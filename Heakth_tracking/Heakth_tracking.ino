#include <Wire.h> 
#include "MAX30105.h"
#include "heartRate.h"
//--- initialization for the heart rate sensor 
MAX30105 particleSensor; 
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg;
//---------------------------------------------------------------MPU6050 initilization
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SSD1306.h>
#include "Classifier.h"
#include "Pipeline.h"
Adafruit_MPU6050 mpu;
int predictionCount=0,stepCount=0;
//-------------------------------------------------------------------OLED initialization 7
Adafruit_SSD1306 display(128, 32, &Wire);
//---------------------------------------------------------------------------------------
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int body_temperature; 
//-----------------------------------------------------------------------------------------
int motor_pin = 25; // for the coin vibrator 
// -----------------------------------------------------------Initialize Bluetoothb communication 
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
BLEServer* pServer = NULL;
BLECharacteristic* stepCharacteristic = NULL;
BLECharacteristic* heartCharacteristic = NULL;
BLECharacteristic* tempCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUIDstep "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define CHARACTERISTIC_UUIDheart "c4833904-2076-4b3f-8351-92c5c980e6a7"
#define CHARACTERISTIC_UUIDtemp "5a24c5c0-41a6-4f66-bfa4-38c050480d92"
// Bluetooth callback setup function 
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {deviceConnected = true;};
    void onDisconnect(BLEServer* pServer) {deviceConnected = false;}
};

void setup() {
  Serial.begin(115200);
  pinMode(motor_pin, OUTPUT);
//initilizing the heart rate sensor -----------------------------
  //You can use the defualt speed where possible;
  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)){
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED 
  //---------------------------------------------------------------------MPU initialization for step count 
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {delay(10);}
  }
  Serial.println("MPU6050 Found!");
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true);	// Keep it latched.  Will turn off when reinitialized.
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);
  //-------------------------------------------------------------------------OLED initilization to display recorded values 
  if(!display.begin(SSD1306_SWITCHCAPVCC,0X3C)){
        Serial.println(F("could not allocate SSD1306")); 
        for(;;); // dont proceed, keep lopping 
         }
  delay(2000); // delay for the oled to have enough time and initialize 
  display.clearDisplay(); // clear the display
  display.setTextColor(WHITE); // setting the colour to white 
  display.display();
  // -----------------------------------------------------------------------------mlx90614
    if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
  //------------------------------------------------------------------------setup for bluetooth
Bluetooth_setup(); 
}

void loop() {
  capture_heart_rate(); 
  delay(3000);
  calculate_steps();
  delay(3000);
  get_body_temp();
  delay(3000);
  display_data();
  delay(3000);
  if (body_temperature> 40 || beatAvg > 190) {
    // Activate the coin vibrator
    digitalWrite(motor_pin, HIGH);
  } else {
    // Deactivate the coin vibrator
    digitalWrite(motor_pin, LOW);
  }
  bluetooth_data_publish(); 
  delay(3000);
}

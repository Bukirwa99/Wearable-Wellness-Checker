#include <Arduino.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP085.h>
#include <DFRobot_QMC5883.h>
#include <Adafruit_MPU6050.h>
#include <MAX30105.h>
#include <heartRate.h>
//#include <DFRobot_MAX30102.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MLX90614.h>
#include "Pipeline.h"
#include "Classifier.h"
#define SDA_2 33
#define SCL_2 32
#define I2C_ADDRESS    0x57
#define OLED_ADDR 0x3C // OLED display address (check with your specific display)
MAX30105 particleSensor;
Adafruit_BMP085 bmp;
Adafruit_MPU6050 mpu;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//////////////////////PULSE OXIMETER VARIABLES/////////////////////////////////
const byte RATE_SIZE = 8; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg;
/////////////////////////PUSLE OXIMITER END///////////////////////////////////
void scanI2c(int i2c);
void stepDetection();
void updateData();
void measureHeartRate();

// Constants for step detection
const float stepThreshold = 5.0;  // Adjust this value to set the threshold for step detection
const unsigned int stepTimeout = 1000;  // Adjust this value to set the timeout between steps in milliseconds
int stepCount=0;
int numberOfPredictions=0;
int idlingCount=0;
bool activeStatus=false;
bool fingerDetected=false;
// Variables for double peak detection
float prevPitch = 0.0;
float prevRoll = 0.0;
unsigned long prevTime = 0;
bool peakDetected = false;
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
  Serial.begin(115200); // Initialize the serial monitor
  Wire.begin();
  Wire1.begin(SDA_2,SCL_2);
  scanI2c(0);
  scanI2c(1);
    // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1);
  }
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
  if (!particleSensor.begin(Wire1, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 was not found. Please check wiring/power. ");
    while (1);
  }
    if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure.");
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0x0A); //Turn off Green LED
  // mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  // mpu.setGyroRange(MPU6050_RANGE_2000_DEG); 
  // mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  // Clear the display buffer
  display.clearDisplay();

  // Set text color to white
  display.setTextColor(WHITE);

  // Set text size
  display.setTextSize(1,1);
  // Set cursor position
  display.setCursor(5, 0);

  // Set white background color
  display.fillScreen(WHITE);

  // Update the display with the initial temperature, roll, and pitch values
  updateData();

  // Display the data on the OLED
  display.display();
  // Serial2.begin(115200, SERIAL_8N1, 27, 26); // Initialize Serial2 with baud rate and pins
  // Serial1.begin(9600, SERIAL_8N1, 15, 2); // Initialize Serial2 with baud rate and pins
  // delay(1000); // Wait for the SIM800L module to initialize
  Bluetooth_setup();
}

void sendATCommand(const char* command) {
  Serial2.println(command); // Send the AT command to SIM800L via Serial2
}
void readATCommand() {
  Serial.println(Serial2.readString()); // Send the AT command to SIM800L via Serial2
}

void loop() {
  updateData();
   display.display();
  // // while(!Serial.available());
  // // Serial2.println(Serial.readString());
  // // while(!Serial2.available());
  // // Serial.println(Serial2.readString());
  // if(Serial1.available())
  // {
  //   Serial.println(Serial1.readString());
  // }
  //   Serial.print("Temperature = ");
  //   Serial.print(bmp.readTemperature());
  //   Serial.println(" *C");
    
  //   Serial.print("Pressure = ");
  //   Serial.print(bmp.readPressure());
  //   Serial.println(" Pa");
    
  //   // Calculate altitude assuming 'standard' barometric
  //   // pressure of 1013.25 millibar = 101325 Pascal
  //   Serial.print("Altitude = ");
  //   Serial.print(bmp.readAltitude());
  //   Serial.println(" meters");

  //   Serial.print("Pressure at sealevel (calculated) = ");
  //   Serial.print(bmp.readSealevelPressure());
  //   Serial.println(" Pa");

  // // you can get a more precise measurement of altitude
  // // if you know the current sea level pressure which will
  // // vary with weather and such. If it is 1015 millibars
  // // that is equal to 101500 Pascals.
  //   Serial.print("Real altitude = ");
  //   Serial.print(bmp.readAltitude(101500));
  //   Serial.println(" meters");
    
  //   Serial.println();
  //   delay(500);
  stepDetection();
  measureHeartRate();
   bluetooth_data_publish();
}
void measureHeartRate()
{
  long irValue = particleSensor.getIR();
  if(irValue<50000)
  {
    //Serial.println(F("No finger"));
    fingerDetected=false;
    beatAvg=NULL;
  }
  else
  {
    //Serial.println("finger detected");
    fingerDetected=true;
    if(checkForBeat(irValue)==true)
    {
      Serial.println("heartbeat detected");
      long delta = millis() - lastBeat; //take a time stamp of the detection.
      lastBeat=millis();
      beatsPerMinute=60/(delta/1000.000);
      Serial.println(beatAvg);
      if (beatsPerMinute < 255 && beatsPerMinute > 20)
      {
        rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
        rateSpot %= RATE_SIZE; //Wrap variable
        //Take average of readings
        beatAvg = 0;
        for (byte x = 0 ; x < RATE_SIZE ; x++)
          beatAvg += rates[x];
        beatAvg /= RATE_SIZE;
      }
    }
  }
}
void stepDetection()
{
  sensors_event_t a, g, temp;
  float ax,ay,az,gx,gy,gz,roll,pitch;
  String PredictedGuesture="";
  mpu.getEvent(&a, &g, &temp);
  float features[]={a.acceleration.x,a.acceleration.y,a.acceleration.z,g.gyro.x,g.gyro.y,g.gyro.z};
  if(!pipeline.transform(features))
  {
    return;
  }
  // perform classification
  PredictedGuesture=forest.predictLabel(pipeline.X);
  if(PredictedGuesture.equals("idling"))
  {
    idlingCount+=1;
    numberOfPredictions=0;
    if(idlingCount>50)
    {
      activeStatus=false;
    }
  }
  if(PredictedGuesture.startsWith("walk"))
  {
    numberOfPredictions+=1;
    if(numberOfPredictions>2)
    {
      stepCount++;
      numberOfPredictions=0;
      idlingCount=0;
    }
    if(stepCount>15)
    {
      activeStatus=true;
    }
    Serial.println(stepCount);
  }
  Serial.print("Predicted gesture: ");
  Serial.print(forest.predictLabel(pipeline.X));
  Serial.print(" (DSP: ");
  Serial.print(pipeline.latencyInMicros());
  Serial.print(" micros, Classifier: ");
  Serial.print(forest.latencyInMicros());
  Serial.println(" micros)");
}
void scanI2c(int i2c) {
  if(i2c==0)
  {
    Wire.begin();
    byte error, address;
    int nDevices = 0;
    Serial.println("Scanning for I2C devices on i2c 0 ...");
    for(address = 0x01; address < 0x7f; address++){
      Wire.beginTransmission(address);
      error = Wire.endTransmission();
      if (error == 0){
        Serial.printf("I2C device found at address 0x%02X\n", address);
        nDevices++;
      } else if(error != 2){
        Serial.printf("Error %d at address 0x%02X\n", error, address);
      }
    }
    if (nDevices == 0){
      Serial.println("No I2C devices found");
    }
  }
  else if(i2c==1)
  {
    Wire1.begin(  SDA_2,SCL_2);
    byte error, address;
    int nDevices = 0;
    Serial.println("Scanning for I2C devices on i2c 1...");
    for(address = 0x01; address < 0x7f; address++){
      Wire1.beginTransmission(address);
      error = Wire1.endTransmission();
      if (error == 0){
        Serial.printf("I2C device found at address 0x%02X\n", address);
        nDevices++;
      } else if(error != 2){
        Serial.printf("Error %d at address 0x%02X\n", error, address);
      }
    }
    if (nDevices == 0){
      Serial.println("No I2C devices found");
    }    
  }
  else;

}
void updateData() {
  // Read the roll and pitch values from MPU6050 sensor

  // Clear the display buffer
  display.clearDisplay();

  // Set white background color
  display.fillScreen(WHITE);

  // Set cursor position
  display.setCursor(0, 0);

  // Print the temperature on the display
  display.setTextColor(BLACK); // Set text color to black for contrast against white background
  //display.setFont(&ArialMT_Plain_10); // Set the bold font (adjust the font name as needed)

  display.print("Body temp:");
  display.print(mlx.readObjectTempC());
  display.println("deg");

  //display.print("Ambient temp:");
  ////display.print(mlx.readAmbientTempC());
  //display.println("deg");

  // display.print("HR: ");
  // display.print(beatAvg);
  // display.println(" bpm");

  display.print("Steps: ");
  display.println(stepCount);
  //display.setCursor(5,40);
  display.print("status:");
  if(activeStatus)
  {
    display.println("actvity detected");
  }
   
  else
    display.println("idling now");
  if(fingerDetected)
  {
    display.setCursor(20,40);
    display.println("Measuring HR");
    display.setCursor(35,50);
    display.print(beatAvg);
    display.print(" bpm");
  }
  else;
    //display.clearDisplay();
}
void display_data(){
  display.clearDisplay();
  display.setTextSize(0.5);
  display.setCursor(0, 0);
  display.print("stepCount: "); 
  display.setTextSize(1);
  display.setCursor(80,0);
  display.print(stepCount);
  delay(3000);
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Average_BPM: "); 
  display.setTextSize(1);
  display.setCursor(80,0);
  display.print(beatAvg);
  delay(3000);
  
  display.clearDisplay();
  display.setTextSize(0.5);
  display.setCursor(0, 0);
  display.print("B_temp: "); 
  display.setTextSize(1);
  display.setCursor(80,0);
  display.print(body_temperature);
  display.display();
  delay(3000);
}
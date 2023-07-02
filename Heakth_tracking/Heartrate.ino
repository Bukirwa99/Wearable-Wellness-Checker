void capture_heart_rate(){
  long irValue = particleSensor.getIR(); 
  if(checkForBeat(irValue) == true){
    long delta = millis() - lastBeat;
    lastBeat = millis();
    beatsPerMinute = 60 / (delta / 1000.0);
    if (beatsPerMinute < 255 && beatsPerMinute > 20){
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable
      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }
  if (irValue < 10000){Serial.println("No Finger");}
  else{
    while (beatAvg ==0){
      delay(5000);
      Serial.println("Waiting for the Heart rate Sensor to start"); }
      Serial.print("Avg_Beats_per_minute: ");
      Serial.println(beatAvg);
  }
  }

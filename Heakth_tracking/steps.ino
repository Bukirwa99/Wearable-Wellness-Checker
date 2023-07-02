void calculate_steps(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float features[] = {a.acceleration.x, a.acceleration.y, a.acceleration.z,g.gyro.x, g.gyro.y, g.gyro.z};
  if (!pipeline.transform(features))
        return;
  String prediction=forest.predictLabel(pipeline.X);
  if (prediction.equals("walking")){
    predictionCount++;
    if(predictionCount>5){
      predictionCount=0;
      stepCount++;
      Serial.print("Step detected: ");
      Serial.println(stepCount);
      }  
}
}
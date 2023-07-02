void get_body_temp(){
  body_temperature = mlx.readObjectTempC();
  Serial.print("Body_Temperature: ");
  Serial.print(body_temperature);
  Serial.println("*C");
}
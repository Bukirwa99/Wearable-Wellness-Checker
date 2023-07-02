void bluetooth_data_publish(){
      // notify changed value
    if (deviceConnected) {
        char testStr[10];
        dtostrf(stepCount, 1, 2, testStr);
        stepCharacteristic->setValue(testStr);
        stepCharacteristic->notify();

        char testStr1[10];
        dtostrf(beatAvg, 1, 2, testStr1);
        heartCharacteristic->setValue(testStr1);
        heartCharacteristic->notify();

        char testStr2[10];
        dtostrf(body_temperature, 1, 2, testStr2);
        tempCharacteristic->setValue(testStr2);
        tempCharacteristic->notify();
        delay(3); // bluetooth stack will go into congestion, if too many packets are sent, in 6 hours test i was able to go as low as 3ms
    }
    // disconnecting
    if (!deviceConnected && oldDeviceConnected) {
        delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) {
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
    }
    
}
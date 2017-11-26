float getTemp() {
  // Read temperature as Fahrenheit (isFahrenheit = true), takes 250milliseconds
  delay(250);
  return dht.readTemperature(true);
}

float getHumidity() {
  // Reading humidity, 250 milliseconds
  delay(250);
  return dht.readHumidity();
}

void checkDHT(float a, float b) {
  if(isnan(a) || isnan(b)) {
    Serial.println("Failed to read from DHT sensor!");
  }
}

void printLCD(String message, int row, int column) {
  lcd.setCursor(column,row);
  lcd.print(message);
}


int getMode() {
  int switchPotValue = map(analogRead(switchPot),0,1023,0,6);
  if(switchPotValue <= 3) {
    return 1; 
  } else {
    return 2;
  } 
}

String modeName(int mode) {
  if(mode == 1) {
    return "1 - Germination";
  } else if (mode == 2) {
    return "2 - Kiln       ";
  }
}

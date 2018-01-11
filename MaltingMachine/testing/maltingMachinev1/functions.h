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

void lcdPrint(int mode) {
  if(mode == 1) {
   // ROW 1:  show temp
    lcd.setCursor(13,0);
    lcd.print(f);
    
    // ROW 2:  show humidity
    lcd.setCursor(10,1);
    lcd.print(h);
  
    // ROW 3: show Mode
    lcd.setCursor(5,2);
    lcd.print(modeName(getMode()));
   
    // ROW 4:Show time remaining for mode 1
    lcd.setCursor(0,3);
    lcd.print("Time Remaining: ");
    lcd.setCursor(16,3);
    lcd.print(modeOneTimer-millis()/1000);
    if(modeOneTimer-millis()/1000 == 0) {  // reset timer
      modeOneTimer += modeOneTimer;
    }
  } else if (mode == 2) {
    // ROW 1:  show temp
    lcd.setCursor(13,0);
    lcd.print(f);
    
    // ROW 2:  show humidity
    lcd.setCursor(10,1);
    lcd.print(h);
  
    // ROW 3: show Mode
    lcd.setCursor(5,2);
    lcd.print(modeName(getMode()));
   
    // ROW 4:Show time remaining for mode 1
    lcd.setCursor(0,3);
    lcd.print("Goal Temp:          ");
    lcd.setCursor(10,3);
    lcd.print(goalTemp);
  } 
}

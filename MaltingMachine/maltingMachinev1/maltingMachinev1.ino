#include "header.h"
#include "functions.h"

void setup() { 
  // setup LEDs to represent motor, heater & mister
  pinMode(motorPin,OUTPUT);
  pinMode(heaterPin,OUTPUT);
  pinMode(misterPin,OUTPUT);
  
  // LCD Setup
  lcd.begin(20,4);
  lcd.print("Temperature:       ");
  lcd.setCursor(0,1);
  lcd.print("Humidity:          ");
  lcd.setCursor(0,2);
  lcd.print("Mode               ");
  lcd.setCursor(0,3);
  lcd.print("Time Remaining:    ");
  
  //rotary endcoder stuff
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
  pinMode (buttonPin, INPUT);
  digitalWrite(outputA, HIGH);
  digitalWrite(outputB, HIGH);
  digitalWrite(buttonPin, LOW);
  
  Serial.begin (9600);
  
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);   
  lastButtonState = digitalRead(buttonPin);
  
  // startup DHT
  dht.begin();
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

void loop() { 


  goalTemp = map(analogRead(potPin),0,1023,115,165);
 




  // ******************  DHT  *********************** //

  if(millis()/1000 % 5 == 0) { // check every 5 seconds
   h = getHumidity();
   f = getTemp();
  checkDHT(h,f);
  }



  // ******************  OUTPUT  ********************* //
 
  if(getMode() == 1) {
    digitalWrite(misterPin,HIGH);
    digitalWrite(motorPin,HIGH);
    
    digitalWrite(heaterPin,LOW);
  }  else if (getMode() == 2) {
     digitalWrite(heaterPin,HIGH);
     digitalWrite(motorPin,HIGH);
     
     digitalWrite(misterPin,LOW);
  }
    
   
    
  
  
  // *****************  LCD PRINT  ******************* //
 lcdPrint(getMode());
 

  
}

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
  pinMode (buttonPin, INPUT_PULLUP);
  digitalWrite(outputA, HIGH);
  digitalWrite(outputB, HIGH);
  digitalWrite(buttonPin, LOW);

  // Serial Communication
  Serial.begin (9600);
  
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);   
  lastButtonState = digitalRead(buttonPin);
  
  // startup DHT
  dht.begin();
}



void loop() { 
  
  // ****************  Rotary Encoder  ******************** //
  
  //  buttonState = digitalRead(buttonPin);  // reads the "current" state of the buttonPin
  aState = digitalRead(outputA); // Reads the "current" state of the outputA
 
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  if (aState != aLastState)
  {     
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(outputB) != aState) { 
      counter ++;
      goalTemp += 5;
      } else {  // otherwise its rotating counterclockwise
        counter --;
        goalTemp -= 5;
      }
          Serial.print("(Position, Button State): (");
          Serial.print(counter);
          Serial.print(",");
          Serial.print(buttonState);
          Serial.println(")");
    } 
  
  aLastState = aState; // Updates the previous state of the outputA with the current state
  lastButtonState = buttonState; // Updates the previous state of the buttonPin with the current state
  lcd.setCursor(0,0);
  lcd.print(counter);

  
//  //Serial.println(digitalRead(22));
//  lcd.setCursor(0,0);
//  lcd.print(digitalRead(22));

  // set goal temp to change in mode 2
//  goalTemp = map(analogRead(potPin),0,1023,115,165);
 




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

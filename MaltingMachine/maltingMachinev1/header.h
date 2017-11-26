
/*    
 *     Matthew Green
 *     November 2017
 */

 // 4 x 20 LCD
 #include <LiquidCrystal.h> 
 LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

 // temp/humidity sensor. See: https://learn.adafruit.com/dht?view=all
 #include "DHT.h" 
 #define DHTPIN 24
 #define DHTTYPE DHT11 
 DHT dht(DHTPIN, DHTTYPE);
 float h = 0;
 float f = 0;

 // Rotary encoder.  See: http://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
 #define outputA 2
 #define outputB 3
 #define buttonPin 22
 int counter = 0; 
 int aState;
 int aLastState; 
 int lastButtonState; 
 int buttonState;

 // output
 int motorPin = 6;
 int heaterPin = 5;
 int misterPin = 4;

 // Mode timer
 int modeOneTimer = 20;


 // Goal Temp
 int goalTemp;

 // potentiometer for goal temp
 #define potPin 1


 // Pot as switch
 #define switchPot 2
 int switchPotValue;




   // ****************  Rotary Encoder  ******************** //
//  
//  //  buttonState = digitalRead(buttonPin);  // reads the "current" state of the buttonPin
//    aState = digitalRead(outputA); // Reads the "current" state of the outputA
//  //  
//   // If the previous and the current state of the outputA are different, that means a Pulse has occured
//    if (aState != aLastState){     
//     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
//     if (digitalRead(outputB) != aState) { 
//     counter ++;
//     } else {
//      counter --;
//    }
////    Serial.print("(Position, Button State): (");
////    Serial.print(counter);
////    Serial.print(",");
////   Serial.print(buttonState);
////    Serial.println(")");
//    } 
//   
//   aLastState = aState; // Updates the previous state of the outputA with the current state
//   lastButtonState = buttonState; // Updates the previous state of the buttonPin with the current state
//   lcd.setCursor(6,2);
//   lcd.print(counter);




  // ******************  Outputs  *********************** //
  // Will be the motor, heater and mister outputs


 


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
 int modeOneTimer = 300;


 // Goal Temp
 int goalTemp;

 // potentiometer for goal temp
 #define potPin 1


 // Pot as switch
 #define switchPot 2
 int switchPotValue;









  // ******************  Outputs  *********************** //
  // Will be the motor, heater and mister outputs


 

/*     Based on: http://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
 *     Setup to work on Arduino MEGA
 */
 #include <LiquidCrystal.h>
 #define outputA 2
 #define outputB 3
 #define buttonPin 22
 #define humidityPin 24

 int counter = 0; 
 int aState;
 int aLastState; 
 int lastButtonState; 
 int buttonState;

 int motorPin = 6;
 int heaterPin = 5;
 int misterPin = 4;

 int modeOneTimer = 300;

 LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

 void setup() { 
 // setup LEDs to represent motor, heater & mister
 pinMode(motorPin,OUTPUT);
 pinMode(heaterPin,OUTPUT);
 pinMode(misterPin,OUTPUT);

  // LCD Screen Setup
  lcd.begin(20,4);
  lcd.print("Temperature: xxx d");
  lcd.setCursor(0,1);
  lcd.print("Humidity: xxx u");
  lcd.setCursor(0,2);
  lcd.print("Mode: ");
  lcd.setCursor(0,3);
  lcd.print("Time Remaining:    s");

  //notary endcoder stuff
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
  lcd.setCursor(10,1);
  if(lastButtonState == 1) {
    lcd.print("Pressed");
  } else {
    lcd.print("Not Pressed");
  }
 
 } 

 void loop() { 
  lcd.setCursor(0,3);
  lcd.print("Time Remaining: ");
  lcd.setCursor(16,3);
  lcd.print(modeOneTimer-millis()/1000);

// Will be the motor, heater and mister outputs
//  digitalWrite(motorPin,HIGH);
//  digitalWrite(heaterPin,HIGH);
//  digitalWrite(misterPin,HIGH);
  
   buttonState = digitalRead(buttonPin);  // reads the "current" state of the buttonPin
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
 
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("(Position, Button State): (");
     Serial.print(counter);
     Serial.print(",");
     Serial.print(buttonState);
     Serial.println(")");
   } 
//   if(buttonState == HIGH) {
//      Serial.println("Button is being pressed");
//   }
   aLastState = aState; // Updates the previous state of the outputA with the current state
   lastButtonState = buttonState; // Updates the previous state of the buttonPin with the current state
   lcd.setCursor(6,2);
   lcd.print(counter);
 }

/*     Based on: http://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
 *     Setup to work on Arduino UNO
 */
 #include <LiquidCrystal.h>
 #define outputA 2
 #define outputB 3
 #define buttonPin 5

 int counter = 0; 
 int aState;
 int aLastState; 
 int lastButtonState; 
 int buttonState;

 LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

 void setup() { 
  lcd.begin(16,4);
  lcd.print("Hello, Worlds!");
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
 } 

 void loop() { 
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
     Serial.print("Counter: ");
     Serial.println(counter);
   } 
//   if(buttonState == HIGH) {
//      Serial.println("Button is being pressed");
//   }
   aLastState = aState; // Updates the previous state of the outputA with the current state
   lastButtonState = buttonState; // Updates the previous state of the buttonPin with the current state
   lcd.setCursor(0,1);
   lcd.print(counter);
 }

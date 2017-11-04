/*     Based on: http://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
 *     Setup to work on Arduino UNO
 */
 
 #define outputA 8
 #define outputB 9
 #define buttonPin 5

 int counter = 0; 
 int aState;
 int aLastState; 
 int lastButtonState; 
 int buttonState;

 void setup() { 
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
 }

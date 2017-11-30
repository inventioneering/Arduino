
 // Rotary encoder.  See: http://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
 #define outputA 2
 #define outputB 3
 #define buttonPin 22
 int counter = 0; 
 int aState;
 int aLastState; 
 int lastButtonState; 
 int buttonState;

 int goalTemp = 120;

void setup() { 
  //rotary endcoder stuff
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
 
  digitalWrite(outputA, HIGH);
  digitalWrite(outputB, HIGH);


  // Serial Communication
  Serial.begin (9600);
  
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);   
  lastButtonState = digitalRead(buttonPin);
 
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
          Serial.print("Counter: ");
          Serial.println(counter);
        
    } 
  
  aLastState = aState; // Updates the previous state of the outputA with the current state
  lastButtonState = buttonState; // Updates the previous state of the buttonPin with the current state
  //  delay(50);
  
}

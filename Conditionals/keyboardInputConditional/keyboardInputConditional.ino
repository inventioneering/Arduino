
int buttonPin = 2;
int led = 13;
int buttonState = 0;
int ledOn = 0;

void setup()
{
  pinMode(buttonPin, INPUT); 
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 
  // check to make sure the Arduino has a Serial option. SOme do not. 
  if (Serial.available())
  {
    // get the value someone types into the serial monitor and turn it into an Integer (whole number)
    buttonState = Serial.parseInt();
  }
 
  // this case is when you've pressed the button but the led is off.
  if (buttonState == 1 /* button pressed*/ && ledOn == 0 /*led off*/) {
   
   digitalWrite(led, HIGH); 
   // keep track of if the led is on or not.
   ledOn = 1;

   // set the value of buttonState back to 0 so that the next "if" statement below doesn't run
   buttonState = 0;
   
   // optional
   Serial.println("Light on");
  }
  
  if (buttonState == 1 && ledOn == 1) {
   digitalWrite(led, LOW); 
   
   // keep track of the button being off
   ledOn = 0;
  
   // make sure the button gets reset.
   buttonState = 0;
   
   // optional
    Serial.println("light off");
  }
  
  // this runs when you press any other button besides the 1.
  else {
    
   // this is optional.  I just used it for debugging.
   Serial.println("Waiting for button press");

  }
  
}
  

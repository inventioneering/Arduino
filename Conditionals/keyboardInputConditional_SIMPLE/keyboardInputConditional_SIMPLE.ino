
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
  
  // turn the LED on if the user presses the number 1 on the keyboard
 if (buttonState == 1) {
 digitalWrite(led, HIGH);  
 }
 
 // if the user presses anything else, turn the LED off
 else {
  digitalWrite(led, LOW); 
 }
  
}
  

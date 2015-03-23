
// setup your circuit to match.
int buttonPin = 2;
int led = 13;

// create variable to hold if the "state" of the button, is it being pressed or not.
int buttonState = 0;

void setup()
{
  pinMode(buttonPin, INPUT); 
  pinMode(led, OUTPUT);
  
  // optional -- used with serial monitor to test
  Serial.begin(9600);
}

void loop()
{
 
  // get a reading off the input pin
  buttonState = digitalRead(buttonPin);
  
  // if you are pressing the button
 if (buttonState == 1) {
  Serial.println("ON");
 digitalWrite(led, HIGH);  
 }
 
 // if the user presses anything else, turn the LED off
 else {
  digitalWrite(led, LOW); 
  Serial.println("OFF");
 }
  
}
  

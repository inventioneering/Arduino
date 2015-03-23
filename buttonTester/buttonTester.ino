
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
 
  buttonState = digitalRead(buttonPin);
  
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
  

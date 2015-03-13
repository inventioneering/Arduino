int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}


void loop() {
  blinkLED(led, 300);
  blinkLED(led, 300);
  blinkLED(led, 300);
  blinkLED(led, 300);
  blinkLED(led, 300);
  blinkLED(led, 300);
  blinkLED(led, 300);
  blinkLED(led, 300);
  blinkLED(led, 300);
  blinkLED(led, 300);
  
  delay(3000);
}


void blinkLED(int ledPin, int delayTime) {
  
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);               // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);               // wait for a second
  
}

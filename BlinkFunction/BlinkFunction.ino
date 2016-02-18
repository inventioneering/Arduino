// I just forked this repo - matt-demo

/*
  This is my edit to the basic blink sketch to show how we might use functions
  to replace the main command to blink an LED.  
  
  The following code is structured differently but wil behave identically to
  the Example: Examples/Basics/Blink.ino
  
  Matt Green
  Spring 2015
 */
 
// I connected an LED to pin 13.  On most boards, there is an onboard LED attached
// to pin 13.
int led = 13;


void setup() {                
  // let the arduino know that you plan to send voltage out to pin 13
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
 
// call the function blinkLED one time.  Send it the two pieces of information it
// needs to run first the pinNumber that has the LED attached and second the
// time (in milliseconds) that it should delay in between turning the LED on
// and off.
blinkLED(led, 1000);
  
}

// This is a new function that I made to control the blinking LED
// you should read more about how functions work in 
// Arduino here: http://arduino.cc/en/Reference/FunctionDeclaration

void blinkLED(int ledPin, int delayTime) {
  
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);               // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);               // wait for a second
  
}

// I'm doing a thing on gitHub that is different from that other thing

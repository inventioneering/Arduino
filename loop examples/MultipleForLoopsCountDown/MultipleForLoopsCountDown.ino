/*
 I'm altering the Blink.ino file so that I can show how to use both functions (subroutines) and for loops.
 
 In this example I'm going to create a loop for each of the behaviors below.
 
 blink-blink-blink-blink   
 pause
 blink-blink-blink
 pause
 blink-blink
 pause
 blink
 
 See below for more detail
 
 Matt Green, Spring 2015
 */

int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}


void loop() {
  
  // this loop will run four times. Convince yourself that this is true.
  for(int i = 0; i < 4; i++) {
   blinkLED();
  }
  
  // pause between blinks
  delay(1000);
  
  // this loop will run three times. Convince yourself that this is true.
  for(int i = 0; i < 3; i++) {
   blinkLED();
  }
   
  // pause between blinks
  delay(1000);
  
   // this loop will run two times. Convince yourself that this is true.
  for(int i = 0; i < 2; i++) {
   blinkLED();
  }
   
  // pause between blinks
  delay(1000);
  
  // no loop needed this time
  blinkLED();
}

void blinkLED() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second 
}

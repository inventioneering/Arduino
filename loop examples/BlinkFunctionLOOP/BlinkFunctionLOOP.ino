/*
 This is built upon the sketch:
 https://github.com/inventioneering/Arduino/tree/master/BlinkFunction
  
 It adds the second layer: loops.
 
 In this file I focus on adding for() loops so we can make the LED blink
 a set number of times before restarting.
 
 The following sketch will blink the onboard LED 10 times, wait 3 seconds and then
 start again.
 
 It is powerful to compare the code in this file to the code required to do the 
 same thing without loops: http://bit.ly/1wFdq80
 
 Or this one that has neither loops nor functions: http://bit.ly/1BeVSek
 
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
 
  /* I'm using a for loop becuase they are great for counting.  You can read
     more about them here: http://arduino.cc/en/Reference/For
   
     notice that I again use the blinkLED(int, int) function which allows
     me to condense the code necessary to make the LED blink 10 times.
  
  */
  for(int counterVariable = 0; counterVariable < 10; counterVariable++) {
    blinkLED(led, 300);
  }
  
  // wait three seconds before starting over and blinking 10 times again
  delay(3000);


  
}

void blinkLED(int ledPin, int delayTime) {
  
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);               // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);               // wait for a second
  
}

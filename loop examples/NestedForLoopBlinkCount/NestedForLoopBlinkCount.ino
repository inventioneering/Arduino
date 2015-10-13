/*
 I'm altering the Blink.ino file so that I can show how to use both functions (subroutines) and for loops.
 
 In this example I've created a nested for loop which is a for loop inside another for loop.  In this instance
 the nested for loop is allowing me to count down my blinking lights in the pattern:
 
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
int delayTime = 90;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}


void loop() {
  
  /* 
     this outter loop controls both how many times we want the inner loop to run and the way in which it runs
     in this case the outter loop counts down from 4 to 1.  You can see the countdown method in that j = 4 at the beggingin
     and then each time I run through the outter loop it decreases by 1 and will eventually stop when j = 0;
 */
 for(int j = 4; j > 0; j--) {
   
   /*
     In this inner loop we grab the counter variable we setup in the outter loop, "j" and use it as part of our
     looping rule on this loop.  The purpose of this inner for loop is to simply repeat the one line of code, blinkLED(); as
     many times as we want it to.  
     
     The tricky part is that the number of times we want this loop to run blinkLED(); keeps changing.
     
     At first we want four blinks, then three, then two, then one.
     
     Think about program flow, the first time we run through this outter loop j = 4 and i = 0
     in this case the inner loop below will run four times becauase it will stop when i < 4... because j = 4 this time...
     
     count blinks starting at i = 0
     
     i = 0    blinkLED();
     i = 1    blinkLED();
     i = 2    blinkLED();
     i = 3    blinkLED();
     i = 4    we won't run this inner loop again because i = 4 and j = 4 and 4 isn't bigger than 4...
     
     
     */
  for(int i = 0; i < j; i++) {
   blinkLED();
  } 
  // run this each time we've completed the inner loop above.  This needs be run to show the user that we are 
  // pausing after we blink so we can see it actually counting down and not just a continuous stream of blinks.
  delay(1000);
 }
}

void blinkLED() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delayTime);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(delayTime);               // wait for a second 
}

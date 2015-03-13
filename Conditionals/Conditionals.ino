/*

This is my sketch showing how to make a single button turn an LED on and off.

Please connect your button(s) as indicated here: http://ardx.org/src/circ/CIRC07-sheet-OOML.pdf

NOTE I only have one button and it is attached to pin 2.  You will notice that it says to attach the
LED to pin 13 then pin 9.  Just leave your's in pin 13 for this example.
*/


// make a variable with a name I will remember that holds the pin number of my button
int buttonPin = 2;

// do the same for my LED.  Remember: variable names are for your convenience.  Make them 
// something you will remember.
int led = 13;

// I'm making a variable that will hold onto the most recent "state" of the button, 
// that is button is pressed or not pressed
int buttonState = 0;

void setup() {
  // setup your buttonPin and led
  pinMode(buttonPin, INPUT); 
  pinMode(led, OUTPUT);

}

void loop() {
  
  // take the reading from the button and assign it to the buttonState variable
  // it will be either a 1 or a 0
  buttonState = digitalRead(buttonPin);

  // if its a 1, turn the LED on
  if(buttonState == HIGH) {
    digitalWrite(led, HIGH);
    delay(50);
  } 
  
  // if anything else happens, turn the LED off.  In our case "anything else" will only 
  // be a 0... but in other uses of if/else statements you need to be very careful to 
  // plan for all the possible outcomes.
  else {
    digitalWrite(led, LOW);
    delay(50);
  }
  
}

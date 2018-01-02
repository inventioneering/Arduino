#include "dht_functions.h"
#include "lcd_functions.h"
#include "printLCD_functions.h"
#include "Timer_Class.h"



#define buttonPin 21
#define encoder0PinA 2
#define encoder0PinB 3
#define buttonPin 21
volatile int encoder0Pos = 0;
volatile int buttonState = 0;
volatile int oldButtonState = 0;

int mode = 1;
Timer timer1(10);

void setup()
{
  // rotary encoder with interrupts
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pull-up resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pull-up resistor
  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2

  // make buttonPin an interrupt to improve responsiveness
  pinMode(buttonPin, INPUT);
  attachInterrupt(5, buttonPress, CHANGE);

  
  lcd.begin(20,4); // 20 columns, 4 rows
  setupLCD();  // lcd_functions.h
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop()
{
  Serial.println(encoder0Pos);
  //Serial.println(timer1.timerRunningQ());
  if(timer1.timerRunningQ() == false) {
    timer1.resetTimer(5);
  }
  changeMode();  // toggle between modes 1 and 2
  
  //rotary.Update(); // Rotary_Class.h
 checkDHT(); // dht_functions.h

 if(mode == 1) {
   // start 5 min timer
   // when that ends, start 55 min timer
   // turn on motor for 5 mins every 55 mins
   // turn on mister for 5 mins every 55 mins
   }

 if(mode == 2) {
   // turn off mister
   // turn on motor
   // turn on heater if temp is below goalTemp
   // turn off header if temp is above goalTemp
  }
  
  lcdPrint(mode,h,t,encoder0Pos); // print whole mode
  
 //fillLCD();
  //debugDHTandRotary(); 
  
}


/*
 * 
 *   FUNCTIONS
 * 
 */

 void buttonPress() {
 buttonState = digitalRead(buttonPin);
 if(oldButtonState != buttonState) {
  changeMode2();
 }
  oldButtonState = buttonState;
 }
 
void debugDHTandRotary() {
  Serial.print("(humidity, temperature, counter): ");
  Serial.print("(");
  Serial.print(h);
  Serial.print(", ");
  Serial.print(t);
  Serial.print(", ");
 // Serial.print(rotary.getCounter());
  Serial.println(")");
}


void fillLCD() {
  lcd.home();
  lcd.print("ThisIsTheSongThatNeverEndsYesItGoesOnAndOnMyFriendOnceHeStartedSingingItNotKnowingWhatItWasAndHeJustKeptOn");

}

void changeMode2() {
  if(mode == 1) {
    mode = 2;
  } else if (mode == 2) {
    mode = 1;
  }
}

void changeMode() {
  if(digitalRead(buttonPin) == LOW) 
  {
    digitalWrite(13,HIGH);
    if(mode == 1) {
      mode = 2;
    }
    else if(mode == 2) {
      mode = 1;
    }
    Serial.println(mode);
  }
   
  else 
  {
    digitalWrite(13,LOW);
  }
}

 void doEncoder() {
  /* If pinA and pinB are both high or both low, it is spinning
     forward. If they're different, it's going backward.

     For more information on speeding up this process, see
     [Reference/PortManipulation], specifically the PIND register.
  */
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos--;
  } else {
    encoder0Pos++;
  }

  //Serial.println (encoder0Pos, DEC);
}

/* See this expanded function to get a better understanding of the
   meanings of the four possible (pinA, pinB) value pairs:
*/
void doEncoder_Expanded() {
  if (digitalRead(encoder0PinA) == HIGH) {   // found a low-to-high on channel A
    if (digitalRead(encoder0PinB) == LOW) {  // check channel B to see which way
      // encoder is turning
      encoder0Pos = encoder0Pos + 1;         // CCW
    }
    else {
      encoder0Pos = encoder0Pos - 1;         // CW
    }
  }
  else                                        // found a high-to-low on channel A
  {
    if (digitalRead(encoder0PinB) == LOW) {   // check channel B to see which way
      // encoder is turning
      encoder0Pos = encoder0Pos - 1;          // CW
    }
    else {
      encoder0Pos = encoder0Pos + 1;          // CCW
    }

  }
 // Serial.println (encoder0Pos, DEC);          // debug - remember to comment out
  // before final program run
  // you don't want serial slowing down your program if not needed
}

/*  to read the other two transitions - just use another attachInterrupt()
  in the setup and duplicate the doEncoder function into say,
  doEncoderA and doEncoderB.
  You also need to move the other encoder wire over to pin 3 (interrupt 1).
*/








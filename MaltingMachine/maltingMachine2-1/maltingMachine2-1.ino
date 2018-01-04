#include "dht_functions.h"
#include "lcd_functions.h"
#include "printLCD_functions.h"
#include "Timer_Class.h"
#include "header.h"


#define buttonPin 21
#define encoder0PinA 2
#define encoder0PinB 3
#define buttonPin 21

volatile int encoder0Pos = 0;
volatile int buttonState = 0;
volatile int oldButtonState = 0;

float lastChangeTime;
int mode = 1;

Timer timer1(300);

void setup()
{
  // rotary encoder with interrupts
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pull-up resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pull-up resistor
  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2

  pinMode(buttonPin, INPUT);
  attachInterrupt(2, changeMode, FALLING);
  
  lcd.begin(20,4); // 20 columns, 4 rows
  setupLCD();  // lcd_functions.h
  Serial.begin(9600);
  pinMode(13,OUTPUT);

  //outputs
  pinMode(motorPin,OUTPUT);
  pinMode(heaterPin,OUTPUT);
  pinMode(misterPin,OUTPUT);

  lastChangeTime = millis();
}

void loop()
{
  //Serial.println(encoder0Pos);
  Serial.println(millis() - lastChangeTime);
  //Serial.println(timer1.timerRunningQ());
  if(timer1.timerRunningQ() == false) {
    timer1.resetTimer(5);
  }
  //changeMode();  // toggle between modes 1 and 2
  
  //rotary.Update(); // Rotary_Class.h
 checkDHT(); // dht_functions.h

 //changeMode();
 if(millis() - lastChangeTime > 500) {
  lastChangeTime = millis();
 }
 
 if(mode == 1) {
   // 1.  start 5 min timer
   // 2.  Turn on motor
   digitalWrite(motorPin,HIGH);
   // 3.  Turn off mister
   digitalWrite(misterPin,LOW);
   // 4.  Turn off heater
   digitalWrite(heaterPin,LOW);
   
   //after 5 minutes, 
   // 1.  start 55 min timer
   // 2.  turn off motor
  // digitalWrite(motorPin,LOW);
   // 3.  turn off heater
  
   }

 if(mode == 2) {
   // turn off mister
   digitalWrite(misterPin,LOW);
   // turn on motor
   digitalWrite(motorPin,LOW);
   // turn on heater if temp is below goalTemp
   digitalWrite(heaterPin,HIGH);
   // turn off header if temp is above goalTemp
  }


  lcdPrint(mode,h,t,timer1.secondsLeft()); // print whole mode
  
 //fillLCD();
  //debugDHTandRotary(); 
  
}


// FUNCTIONS
void changeMode() {
  if(millis() - lastChangeTime < 400) {
   if(mode == 1) {
    mode = 2;
   } else if (mode == 2) {
    mode = 1;
   }
   lastChangeTime = millis();
  } 
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








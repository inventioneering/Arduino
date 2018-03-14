#include "dht_functions.h"
#include "lcd_functions.h"
#include "printLCD_functions.h"
#include "Timer_Class.h"
#include "header.h"


#define buttonPin 21
#define encoder0PinA 2
#define encoder0PinB 3


volatile int encoder0Pos = 0;
volatile int buttonState = 0;
volatile int oldButtonState = 0;

float lastChangeTime;
int mode = 1;
boolean modeOneOn = false;
boolean timerAOn = true;


Timer timer1(10); // just for testing, set to 301 for production



void setup()
{
  // rotary encoder with interrupts
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pull-up resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pull-up resistor
  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2

  pinMode(buttonPin, INPUT);
  //attachInterrupt(2, changeMode, FALLING);
  attachInterrupt(2, changeMode, FALLING);  // debugging
  
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
  //Serial.println(mode);
  //Serial.println(encoder0Pos);
 // Serial.println(millis() - lastChangeTime);
    //Serial.println(timer1.secondsLeft());
  //Serial.println(timer1.timerRunningQ());
//  if(timer1.timerRunningQ() == false) {
//    timer1.resetTimer(5);
//  }
  
 
 checkDHT(); // dht_functions.h

 // update the button so it can be pressed again
 if(millis() - lastChangeTime > 500) {
  lastChangeTime = millis();
 }

 if(mode == 1) 
 {
   manageTimer();
   lcdPrint(mode,h,t,timer1.secondsLeft()); // print whole mode
 }


 if(mode == 2) 
 {
  // set flag to indicate that we've switched to mode2
   modeOneOn = false;
   // turn off mister
   digitalWrite(misterPin,LOW);
   // turn on motor
   digitalWrite(motorPin,LOW);
   // turn on heater if temp is below goalTemp
   digitalWrite(heaterPin,HIGH);
   // turn off header if temp is above goalTemp
    lcdPrint(mode,h,t,12345); // print whole mode
  }


  
}


// FUNCTIONS


void manageTimer() {
  
  // while the 5 min timer is running
  if(timerAOn && timer1.timerRunningQ()) 
  {
    Serial.println("5 min timer is running");
    // Turn on motor
   digitalWrite(motorPin,HIGH);
   
   // Turn on mister
   digitalWrite(misterPin,HIGH);
   
   // Turn off heater
   digitalWrite(heaterPin,LOW);
  }

  // While the 55 min timer is running
  if(!timerAOn && timer1.timerRunningQ()) 
  {
    Serial.println("55 min timer is running");
     // Turn off motor
   digitalWrite(motorPin,LOW);
   
   // Turn off mister
   digitalWrite(misterPin,LOW);
   
   // Turn off heater
   digitalWrite(heaterPin,LOW);
  }

  
  // Turn on 5 minute timer
  if(!timerAOn && !timer1.timerRunningQ()) 
  {
    Serial.println("reset timer to 5 minutes");
   timerAOn = true;
   timer1.resetTimer(5); // 300 for production
  }

  // turn on 55 minute timer
 if(timerAOn && !timer1.timerRunningQ()) 
 {
  Serial.println("reset timer to 55 minutes");
  timerAOn = false;
  timer1.resetTimer(20); // 55000 for production
 }
 

 
}


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








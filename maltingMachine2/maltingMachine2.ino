#include "Rotary_Class.h"
#include "dht_functions.h"
#include "lcd_functions.h"
#include "printLCD_functions.h"
#include "Timer_Class.h"


#define buttonPin 22
int mode = 1;
RotaryEncoder rotary(2, 3, 22, 10); // a 10ms delay seems to help smooth out the encoder.  Not sure why
Timer timer1(10);

void setup()
{
  lcd.begin(20,4); // 20 columns, 4 rows
  setupLCD();  // lcd_functions.h
  Serial.begin(57600);
  pinMode(13,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop()
{
  Serial.println(timer1.timerRunningQ());
  if(timer1.timerRunningQ() == false) {
    timer1.resetTimer(5);
  }
  changeMode();  // toggle between modes 1 and 2
  
  rotary.Update(); // Rotary_Class.h
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
  lcdPrint(mode,h,t,rotary.getGoalTemp()); // print whole mode

  //fillLCD();
  //debugDHTandRotary(); 
  
}


/*
 * 
 *   FUNCTIONS
 * 
 */
 
void debugDHTandRotary() {
  Serial.print("(humidity, temperature, counter): ");
  Serial.print("(");
  Serial.print(h);
  Serial.print(", ");
  Serial.print(t);
  Serial.print(", ");
  Serial.print(rotary.getCounter());
  Serial.println(")");
}


void fillLCD() {
  lcd.home();
  lcd.print("ThisIsTheSongThatNeverEndsYesItGoesOnAndOnMyFriendOnceHeStartedSingingItNotKnowingWhatItWasAndHeJustKeptOn");

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








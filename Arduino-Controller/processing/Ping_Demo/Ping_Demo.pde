// I found this here: https://www.youtube.com/watch?v=KOirgo410Xw
// I edited the following to make it work with my arduino setup
// on the mac.

import processing.serial.*;
//import cc.arduino.*;
//Arduino arduino;

Serial port;
String distance_sm = "";
String data = "";
PFont font;
int index = 0;

void setup() 
{
  size(400, 400);
  println(Serial.list());
 port = new Serial(this, "/dev/cu.usbmodem1421", 9600);
 port.bufferUntil('.');
 
}

void draw() {
  background(0,0,0);
    fill(255);                 
    text(distance_sm, 70, 175);           

}

void serialEvent (Serial port)
{
  data = port.readStringUntil('.');
  data = data.substring(0, data.length() - 1);
  index = data.indexOf(",");
  distance_sm = data.substring(0, index);
}
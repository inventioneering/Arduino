// I found this here: https://www.youtube.com/watch?v=KOirgo410Xw
// I edited the following to make it work with my arduino setup
// on the mac.

import processing.serial.*;
//import cc.arduino.*;
//Arduino arduino;

Serial port;
String distance = "";
String data = "";
PFont font;
int index = 0;
float dist;

void setup() 
{
  size(400, 400);
  ellipseMode(CENTER);
  println(Serial.list());
 port = new Serial(this, "/dev/cu.usbmodem1421", 57600);
 port.bufferUntil('.');
 //background(0);
 
}

void draw() {
    background(0,0,0);
    fill(255);                 
    text(distance, 70, 175);  
    //noStroke();
    if(dist <= 100)
    {
      ellipse(width/2, height/2, dist, dist);
    }

}

void serialEvent (Serial port)
{
  data = port.readStringUntil('.');
  data = data.substring(0, data.length() - 1);
  index = data.indexOf(",");
  distance = data.substring(0, index);
  dist = float(distance);
}
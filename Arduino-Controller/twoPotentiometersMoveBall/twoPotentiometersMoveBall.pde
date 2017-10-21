int circleSpeed = 10;
int x = 200;
int y = 200;
int a = 0;
int difference = 0;
int c = 0;
int difference2 = 0;
int leftMove = 0;
int upMove = 0;
import processing.serial.*;
import cc.arduino.*;
Arduino arduino;

void setup()
{
  size(400,400); 
  arduino = new Arduino(this, Arduino.list()[1], 57600);
  x = width/2;
  y = height/2;
}

void draw()
{
  background(255);
  fill(255,0,0);
  
  ellipse(x,y,20,20); 
  //println(arduino.analogRead(0)); 
  a = arduino.analogRead(0);  // left and right
  delay(25);
  c = arduino.analogRead(0);  //left and right
  difference = c-a;
  
  a = arduino.analogRead(5);  // up and down
  delay(25);
  c = arduino.analogRead(5);  //up and down
  difference2 = c-a;

  moveBall("horizontal", difference);
  moveBall("vertical", difference2);
  
  
  if(difference == 0 && leftMove == 1)
  {
    x -= circleSpeed;
  }
  
   if(difference == 0 && leftMove == 0)
   {
    x += circleSpeed;
   }
   
   if(difference2 == 0 && upMove == 1)
  {
    y -= circleSpeed;
  }
  
   if(difference2 == 0 && upMove == 0)
   {
    y += circleSpeed;
   }
   
  //println(c);
 }
 
 void moveBall(String direction, int diff)
 {
  if(direction == "horizontal")
  {
    if(diff > 50)
  {
    x += circleSpeed; 
    leftMove = 0;
  }
  
  if(diff < -50)
  {
    x -= circleSpeed;
    leftMove = 1;
  }
 
  }
  
  if(direction == "vertical")
  {
    if(diff > 50)
  {
    y += circleSpeed; 
    upMove = 0;
  }
  
  if(diff < -50)
  {
    y -= circleSpeed;
    upMove = 1;
  }
  }
   
 }
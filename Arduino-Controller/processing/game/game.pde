// This is a simple game made from the components in the SparkFun Guide to Processing
// Painting program.  You can see the original sketch here: http://bit.ly/1OPoIso
// 
// The goal of this challenge was to create a game from the same components as
// another sketch that have been repurposed.  
//
// 
// I was inspired by this.  I used this authors gameOver idea and brought it 
// into this sketch:
// http://www.123mylist.com/2013/12/basic-pong-game-using-processing.html



// this is stuff I'm using to interface with the arduino

// Green = VCC
// Black = Trig 3
// Yellow = Echo 2
// Blue = GND
import processing.serial.*;
Serial port;
String distance = "";
String data = "";
PFont font;
int index = 0;
float dist;
float distanceMap;



// This is where I'm declaring variables I'll use in the game
int x, y = 1;  // keep track of the (x,y) position of the falling ball
int yChange = 2;  // a way to manage the speed of the ball
int boxSpeed = 6; 
int boxX, boxY = 1;  // (x,y) position of the "box"
int boxWidth = 80; 
int boxHeight = 20;
int gameOver = 0;  // keeps track of if the game is still going. 
int score = 0; // keeps track of the player's score


void setup()
{
  background(255);
  rectMode(CENTER);
  ellipseMode(CENTER);
  size(400, 600);
  frameRate(60);  // default is 30.  This makes it smoother on my machine

  x = int(random(0, width));  // make the ball drop from a differnt location each time
  
  port = new Serial(this, "/dev/cu.usbmodem1421", 57600);
  port.bufferUntil('.');
}


void draw()
{
  
  
    
  if(gameOver == 0)  // run this chunk while the game is still going
  {
  background(255);
  
  // print the current score to the screen
  fill(0);
  textSize(20);
  text("Score: "+score, width - 100, 30);
  
  // This creates the solid black band.
  // I created a visual trick here to make it look like there is a 
  // rectangular "hole" in the black band.  In reality there is a 
  // white rectangle on top of a black rectangle.  The black one
  // stretches across the width of the screen and doesn't move.
  // The white one is smaller and moves left and right as the 
  // moves the p
  fill(0);
  rect(width/2, 0.75*height, width, boxHeight);
  
  
  // the map function allows me to take values coming from the pressure sensor and "map" them across the width
  // of the entire screen.  Its the easy way of figuring out how many "slices" I'd need to make to fluidly 
  // move my rectangle around the screen.
  //
  // I've chosen to create a simple map so that as the distance is small, the rectangle is close to the left
  // of the screen and as the distance increases you move it away...
  float distanceMap = map(dist, 0, 40, 0, width);
  
  fill(255);
  noStroke();
  rect(distanceMap, 0.75*height, boxWidth, boxHeight);  // draw rectangle based on distance sensor values
 

  // draw falling circle
  fill(0, 255, 0);
  ellipse(x, y, 30, 30);
  // this moves the circle down.  **Remember** that in Processing as you move down
  // the y-values get bigger and more positive not smaller and more negative.
  // see this for more information: https://processing.org/tutorials/drawing/
  y += yChange;  
  

  // if the circle falls all the way to the bottom...
  if (y >= height)
  {
    y = 0;  // reset y=0 so the next ball starts at the top of the screen
    x = int(random(0, width));  // pick a new random x position for new ball
    score++;  // add one to the score
    
    // this section checeks to see if the score is evenly divisibly by 2... if it is then increase
    // the value of yChange.  yChange is used to set the speed of the falling ball.  Essentially the more
    // you score, the harder the game.  Thank you Devin Perry for the idea.
  if(score % 2 == 0)
    {
     yChange++; 
     background(0,255,0);  // flash the screen green to give the player a head's up the the speed is increasing.
    }
  }
  

  // this checks to see if the ball's height is the same height is between
  // the top of the "hole" and the bottom of it.  If it is then...
  if(y+10 >= int(0.75*height-boxHeight/2) && y <= int(0.75*height+boxHeight/2))
  {
    // if its also either to the left or right of the "hole" then end the game
    // essentially this "nested if statement" first checks to see if the ball
    // is close to the hole and if it makes it through the hole or not.
    
    if(x < distanceMap-boxWidth/2 | x > distanceMap+boxWidth/2)
    {
     gameOver = 1;  // now the next condition can run...
    }
  }
  
  }
  
  else  // this only happens when gameOver doesn't equal 0
  {
    background(0,255,0);
    fill(255);
    textSize(32);
    text("Game Over!",width/2-90,height/2-180);
    text("Score: " + score,width/2-60,height/2);
    text("Press R to Restart",width/2-130,height/2+80);
    
    //delay(2000);
    
    // reset game by holding your hand in front of the distance sensor (very close)
    if(dist <= 2)
    {
      gameOver=0;
      score = 0;
      y = 1;
      x = int(random(0, width));
      boxSpeed = 6;
    }
  }
  
}

// this resets the game.  It works at anytime during the game
void keyPressed()
{
  if(key == 'r' | key == 'R')
  {
    gameOver=0;
    score = 0;
    y = 1;
    x = int(random(0, width));
 }
  
}

// this is used to grab the data coming from the USB, Universal Serial Bus... where "Serial" is a type of electronic connection scheme... and
// use it as data...
void serialEvent (Serial port)
{
  data = port.readStringUntil('.');
  data = data.substring(0, data.length() - 1);
  index = data.indexOf(",");
  distance = data.substring(0, index);
  dist = float(distance);
}
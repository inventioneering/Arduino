int x,y;

void setup()
{
 size(400,400); 
 x = width/2;
 y = height/2;
}

void draw()
{
  background(255);
  fill(255,0,0);
  ellipse(x,y,20,20);
}

void keyPressed()
{
  // move left
 if(keyCode == 37)
 {
  x-=5; 
 }
 
 // move right
 if(keyCode == 39)
 {
   x+=5;
 }
}
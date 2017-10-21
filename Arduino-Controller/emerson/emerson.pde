int x = 0;  // create a variable called x, set it equal to zero... for now
int y = 0;  // create a variable called y, set it equal to zero... for now

void setup()
{
  size(400,400); 
  fill(255,0,0);
  x = width/2;
  y = height/2;
  rectMode(CENTER);
}

void draw()
{
  background(255);
  rect(x,y,20,20);
  

  
}

void keyPressed()
{
   if(key == 'w')  // move up
 {
  y = y - 2;   // this line is connected to line 16 above...
 }
 
 if(key == 's')  // move down
 {
  y = y + 2; 
 }
 
 if(key == 'a')  // move left
 {
   x = x - 2; 
 }
 
 if(key == 'd')  // move left
 {
   x = x + 2; 
 }
}
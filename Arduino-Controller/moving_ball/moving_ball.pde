int x= 0;
int a = 0;
int b = 0;
int difference = 0;

void setup()
{
 size(400,400); 
}

void draw()
{
  background(255);
  fill(255,0,0);
 ellipse(x,height/2, 20,20); 
 
 if(key == 'd') // replace this logic
 {
  x+=10;
 }
 if(key == 'a')
 {
  x-=10; 
 }


}


 
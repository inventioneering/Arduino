import processing.serial.*;

Serial sp;
byte[] buff;
float[] r;
float x,y,z;

int SIZE = 150, SIZEX = 200;
int OFFSET_X = 2, OFFSET_Y = 0;

int ballX= 0;
int ballY = 0;
int a = 0;
int b = 0;
int difference = 0;
int positionChange = 2;
int verticalPosition;


void setup()
{
 size(400,400); 
 ballX = width/2;
 sp = new Serial(this, "/dev/cu.usbmodem1421",  9600);
 buff = new byte[128];
 r = new float[3];
 verticalPosition = height/2;

}

void draw()
{
   int bytes = sp.readBytesUntil((byte)10, buff);
    String mystr = (new String(buff, 0, bytes)).trim();
    if(mystr.split(" ").length != 3) {
     // println(mystr);
      return;
    }
    setVals(r, mystr);
    z = r[0];
    x = r[1];
    y = r[2];
    
    
   if(x <= - 20)  // right
   {
     ballX +=2;
   }
   
   if(x > 10)  // left
   {
     ballX -= 2; 
   }
   
   if(z < -30)  //up
   {
     ballY -= 2;
   }
 
   if(z >= 30)  // down
   {
    ballY += 2; 
   }
   
    
    background(255);  
    
    println(x + ", " + z);

    fill(255,0,0);
    ellipse(ballX,ballY, 20,20); 
    //if(1==1)
    //{
    //  verticalPosition -= positionChange;
    //}
    //println("This is the z value: " + abs);
}



void setVals(float[] r, String s) 
{
  int i = 0;
  r[0] = -(float)(Integer.parseInt(s.substring(0, i = s.indexOf(" "))) +OFFSET_X)*HALF_PI/256;
  r[1] = -(float)(Integer.parseInt(s.substring(i+1, i = s.indexOf(" ", i+1))) + OFFSET_Y)*HALF_PI/256;
  r[2] = (float) Integer.parseInt(s.substring(i+1)); 
}


 
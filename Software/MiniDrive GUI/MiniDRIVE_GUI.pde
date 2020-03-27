import processing.serial.*; //Importing the Serial library.

Serial myPort; //Creating a port variable.

int r,g,b; //Initializing colours.

String T= "MiniDRIVE GUI"; //Creating word strings for the interface.
String t= "Developed by: Tanmay Samak and Chinmay Samak";
String T1= "FORWARD";
String T2= "RIGHT";
String T3= "LEFT";
String T4= "BACKWARD";
String T5= "STOP"; 

void setup()
{
  size(1080,480); //Creating the display window and defining its size.
 
  r = 0; //Setting up the colours.
  g = 0;
  b = 0;

  myPort = new Serial(this, "COM11", 4800); //Initializing the serial port with 9600 baud rate [Specify the required COM Port & baud rate for serial communication].
}
 
void draw()
{
  background(255,255,255); //Setting up the background colour to White.
  
  textSize(32); //Defining the Title's size = 32.
  fill (0,0,0); //Painting the Title black.
  textAlign(CENTER,CENTER);  //Aligning Title to center horizontally and vertically.
  text(T,540,25);  //Placing the Title in a specific location.
  
  textSize(16); //Defining the Subtitle's size = 16.
  fill (0,0,0); //Painting the Subtitle black.
  textAlign(CENTER,CENTER);  ////Aligning Subtitle to center horizontally and vertically.
  text(t,540,60);  //Placing the Subtitle in a specific location.

  fill (150,150,150); //Painting the buttons Dark Grey.

  rect(755,125,100,100,10); //FORWARD BUTTON
  rect(755,250,100,100,10); //BACKWARD BUTTON
  rect(630,250,100,100,10); //LEFT BUTTON
  rect(880,250,100,100,10); //RIGHT BUTTON
  rect(100,250,400,100,10); //SPACE BAR

  textSize (16); //Defining the Button Text's size = 16.
  fill (0,0,0); // Painting it black.
  textAlign(CENTER,CENTER);  //Text alignment.
  text(T1,805,175); //FORWARD Text.
  textAlign(CENTER,CENTER);
  text(T2,930,300);//RIGHT Text.
  textAlign(CENTER,CENTER);
  text(T3,680,300); //LEFT Text.
  textAlign(CENTER,CENTER);
  text(T4,805,300);//BACKWARD Text.
  textAlign(CENTER,CENTER);
  text(T5,300,300); //STOP Text.
}
 
void keyPressed()
{
  switch(keyCode)  //Switch Case for the Key pressed (UP arrow, DOWN arrow, LEFT arrow, RIGHT arrow, SPACE bar).
    {
      case UP: //In case the UP arrow key is pressed:
      myPort.write('w'); // Send "w"
      println("ROBOT IS MOVING FORWARD"); //Print the received data.
      fill(200,200,200); //Paint the FORWARD BUTTON Light Grey.
      rect(755,125,100,100,10); //FORWARD BUTTON
      break;
      
      case DOWN: //In case the DOWN arrow key is pressed:
      myPort.write('s'); // Send "s"
      println("ROBOT IS MOVING BACKWARD"); //Print the received data.
      fill(200,200,200); //Paint the BACKWARD BUTTON Light Grey.
      rect(755,250,100,100,10); //BACKWARD BUTTON
      break;
      
      case LEFT: //In case the LEFT arrow key is pressed:
      myPort.write('a'); // Send "a"
      println("ROBOT IS TAKING LEFT TURN"); //Print the received data.
      fill(200,200,200); //Paint the LEFT BUTTON Light Grey.
      rect(630,250,100,100,10); //LEFT BUTTON
      break;
      
      case RIGHT: //In case the RIGHT arrow key is pressed:
      myPort.write('d'); // Send "d"
      println("ROBOT IS TAKING RIGHT TURN"); //Print the received data.
      fill(200,200,200); //Paint the RIGHT BUTTON Light Grey.
      rect(880,250,100,100,10); //RIGHT BUTTON
      break;
      
      case ' ': //In case the SPACE bar key is pressed:
      myPort.write('x'); // Send "x"
      println("ROBOT HAS STOPPED"); //Print the received data.
      fill(200,200,200); //Paint the SPACE BAR Light Grey.
      rect(100,250,400,100,10); //SPACE BAR
      break;
      
      default:
      break;
    }
}

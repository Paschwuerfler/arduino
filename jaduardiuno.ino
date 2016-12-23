// include the SevenSegmentTM1637 library
#include "SevenSegmentTM1637.h"

const byte button1 = 10;
const byte button2 = 11;
const byte button3 = 12;

const byte PIN_CLK = 4;   // define CLK pin (any digital pin)
const byte PIN_DIO = 5;   // define DIO pin (any digital pin)
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

int number = 10;
byte lastpress = 0;
byte setmode = 1;
byte lastpress2;
byte hours = 0;
byte minutes = 0;
int hm = 0;

int bs1 = digitalRead(button1);
int bs2 = digitalRead(button2);
int bs3 = digitalRead(button3);

// run setup code
void setup() {
  Serial.begin(250000);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  display.setBacklight(100);  // set the brightness to 100 %
  display.print("RDY");      // display INIT on the display

  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:


 bs1 = digitalRead(button1);
 bs2 = digitalRead(button2);
 bs3 = digitalRead(button3);

 Serial.println("buttonstate");
 Serial.println(bs2);

 Serial.println("lastpress");
 Serial.println(lastpress);

 if((bs2==1) && (lastpress==0))
 {setmode ++;}

 if(setmode == 4)
 {setmode = 1;}



 
 Serial.println("setastate:");
 Serial.println(setmode);

 Serial.println("hmin");
 Serial.println(hm);

 //if (setmode == 1)
 //{
display.print(hm);
 //}


 
 if (setmode == 2)
 {
  if (bs1 = 1)
  { hours --;}

  if (bs3 = 1)
  { hours ++;}
 }

 if (setmode == 3)
 {
  if (bs1 = 1)
  { minutes ++;}

  if (bs3 = 1)
  { minutes --;}
 }

 

 if (bs2 == 1)
 {
    digitalWrite(LED_BUILTIN, HIGH); 
 }

 if (bs2 == 0)
 {
    digitalWrite(LED_BUILTIN, LOW); 
 }

 if(hours == 24)
 {hours = 0;}

 if(hours == 61)
 {hours = 0;}
 
lastpress = bs2;
delay(20);
}


#include <Servo.h>


Servo myservo1;
Servo myservo2;
int pos = 0;
int vel = 10;
int parado = 0;

void setup()
{
  myservo1.attach(10);
  myservo2.attach(11);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  attachInterrupt(digitalPinToInterrupt(3),veldown, CHANGE);
  attachInterrupt(digitalPinToInterrupt(2),velup, CHANGE);
  Serial.begin(9600);
}

void veldown()
{
  if(vel < 15)
  {
  	vel ++;
  }
  if(vel >= 15)
  {
   	parado = 1;
  }
}

void velup()
{
  if(vel > 6)
  {
  	vel --;
  }
  if(parado == 1)
  {
   	parado = 0; 
  }
}

void loop()
{
  if(parado == 0)
  {
  	Serial.print(vel);
  	for (pos = 0; pos <= 180; pos += 1)
  	{
   	 myservo1.write(pos);
   	 myservo2.write(pos);
   	 delay(vel);
 	}
  	for (pos = 180; pos >= 0; pos -= 1) 
  	{
     myservo1.write(pos);
     myservo2.write(pos);
     delay(vel);
    }
  }
}

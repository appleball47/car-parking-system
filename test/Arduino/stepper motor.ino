/*
* Hardware Connection
* Servo red wire – 5V pin Arduino         
* Servo brown wire – Ground pin Arduino         
* Servo yellow wire – PWM(9) pin Arduino
*/

#include <Servo.h> //Including header file to operate servo motor

Servo myservo; //Creating a object of servo class
int val;

void setup()
{
    myservo.attach(9); //Connection servo motor to arduino
}

void loop()
{
    for (val = 0; val < 180; val++)
    {
        myservo.write(val); //Rotating servo motor from 0 to 180 dergree
        delay(15);
    }
}
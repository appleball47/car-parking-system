/*
* It is possible to use HC-S04 in 3 wire system.    
* 
* Hardware Connection
* VCC - 5V
* TRIG - 10
* ECHO - 10
* GND - GND
* Usage of NewPing.h library imporves the accuracy of the sensors.
* By using this libary we eliminate the need to manually sending and receiving 10 micro-sec
* signal pulse. This library is not available by default and can be installed from library manager.
*/

// Include NewPing Library
#include "NewPing.h"

// Define Constants

#define TRIGGER_PIN 10 // Trigger and Echo both on pin 10
#define ECHO_PIN 10
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Define Variables

float duration; // Stores HC-SR04 pulse duration value
float distance; // Stores calculated distance in cm
int iterations = 5;

void setup()
{
    Serial.begin(9600);
}

void loop()
{

    duration = sonar.ping_median(iterations);

    // Determine distance from duration
    // Use 343 metres per second as speed of sound

    distance = (duration / 2) * 0.0343;

    // Send results to Serial Monitor
    Serial.print("Distance = ");
    if (distance >= 400 || distance <= 2)
    {
        Serial.println("Out of range");
    }
    else
    {
        Serial.print(distance);
        Serial.println(" cm");
        delay(500);
    }
    delay(500);
}
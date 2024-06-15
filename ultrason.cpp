// ultrason.cpp

#include <Arduino.h>
#include <Ultrasonic.h>
#include "ultrason.h"

void setup_ultrason(int trig, int echo)
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
}

float mesurer_distance(int trig, int echo)
{
  long timeInMicro;
  long distanceInCm;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  timeInMicro = pulseIn(echo, HIGH);
  distanceInCm = timeInMicro /29 /2;

  /*/
  Serial.println(" ");
  Serial.print("distance : ");
  Serial.println(distanceInCm);
  /*/
  return distanceInCm;
}
// bras_robot.cpp

// necessite servo 180

#include <Arduino.h>
#include <Servo.h>
#include "bras_robot180.h"

Servo myservo180;

//  int servo_signal = 9;

  void setup_bras_robot(int servo_signal)
  {
    // servomoteur 180
    myservo180.attach(servo_signal);
    myservo180.write(0);
  }

  void ouvrir_bras()
  {
      myservo180.write(180);
  }

  void fermer_bras() 
  {
      myservo180.write(0);
  }








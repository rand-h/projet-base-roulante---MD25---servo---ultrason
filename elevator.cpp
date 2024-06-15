// elevator.cpp 

#include "Arduino.h"
#include "Servo.h"
#include "elevator.h"

Servo elevator;

// Setup
  void setup_elevator(int servo_signal)
  {
    // servomoteur 360 (moteur continu)
    elevator.attach(servo_signal); // attach the servo to our servo object
    elevator.write(90); // stop the motor
    init_elevator();
  }

// commande servomoteur pour le bras
  void monter()
  {
    elevator.write(135); // sens horaire // ouvrir
    delay(2000); // keep rotating for 200 ms
    elevator.write(90); // arreter le moteur
  }

  void descendre() 
  {
    elevator.write(45); // sens anti-horaire
    delay(2000); // keep rotating for 200 ms
    elevator.write(90); // arreter le moteur
  }

  void init_elevator()
  {
    elevator.write(135);
    delay(500);
    elevator.write(45); // sens horaire // ouvrir
    delay(2000); // keep rotating for 200 ms
    elevator.write(90); // arreter le moteur
  }








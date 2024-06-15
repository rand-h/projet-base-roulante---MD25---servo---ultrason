// driven.cpp 

// necessice servo 360

#include "Arduino.h"
#include "Servo.h"
#include "driven.h"

Servo driven;

// Setup
  void setup_driven(int servo_signal)
  {
    // servomoteur 360 (moteur continu)
    driven.attach(servo_signal); // attach the servo to our servo object
    driven.write(90); // stop the motor
    init_driven();
  }

  void sortir()
  {
    driven.write(135); // sens horaire // ouvrir
    delay(1000); // keep rotating for 200 ms
    driven.write(90); // arreter le moteur
  }

  void rentrer() 
  {
    driven.write(45); // sens anti-horaire
    delay(900); // keep rotating for 200 ms
    driven.write(90); // arreter le moteur
  }

  void init_driven()
  {
    driven.write(135); // sens horaire // ouvrir
    delay(950); // keep rotating for 200 ms
    driven.write(90); // arreter le moteur
  }








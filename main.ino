#include <Arduino.h>

#include "motor.h"
#include "ultrason.h"
#include "driven.h"
#include "elevator.h"
#include "bras_robot.h"

// ------ variables -------
// ---- capteurs ----
//-- avant
// gauche
int trig_g = 50;
int echo_g = 51;

// droite 
int trig_d = 36;
int echo_d = 40;

// milieu
int trig_m = 49;
int echo_m = 48;

//-- arriere
// rear gauche
int trig_rear_g = 38;
int echo_rear_g = 39;

// rear droite 
int trig_rear_d = 42;
int echo_rear_d = 43;

// rear milieu
int trig_rear_m = 44;
int echo_rear_m = 45;

// actionneur
int driven_pin = 11;
int elevator_pin = 3;
int servo_signal = 9; // bras

// millis counter
float start_time = 0;


// ----------------------------- setup ---------------------------------
void setup() 
{
  Serial.begin(9600);

  //--- setup capteur ----
  //--avant
  setup_ultrason(trig_d, echo_d);  // Droite
  setup_ultrason(trig_g, echo_g);  // Gauche
  setup_ultrason(trig_m, echo_m);  // milieu

  //--arriere
  setup_ultrason(trig_rear_g, echo_rear_g);  // Arrière gauche
  setup_ultrason(trig_rear_d, echo_rear_d);  // Arrière droite
  setup_ultrason(trig_rear_m, echo_rear_m);  // Arrière milieu

  //--- setup moteur ----
  setup_moteur();
  
  //--- setup servo bras robot ---
  setup_bras_robot(servo_signal);
  
  //--- setup servo driven ---
  setup_driven(driven_pin);   // panneau solaire

  //--- setuo servo elevator ----
  setup_elevator(elevator_pin);
}



int etat = 1;

// ---------------------------- Action pendant le jeu ------------------------
void loop() 
{

  int v = 150; // vitesse

  int obstacle = 20; // cm
  
  int duree_jeu = 90 * 1000; // 90 secondes
  
  while (millis() < duree_jeu && etat == 1) // faire des actions pendants le temps de jeux
  {
    /*/
    if (mesurer_distance(trig_d , echo_d) < obstacle || mesurer_distance(trig_g , echo_g) < obstacle || mesurer_distance(trig_m , echo_m) < obstacle)
    {
      stop();
    }
  
    else
    {/*/

    // strategie -->
       
       rentrer();    // commande pour bras panneau solaire
       sortir();
       
       //descendre();
        
       avancer_un_peu(95);
       stop();
       rentrer();

       delay(1000);

       tourner_gauche();

       delay(1000);
      
      //

       avancer_un_peu(160);
       //fermer_bras();
 
      //
       stop();

       delay(1000);

       tourner_gauche();
       delay(1000);

       avancer_un_peu(95);
       
       stop();
       delay(1000);
      //

       etat = 0;
       break;   
    //}
  }

  stop();
}


/// -------------- definitions autres fonctions -------------------





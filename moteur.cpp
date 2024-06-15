// moteur.cpp

#include <Arduino.h>
#include <Wire.h>
#include "moteur.h"

#define MD25 0x58
#define SPEED1 0x00
#define ENCODER1 0x02
#define RESET_ENCODER 0x20

void setup_moteur()
{
  Wire.begin();
  Wire.beginTransmission(MD25);
  Wire.write(RESET_ENCODER);
  Wire.endTransmission();
}


void stop() {
  Wire.beginTransmission(MD25);
  Wire.write(SPEED1);
  Wire.write(128); // Mode à 1 pour arrêter les moteurs
  Wire.write(128); // Mode à 1 pour arrêter les moteurs
  Wire.endTransmission();
}

void avancer(int vitesse_moteur1, int vitesse_moteur2) { // temps en seconde
  definir_vitesse(vitesse_moteur1, vitesse_moteur2);
}

void reculer(int vitesse_moteur1, int vitesse_moteur2) { // temps en seconde
  definir_vitesse(-vitesse_moteur1, -vitesse_moteur2);
}

void definir_vitesse(int vitesse_moteur1, int vitesse_moteur2) {
  Wire.beginTransmission(MD25);
  Wire.write(SPEED1);
  Wire.write(vitesse_moteur1); // Vitesse moteur 1
  Wire.write(vitesse_moteur2); // Vitesse moteur 2
  Wire.endTransmission();
}


void avancer_basic(int distance, int sens)
{
  float t = distance / 0.01787; // distance / vitesse_moyenne
  int obstacle = 20;

  int parcouru = 0;

  int v = 150;

  (sens >= 0) ? (sens = 1) : (sens = 0); 

  v = v * sens; 

  // calcul temps d'arret si obstacle detecter

  start_time = millis();

    while (millis() - start_time < t - parcouru) 
    {
      if (mesurer_distance(trig_d , echo_d) < obstacle || mesurer_distance(trig_g , echo_g) < obstacle || mesurer_distance(trig_m , echo_m) < obstacle)
        { 
          parcouru = millis() - start_time; 
          stop(); 
          start_time = millis();  
        }
      else
      {
          avancer(v,v);
      }     
    }
  stop();
  start_time = 0;
}


void avancer_un_peu(int distance)
{
  float Vm = 0.01787;
  float t = distance / Vm; // distance / vitesse_moyenne
  int v = 150;

  int obstacle = 20;

  int parcouru = 0;
  int temporisateur = 0;

  // calcul temps d'arret si obstacle detecter

  start_time = millis();

    while (millis() - start_time < t - parcouru) 
    {
        if (mesurer_distance(trig_d , echo_d) < obstacle || mesurer_distance(trig_g , echo_g) < obstacle || mesurer_distance(trig_m , echo_m) < obstacle)
        { 
          parcouru = millis() - start_time; 
          stop(); 
          start_time = millis();  

          temporisateur += parcouru; // calcul le temps d'arret
          //
          if (temporisateur > 5000)   // si obstacle detecter et robot reste bloquer pendant 5 secondes
          {
            // action si l'obstacle est ad
            int d = 50; // distance d'avancement

            (temporisateur % 2 == 0) ? (eviter_obstacle1(d)) : (eviter_obstacle2(d));
            //eviter_obstacle2(d);

            t += (d / Vm);
            start_time = millis();
          }
          //
        }
        else
        {
          avancer(v,v);
          temporisateur = 0;
        }
    }
  stop();
  start_time = 0;
}

void eviter_obstacle1(int d)  // d est la distance qu'il doit parcourir pendant la deviation
{
    int av = 30;
    rentrer();
    ouvrir_bras(); // rentrer bras

    tourner_gauche();

    avancer_basic(av , 1);

    tourner_droite();
    avancer_basic(d, 1);

    tourner_droite();

    avancer_basic(av , 1);

    tourner_gauche();

    delay(2000);
}

void eviter_obstacle2(int d)
{
    float sqrt_deux = 0.707; // sqrt(2) / 2 = sin(45°)

    rentrer();
    ouvrir_bras(); // rentrer bras

    tourner_gauche_45();

    avancer_basic(sqrt_deux * d , 1);

    tourner_droite();

    avancer_basic(sqrt_deux * d , 1);

    tourner_gauche_45();

    delay(2000);
}

void eviter_obstacle3(int d)
{
    rentrer();
    ouvrir_bras();

    avancer_basic(d , -1);

    delay(4000);    // reculer et attendre l'autre 

    avancer_basic(d , 1);

    delay(1000);
}


void reculer_un_peu(int distance)
{
  float t = distance / 0.01787; // distance / vitesse_moyenne

  int v = 150;

  int obstacle = 20;

  int parcouru = 0;

  // calcul temps d'arret si obstacle detecter

  start_time = millis();

    while (millis() - start_time < t - parcouru) 
    { // utilise les capteurs ultrason arrières
        if (mesurer_distance(trig_rear_d, echo_rear_d) < obstacle || mesurer_distance(trig_rear_g, echo_rear_g) < obstacle || mesurer_distance(trig_rear_m, echo_rear_m) < obstacle)
        { // mettre des capteurs à l'arriere
          parcouru = millis() - start_time;
          stop();
          start_time = millis();
        }
        else
        {
          avancer(-v,-v);
        }
    } 

  stop();
  start_time = 0;
}


void tourner_droite() {
  definir_vitesse(150, -150); // Tourner à droite en ralentissant le moteur gauche 
  delay(1000); // Temps de rotation pour effectuer un demi-tour
  stop();
}

void tourner_droite_45() {
  definir_vitesse(150, -150); // Tourner à droite en ralentissant le moteur gauche 
  delay(500); // Temps de rotation pour effectuer un demi-tour
  stop();
}

void tourner_gauche() {
  definir_vitesse(-150, 150); // Tourner à droite en ralentissant le moteur gauche 
  delay(1000); // Temps de rotation pour effectuer un demi-tour
  stop();
}

void tourner_gauche_45() {
  definir_vitesse(-150, 150); // Tourner à droite en ralentissant le moteur gauche 
  delay(500); // Temps de rotation pour effectuer un demi-tour
  stop();
}

void demi_tour() {
  definir_vitesse(150, -150); // Tourner à droite en ralentissant le moteur gauche 
  delay(2000); // Temps de rotation pour effectuer un demi-tour
  stop();
}



// avancer progressivement la vitesse jusqu'à la vitesse cible
    void avancerProgressivement(int vitesseCible, int accel) 
    {
      int vitesseActuelle = 0; // Commencez à l'arrêt
      int coef_accel = 10;    // pause avant chaque boucle

      int increment = accel;

      while (vitesseActuelle < vitesseCible) 
      {
        vitesseActuelle += increment; // Augmentez la vitesse par l'incrément
        
        if (vitesseActuelle > vitesseCible) 
        {
          vitesseActuelle = vitesseCible; // Assurez-vous de ne pas dépasser la vitesse cible
        }
        // Envoyez la nouvelle vitesse aux moteurs

        definir_vitesse(vitesseActuelle , vitesseActuelle);

        delay(coef_accel); // Attendez un peu avant d'augmenter à nouveau la vitesse
      }
    }


// reculer progressivement la vitesse jusqu'à la vitesse cible
    void reculerProgressivement(int vitesseCible, int accel) 
    {
      int vitesseActuelle = 0; // Commencez à l'arrêt
      int coef_accel = 10;    // pause avant chaque boucle

      int increment = accel;

      while (vitesseActuelle > vitesseCible) 
      {
        vitesseActuelle -= increment; // Augmentez la vitesse par l'incrément
        
        if (vitesseActuelle < vitesseCible) 
        {
          vitesseActuelle = -vitesseCible; // Assurez-vous de ne pas dépasser la vitesse cible
        }
        // Envoyez la nouvelle vitesse aux moteurs

        definir_vitesse(vitesseActuelle , vitesseActuelle);

        delay(coef_accel); // Attendez un peu avant d'augmenter à nouveau la vitesse
      }
    }








// moteur.h 

#include "Arduino.h"

void setup_moteur();

void definir_vitesse(int vitesse_moteur1, int vitesse_moteur2); 

void avancer(int vitesse_moteur1, int vitesse_moteur2); 
void reculer(int vitesse_moteur1, int vitesse_moteur2); 

void avancer_un_peu(int distance);
void reculer_un_peu(int distance);

void tourner_droite(); 
void tourner_droite_45(); 

void tourner_gauche(); 
void tourner_gauche_45(); 

void avancer_basic(int distance, int sens);

void demi_tour(); 

void stop();

void avancerProgressivement(int vitesseCible); 
void reculerProgressivement(int vitesseCible); 

// necessite des capteurs
void eviter_obstacle1(int d);     // contourner en carrée
void eviter_obstacle2(int d);     // contourner en triangle 45°
void eviter_obstacle3(int d);     // reculer, pause, attendre l'autre et avancer







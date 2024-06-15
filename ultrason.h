// ultrason.h -> library pour le capteur ultrason

#include <Arduino.h>

void setup_ultrason(int trig, int echo);

float mesurer_distance(int trig, int echo);

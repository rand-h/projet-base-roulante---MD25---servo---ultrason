# Projet Robotique sous Arduino

## Introduction
Ce projet a pour ambition de concevoir un robot autonome piloté par une carte Arduino. Il est conçu pour naviguer de manière autonome dans un environnement complexe en utilisant une gamme de capteurs et d'actionneurs. L'objectif principal est de créer un système robotique flexible et évolutif, capable de s'adapter à diverses applications et missions.

**Logiciel Utilisé :** [Arduino IDE](https://www.arduino.cc/en/software)
## Composants
Le robot est composé des éléments suivants :
- **Arduino** - [Acheter](https://www.gotronic.fr/art-carte-joy-it-2560-r3-25502.htm) | [Documentation](https://docs.arduino.cc/#:~:text=Arduino%20Documentation%201%20Hardware%20The%20vital%20pieces%20of,to%20program%20with%20Arduino%2C%20including%20library%20documentation.%20)
- **Capteur ultrason (HC-SR04)** - [Acheter](https://www.gotronic.fr/art-module-a-detection-us-hc-sr04a-27740.htm) | [Documentation](https://www.hwlibre.com/fr/hc-sr04/)
- **Servomoteur 180 (FS90)** - [Acheter](https://www.gotronic.fr/art-servomoteur-analogique-miniature-fs90-25826.htm) | [Documentation]()
- **Servomoteur 360 (SG90)** - [Acheter](https://www.amazon.fr/servomoteur-sg90/s?k=servomoteur+sg90) | [Documentation](https://arduino-france.site/ultrason-hc-sr04/)
- **Module de propulsion RD02 (MD25 + moteur EMG30)** - [Acheter](https://www.gotronic.fr/art-module-de-propulsion-rd02-11565.htm) | [Documentation](http://www.robot-electronics.co.uk/htm/md25tech.htm)
- **Capteur IMU (Grove - IMU 10DOF)** - [Acheter](https://wiki.seeedstudio.com/Grove-IMU_10DOF/) | [Documentation](https://wiki.seeedstudio.com/Grove-IMU_10DOF/)

Autres :  
`Modèle 3D à imprimer`
- **pince robot**\
&ensp;&ensp;&ensp;├── Model 3D/pince.3mf
- **Elevator** : inspiré de [Linear Servo Actuators](https://www.thingiverse.com/thing:3170748)\
&ensp;&ensp;&ensp;├── Model 3D/elevator + servo.3mf
&ensp;&ensp;&ensp;├── Model 3D/bouge_panneau.3mf

## Structure des Fichiers de Code
Le projet se compose de plusieurs types de fichiers :
- `main.ino` : Le fichier principal contenant le code d'exécution du robot.
- `.h` : Fichiers d'en-tête contenant les déclarations des fonctions et des classes.
- `.cpp` : Fichiers source contenant les définitions des fonctions et des classes.

Pour intégrer une fonction dans votre projet, incluez simplement le fichier `.h` correspondant dans `main.ino`.

**Arborescence des fichiers :**\
main/\
&ensp;&ensp;&ensp;├── main.ino &emsp;// Fichier principal\
&ensp;&ensp;&ensp;├── moteur.h/cpp &emsp;// Gestion des moteurs\
&ensp;&ensp;&ensp;├── ultrason.h/cpp &emsp;// Capteurs ultrasons\
&ensp;&ensp;&ensp;├── bras_robot.h/cpp &emsp;// Bras robotique à servomoteur 180°\
&ensp;&ensp;&ensp;├── driven.h/cpp &emsp;// Charnière à servomoteur 360°\
&ensp;&ensp;&ensp;├── elevator.h/cpp &emsp;// Monte-charge à servomoteur 360°\
&ensp;&ensp;&ensp;└── IMU.h/cpp &emsp;// Capteur IMU

## Contribuer au Projet
Nous invitons activement la communauté à participer au projet. Que ce soit pour l'apport d'améliorations au code ou pour des propositions d'idées, **toutes les contributions sont les bienvenues**.


##
Auteur : Hosea Rand.

#include <Arduino.h>

/*
  Commande Servo Moteur MG995

  Programme Basique sur Arduino Mega.
  Visual Studio Code (VSC) en utilisant l'extension PlateformIO IDE (PIO) v3.3.3

  Consituants :
  - servo moteur MG 995
  -Potentiomètre 10 kOhm

  version 1 : 12 novembre 2024
  dernière mise à jour : 19 novembre 2024
*/

//---Inclusion des bibliothèques 
//-Librarie Arduino.h à inclure pour fonctionner sur Visual Studio Code
#include <Arduino.h>
//-Librarie Servo.h à télécharger via l'outil "Libraries" de PIO
#include <servo.h>


//---Déclaration des variables et autres objets.

Servo myServo; //Création de l'objet servo appelable sous le nom "myServo".

int const potPin = A0;  //On connecte le curseur du potentiomètre à la broche analogique A0 de l'Arduino
int potVal; //Variable de la position du potentiomètre après la conversion 
int angle; //Variable de l'angle du servo moteur

int angle_min = 0; //Angle minimum que peut prendre le servo moteur
int angle_max = 90; //Angle maximum que peut prendre le servo moteur sans l'endommager 

//---Configuration

void setup() {
  myServo.attach(3); //On déclare que la commande du servo moteur est sur le pin digital 3 de l'arduino
  Serial.begin(9600);//Initialisation du moniteur série
}



void loop() {
  Serial.println();
  Serial.println("Nouvelle commande d'angle");
  Serial.println();

  //-Lecture de la commande angulaire

  potVal = analogRead(potPin);    //Lecture de la valeur du potentiomètre 
  Serial.print("Valeur du potentiomètre : ");
  Serial.println(potVal);

  //-Mise à l'échelle des valeurs
  angle=map(potVal, 0, 1023, angle_min, angle_max); 
  //La fonction map va remettre à l'échelle la valeur lu sur le pin A0 qui est entre 0 et 1023 (donc sur 10bits) 
  //pour qu'elle soit remise proportionnellement entre l'angle minimum et maximum

  //Affichage de l'angle demandé
  Serial.print("Angle du servomoteur: ");
  Serial.print(angle);
  Serial.println("°");
  Serial.println();

  //Application de la commande position au servo moteur
  myServo.write(angle);

  delay(2000);
}

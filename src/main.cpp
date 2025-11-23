#include <Arduino.h>
#include "BluetoothGarf.h"
#include "sPrint.h"


void setup() {
  Serial.begin(115200);
  setupBluetooth();
  Serial.println("Robot Garfield prêt (serveur).");
  
}

void loop() {
  etat etatGarfield = { 2, 0}; // Exemple d'état de Garfield à envoyer
  positionEtEtat etatLasagne;

envoieEtat(etatGarfield);
Serial.println("Garfield enyoyé position à Lasagne");

  if (recoieEtat(etatLasagne)) {
    printPosition(etatLasagne);
    // Serial.print("Position reçu : ");
    // Serial.print(etatLasagne.x);
    // Serial.print(", ");
    // Serial.print(etatLasagne.y);
    // Serial.print(", ");
    // Serial.print(etatLasagne.etatJeu);
    // Serial.print(", ");
    // Serial.print(etatLasagne.GelerAutreRobot);
  }

  delay(2000); // Attendre avant le prochain envoi
}
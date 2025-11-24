#include "BluetoothGarf.h"


BluetoothSerial SerialBT;

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Envoie la position et l'état du robot sous forme de structure via Bluetooth
 *
 * @param Etat (structure) structure contenant l'état du robot
 ******************************************************************************************/

void envoieEtat(const etat &pos) { // Prend la reférence d'une structure Position en paramètre
  SerialBT.write((uint8_t*)&pos, sizeof(etat)); 
}

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Lit la position et l'état du robot sous forme de structure via Bluetooth et la copie dans la structure passée en paramètre
 *
 * @param positionEtEtat (structure) structure contenant la position (x,y) et l'état du robot
 ******************************************************************************************/

bool recoieEtat(positionEtEtat &pos) {
  if (SerialBT.available() >= sizeof(positionEtEtat)) {
    SerialBT.readBytes((uint8_t*)&pos, sizeof(positionEtEtat));
    return true;
  }
  return false;
}

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Démarre le module Bluetooth en mode serveur
 ******************************************************************************************/
void setupBluetooth() // Initialisation du Bluetooth
{
  SerialBT.begin("ESP32_Garfield"); // Nom du périphérique Bluetooth
}


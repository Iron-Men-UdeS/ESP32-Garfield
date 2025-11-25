#include "BluetoothGarf.h"


BluetoothSerial SerialBT;

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Envoie la position et l'état du robot sous forme de structure via Bluetooth
 *
 * @param sEtat (structure) structure contenant l'état du robot
 ******************************************************************************************/

void envoieEtatstruct(const sEtat &pos) { // Prend la reférence d'une structure Position en paramètre
  SerialBT.write((uint8_t*)&pos, sizeof(sEtat)); 
}


/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Lit la position et l'état du robot sous forme de structure via Bluetooth et la copie dans la structure passée en paramètre
 *
 * @param sPositionEtEtat (structure) structure contenant la position (x,y) et l'état du robot
 ******************************************************************************************/
bool recoieEtatstruct(sPositionEtEtat &pos) {
  if (SerialBT.available() >= sizeof(sPositionEtEtat)) {
    SerialBT.readBytes((uint8_t*)&pos, sizeof(sPositionEtEtat));
    return true;
  }
  return false;
}


/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Démarre le module Bluetooth en mode client
 ******************************************************************************************/

void setupBluetooth() // Initialisation du Bluetooth
{
  SerialBT.begin("ESP32_Garfield"); // Nom du périphérique Bluetooth
}


/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Envoie la position et l'état du robot sous forme de tableau via Bluetooth
 *
 * @param tab tableau contenant la position (x,y) et l'état du robot
 ******************************************************************************************/

void envoieEtat(uint8_t *tab) { // Prend la reférence d'une structure Position en paramètre
  SerialBT.write(0x24); // Envoie le caractère '$' pour indiquer le début de la trame
  SerialBT.write(tab, sizeof(tab)); 
}

/*******************************************************************************************
 * Auteur : Vincent
 * 
 * Lit la position et l'état du robot sous forme de tableau via Bluetooth
 *
 * @param tab tableau dans lequel la position et l'état du robot seront copiés
 ******************************************************************************************/

bool recoieEtat(uint8_t *tab)
{
  if (SerialBT.available() >= sizeof(tab))
  {
    if (SerialBT.read() == 0x24)
    {
      SerialBT.readBytes(tab, sizeof(tab));
      return true;
    }
  }
  return false;
}
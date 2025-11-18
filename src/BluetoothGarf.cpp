#include "BluetoothGarf.h"


BluetoothSerial SerialBT;



void envoieEtat(const etat &pos) { // Prend la reférence d'une structure Position en paramètre
  SerialBT.write((uint8_t*)&pos, sizeof(etat)); 
}

bool recoieEtat(positionEtEtat &pos) {
  if (SerialBT.available() >= sizeof(positionEtEtat)) {
    SerialBT.readBytes((uint8_t*)&pos, sizeof(positionEtEtat));
    return true;
  }
  return false;
}

void setupBluetooth() // Initialisation du Bluetooth
{
  SerialBT.begin("ESP32_Garfield"); // Nom du périphérique Bluetooth
}


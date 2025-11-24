#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <BluetoothSerial.h>

struct sPositionEtEtat {
  float x;
  float y;
  int etatJeu;
  bool GelerAutreRobot;
};

struct sEtat {
  int etatJeu;
  bool GelerAutreRobot;
};

extern BluetoothSerial SerialBT;

void envoieEtat(uint8_t *tab);
bool recoieEtat(uint8_t *tab);

bool recoieEtatstruct(sPositionEtEtat &pos);
void envoieEtatstruct(const sEtat &pos);

void setupBluetooth();
void connexionBluetooth();


#endif
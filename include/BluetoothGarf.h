#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <BluetoothSerial.h>

struct positionEtEtat {
  float x;
  float y;
  int etatJeu;
  bool GelerAutreRobot;
};

struct etat {
  int etatJeu;
  bool GelerAutreRobot;
};

void envoieEtat(const etat &pos);
bool recoieEtat(positionEtEtat &pos);
void setupBluetooth();
void connexionBluetooth();


#endif
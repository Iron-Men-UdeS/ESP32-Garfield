#include <Arduino.h>
#include "BluetoothGarf.h"
#include "sPrint.h"
#include "comUART.h"


// sEtat etatGarfield = { 2, 0}; // Exemple d'état de Garfield à envoyer
// sPositionEtEtat etatLasagne;

uint8_t tabLasagne[4] = {22,22,22,22}; // [x , y , Gel , etatJeu]

uint8_t tabGarfield[2] = {22,22}; // [Gel , etatJeu]
void setup() {
  Serial.begin(115200);
  initUART1();
  setupBluetooth();
  // Serial.println("Robot Garfield prêt (serveur).");
  
}

void loop()
{
  
  if (SerialBT.connected()) { // si le robot est connecté via Bluetooth
  envoieEtat(tabGarfield); // envoie son état sous forme de tableau
  Serial.println("Garfield enyoyé position à Lasagne");
  }

  if (recoieEtat(tabLasagne)) 
  {
  envoieTrame(tabLasagne , sizeof(tabLasagne)); // envoie l'état de la lasagne via UART
    Serial.print("Position reçu bluetooth : ");
    Serial.print(tabLasagne[0]);
    Serial.print(", ");
    Serial.print(tabLasagne[1]);
    Serial.print(", ");
    Serial.print(tabLasagne[2]);
    Serial.print(", ");
    Serial.println(tabLasagne[3]);
    // Serial.println("Position de lasagne transmise via UART");
  }
  litUART(tabGarfield, sizeof(tabGarfield) +2); // lit la position de Garfield via UART
 
  Serial.print("Lecture de Garfield via UART : ");
  Serial.print(tabGarfield[0]);
  Serial.print(", "); 
  Serial.println(tabGarfield[1]);
  



}
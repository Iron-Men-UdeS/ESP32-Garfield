#include "BluetoothGarf.h"
#include "sPrint.h"

void printPosition (sPositionEtEtat printPos){ // Imprime la position reçue
    Serial.print("Position reçue : ");
    Serial.print(printPos.x);
    Serial.print(", ");
    Serial.print(printPos.y);
    Serial.print(", ");
    Serial.print(printPos.etatJeu);
    Serial.print(", ");
    Serial.println(printPos.GelerAutreRobot);
}

void printtat (sEtat printEtat){ // Imprime l'état reçu
    Serial.print("État reçu : ");
    Serial.print(printEtat.etatJeu);
    Serial.print(", ");
    Serial.println(printEtat.GelerAutreRobot);
}
#include <SPI.h>
#include <LoRa.h>
#include "DHT.h"
#define DHTPIN A0 

const int rs = 8, en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 3; /*Mention the pin number for LCD connection*/

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);/*Initialize LCD method*/

void setup() { /*this code starts the LoRa node 433E6 is the frequency specified on the module*/
  Serial.begin(9600);

  lcd.begin(16, 2);

  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {

    Serial.println("Starting LoRa failed!");

    while (1);
}
}
void loop() {

    // try to parse packet

  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    // received a paket

    Serial.print("Received packet '");

    // read packet

    while (LoRa.available()) {

      char incoming = (char)LoRa.read();

      if (incoming == 'c')

      {

        lcd.setCursor(0, 1);

      }

      else

      {

        lcd.print(incoming);

      }

    }
  
}

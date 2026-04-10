// sender code
#include <SPI.h>
#include <LoRa.h>

#define SS 10
#define RST 9
#define DIO0 2

void setup() {
  Serial.begin(9600);
  while (!Serial);

  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(915E6)) {   
    Serial.println("LoRa init failed!");
    while (1);
  }

  Serial.println("LoRa Sender Initialized");
}

void loop() {
  Serial.println("Sending packet...");

  LoRa.beginPacket();
  LoRa.print("Hello from Apurv");
  LoRa.endPacket();

  delay(2000);
}

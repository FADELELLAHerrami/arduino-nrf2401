#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<printf.h>

RF24 radio(9, 10);  // CE, CSN
byte addresses[][6] = {"1Node", "2Node"}; // Utilisez des octets au lieu de chaînes

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
  printf_begin();
  radio.printDetails();
}

void loop() {

}

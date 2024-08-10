#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

const int relayPins[] = {4, 5, 6, 7};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], LOW); // Ensure all relays are off initially
  }

  Serial.begin(9600);  // Initialize serial communication
  BTSerial.begin(9600); // Initialize Bluetooth serial communication
}

void loop() {
  if (BTSerial.available()) {
    char command = BTSerial.read();

    switch (command) {
      case '1':
        digitalWrite(relayPins[0], HIGH); // Turn relay 1 ON
        Serial.println("Relay 1 ON");
        break;
      case '2':
        digitalWrite(relayPins[0], LOW); // Turn relay 1 OFF
        Serial.println("Relay 1 OFF");
        break;
      case '3':
        digitalWrite(relayPins[1], HIGH); // Turn relay 2 ON
        Serial.println("Relay 2 ON");
        break;
      case '4':
        digitalWrite(relayPins[1], LOW); // Turn relay 2 OFF
        Serial.println("Relay 2 OFF");
        break;
      case '5':
        digitalWrite(relayPins[2], HIGH); // Turn relay 3 ON
        Serial.println("Relay 3 ON");
        break;
      case '6':
        digitalWrite(relayPins[2], LOW); // Turn relay 3 OFF
        Serial.println("Relay 3 OFF");
        break;
      case '7':
        digitalWrite(relayPins[3], HIGH); // Turn relay 4 ON
        Serial.println("Relay 4 ON");
        break;
      case '8':
        digitalWrite(relayPins[3], LOW); // Turn relay 4 OFF
        Serial.println("Relay 4 OFF");
        break;
      default:
        Serial.println("Invalid command");
        break;
    }
  }
}

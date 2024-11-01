// #include <SoftwareSerial.h>

// SoftwareSerial BTSerial(0, 1); // RX, TX

// // Define the relay pins
// const int relayPin1 = 4;
// const int relayPin2 = 5;
// const int relayPin3 = 6;
// const int relayPin4 = 7;

// void setup() {
//   // Set the relay pins as outputs and ensure relays are off initially
//   pinMode(relayPin1, OUTPUT);
//   pinMode(relayPin2, OUTPUT);
//   pinMode(relayPin3, OUTPUT);
//   pinMode(relayPin4, OUTPUT);
  
//   digitalWrite(relayPin1, HIGH);
//   digitalWrite(relayPin2, LOW);
//   digitalWrite(relayPin3, LOW);
//   digitalWrite(relayPin4, LOW);

//   Serial.begin(9600);  // Initialize serial communication
//   BTSerial.begin(9600); // Initialize Bluetooth serial communication
// }

// void loop() {
//   if (BTSerial.available()) {
//     char command = BTSerial.read();

//     switch (command) {
//       case '1':
//         digitalWrite(relayPin1, HIGH); // Turn relay 1 ON
//         Serial.println("Relay 1 ON");
//         break;
//       case '2':
//         digitalWrite(relayPin1, LOW); // Turn relay 1 OFF
//         Serial.println("Relay 1 OFF");
//         break;
//       case '3':
//         digitalWrite(relayPin2, HIGH); // Turn relay 2 ON
//         Serial.println("Relay 2 ON");
//         break;
//       case '4':
//         digitalWrite(relayPin2, LOW); // Turn relay 2 OFF
//         Serial.println("Relay 2 OFF");
//         break;
//       case '5':
//         digitalWrite(relayPin3, HIGH); // Turn relay 3 ON
//         Serial.println("Relay 3 ON");
//         break;
//       case '6':
//         digitalWrite(relayPin3, LOW); // Turn relay 3 OFF
//         Serial.println("Relay 3 OFF");
//         break;
//       case '7':
//         digitalWrite(relayPin4, HIGH); // Turn relay 4 ON
//         Serial.println("Relay 4 ON");
//         break;
//       case :
//         digitalWrite(relayPin4, LOW); // Turn relay 4 OFF
//         Serial.println("Relay 4 OFF");
//         break;
//       default:
//         Serial.println("Invalid command");
//         break;
//     }
//   }
// }


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

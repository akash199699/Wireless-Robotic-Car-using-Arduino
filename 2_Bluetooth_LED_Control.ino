#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX (connect to HC-05 TX, RX via divider)

char data;
int ledPin = 13;

void setup() {
  Serial.begin(9600);      // for Serial Monitor
  BT.begin(9600);          // for HC-05
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.println("Bluetooth LED Controller Ready");
}

void loop() {
  if (BT.available()) {
    data = BT.read();
    Serial.print("Received from BT: ");
    Serial.println(data);

    if (data == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    } else if (data == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
  }
}
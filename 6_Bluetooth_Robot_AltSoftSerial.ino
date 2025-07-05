#include <AFMotor.h>
#include <AltSoftSerial.h>

AltSoftSerial bluetooth; // RX = pin 8, TX = pin 9

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

bool isRunning = false;
unsigned long lastBluetoothActivity = 0;
unsigned long bluetoothTimeout = 5000;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Bluetooth Controlled Robot - Ready");

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();
    lastBluetoothActivity = millis();
    Serial.print("Command Received: ");
    Serial.println(command);

    if (command == 'F' && isRunning) moveForward();
    else if (command == 'B' && isRunning) moveBackward();
    else if (command == 'R' && isRunning) turnRight();
    else if (command == 'L' && isRunning) turnLeft();
    else if (command == 'S') stopMotors();
    else if (command == 'P') {
      isRunning = false;
      stopMotors();
      Serial.println("Robot Paused");
    } else if (command == 'I') {
      isRunning = true;
      Serial.println("Robot Started");
    } else Serial.println("Unknown Command");
  }

  if (millis() - lastBluetoothActivity > bluetoothTimeout) {
    Serial.println("No Bluetooth activity for 5 seconds.");
    stopMotors();
    lastBluetoothActivity = millis();
  }
}

void moveForward() {
  Serial.println("Moving Forward...");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void moveBackward() {
  Serial.println("Moving Backward...");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void turnRight() {
  Serial.println("Turning Right...");
  motor1.run(FORWARD);
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);
}
void turnLeft() {
  Serial.println("Turning Left...");
  motor1.run(BACKWARD);
  motor3.run(BACKWARD);
  motor2.run(FORWARD);
  motor4.run(FORWARD);
}
void stopMotors() {
  Serial.println("Motors Stopped...");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
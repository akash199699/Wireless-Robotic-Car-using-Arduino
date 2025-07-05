#include <AFMotor.h>
#include <SoftwareSerial.h>
// SoftwareSerial setup: RX on pin 10, TX on pin 11
SoftwareSerial bluetooth(10, 11);
// Initialize motors on terminals 1, 2, 3, and 4
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
bool isRunning = false;
unsigned long lastBluetoothActivity = 0;
unsigned long bluetoothTimeout = 5000;  // 5 seconds timeout
void setup() {
 Serial.begin(9600);          // For Serial Monitor
 bluetooth.begin(9600);       // For Bluetooth communication
 Serial.println("Bluetooth Controlled Robot - Ready");
// Set motor speeds (0 to 255)
motor1.setSpeed(200);
motor2.setSpeed(200);
motor3.setSpeed(200);
motor4.setSpeed(200);
}
void loop() {
// Continuously monitor Bluetooth connection
if (bluetooth.available()) {
char command = bluetooth.read();
lastBluetoothActivity = millis();  // Reset timeout timer
Serial.print("Command Received: ");
Serial.println(command);  // Debugging output to Serial Monitor
// Check and execute the command
if (command == 'F') {
if (isRunning) moveForward();
} else if (command == 'B') {
if (isRunning) moveBackward();
} else if (command == 'R') {
if (isRunning) turnRight();
} else if (command == 'L') {
 if (isRunning) turnLeft();
 } else if (command == 'S') {
 stopMotors();
 } else if (command == 'P') {
isRunning = false;
stopMotors();
Serial.println("Robot Paused");
} else if (command == 'I') {
isRunning = true;
Serial.println("Robot Started");
} else {
Serial.println("Unknown Command");
}
}
// Check for Bluetooth timeout
if (millis() - lastBluetoothActivity > bluetoothTimeout) {
Serial.println("No Bluetooth activity detected for 5 seconds.");
// Optionally, stop the motors or take other actions here
stopMotors();
lastBluetoothActivity = millis();  // Reset timeout timer
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
motor1.run(FORWARD);  // Left side motors forward
motor3.run(FORWARD);  // Left side motors forward
motor2.run(BACKWARD); // Right side motors backward
motor4.run(BACKWARD); // Right side motors backward
}
void turnLeft() {
Serial.println("Turning Left...");
motor1.run(BACKWARD); // Left side motors backward
motor3.run(BACKWARD); // Left side motors backward
motor2.run(FORWARD);  // Right side motors forward
motor4.run(FORWARD);  // Right side motors forward
}
void stopMotors() {
Serial.println("Motors Stopped...");
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
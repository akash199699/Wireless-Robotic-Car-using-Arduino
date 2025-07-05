#include <AFMotor.h>

// Motor mapping
AF_DCMotor motorRF(1); // Right Front - M1
AF_DCMotor motorLF(2); // Left Front  - M2
AF_DCMotor motorLB(3); // Left Back   - M3
AF_DCMotor motorRB(4); // Right Back  - M4

void setup() {
  Serial.begin(9600);
  Serial.println("4-Motor Drive Initialized");

  // Set speed (0–255)
  motorRF.setSpeed(200);
  motorLF.setSpeed(200);
  motorLB.setSpeed(200);
  motorRB.setSpeed(200);
}

void loop() {
  // Move Forward
  Serial.println("Moving Forward");
  motorRF.run(FORWARD);
  motorLF.run(FORWARD);
  motorLB.run(FORWARD);
  motorRB.run(FORWARD);
  delay(3000);

  // Stop
  Serial.println("Stop");
  stopAllMotors();
  delay(2000);

  // Move Backward
  Serial.println("Moving Backward");
  motorRF.run(BACKWARD);
  motorLF.run(BACKWARD);
  motorLB.run(BACKWARD);
  motorRB.run(BACKWARD);
  delay(3000);

  // Stop
  Serial.println("Stop");
  stopAllMotors();
  delay(2000);
}

void stopAllMotors() {
  motorRF.run(RELEASE);
  motorLF.run(RELEASE);
  motorLB.run(RELEASE);
  motorRB.run(RELEASE);
}
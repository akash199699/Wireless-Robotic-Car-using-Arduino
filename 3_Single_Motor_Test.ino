#include <AFMotor.h>

AF_DCMotor motor(1);

void setup() {
  motor.setSpeed(191); 
  Serial.begin(9600); 
  Serial.println("Motor Control Initialized");
}

void loop() {
  Serial.println("Motor 1 Forward");
  motor.run(FORWARD);
  delay(2000);
  
  Serial.println("Motor Stopped");
  motor.run(RELEASE);
  delay(1000);
  
  Serial.println("Motor 1 Backward");
  motor.run(BACKWARD);
  delay(2000);
  
  Serial.println("Motor Stopped");
  motor.run(RELEASE);
  delay(1000);
}
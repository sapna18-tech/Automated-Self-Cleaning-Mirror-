#include <Servo.h>

Servo servo1;
Servo servo2;

void sweepServo(Servo& s, int from, int to, int delayTime = 15) {
  if (from < to) {
    for (int pos = from; pos <= to; pos++) {
      s.write(pos);
      delay(delayTime);
    }
  } else {
    for (int pos = from; pos >= to; pos--) {
      s.write(pos);
      delay(delayTime);
    }
  }
}

void setup() {
  servo1.attach(9);   // First servo on pin 9
  servo2.attach(10);  // Second servo on pin 10

  // Move both servos to 0° initially
  servo1.write(0);
  servo2.write(0);
  delay(1000);  // Let them settle

  // === First Servo Movement ===
  sweepServo(servo1, 0, 180);  // Move up to 120
  sweepServo(servo1, 180, 0);  // Return to 0
  delay(1000);                 // Wait before starting second servo

  // === Second Servo Movement ===
  for (int i = 0; i < 3; i++) {
    sweepServo(servo2, 0, 180, 10);
    sweepServo(servo2, 180, 0, 10);
  }
  // sweepServo(servo2, 0, 180, 10);
  // Return second servo to 0° explicitly
  // servo2.write(0);
}

void loop() {
  // No repeat
}
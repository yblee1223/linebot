# 1 "/Users/iyongbin/Repository/linebot/src/motor/motor.ino"
// void setup()
// {
//     Serial.begin(9600);
// }

// void loop()
// {
//     int a = Serial.read();
//     if (a != -1){
//         Serial.println("Hello People");
//     }
//     Serial.println("Hello ino");
// }


// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void directionControl(int dir);
void speedControl();

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, 0x1);
  pinMode(enB, 0x1);
  pinMode(in1, 0x1);
  pinMode(in2, 0x1);
  pinMode(in3, 0x1);
  pinMode(in4, 0x1);

  // Turn off motors - Initial state
  digitalWrite(in1, 0x0);
  digitalWrite(in2, 0x0);
  digitalWrite(in3, 0x0);
  digitalWrite(in4, 0x0);

  Serial.begin(9600);
}

void loop() {
  Serial.println("state:");
  int dir = Serial.read(); // direcrtion
  directionControl(0);
  delay(4000);
  directionControl(1);
  delay(4000);
  directionControl(2);
  delay(4000);
  directionControl(3);
  delay(4000);
  // speedControl();
  // delay(1000);
}
// back
// forward
// turn left
// turn right

// This function lets you control spinning direction of motors
void directionControl(int dir) {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  // forward
  if (dir == 0){
    Serial.println("forward");
    digitalWrite(in1, 0x1);
    digitalWrite(in2, 0x0);
    digitalWrite(in3, 0x0);
    digitalWrite(in4, 0x1);
  }
  // backward
  else if (dir == 1){
    Serial.println("backward");
    digitalWrite(in1, 0x0);
    digitalWrite(in2, 0x1);
    digitalWrite(in3, 0x1);
    digitalWrite(in4, 0x0);
  }
  // turn right
  else if (dir == 2){
    Serial.println("turn right");
    digitalWrite(in1, 0x0);
    digitalWrite(in2, 0x1);
    digitalWrite(in3, 0x0);
    digitalWrite(in4, 0x1);
  }

  // turn left
  else if (dir == 3){
    Serial.println("turn left");
    digitalWrite(in1, 0x1);
    digitalWrite(in2, 0x0);
    digitalWrite(in3, 0x1);
    digitalWrite(in4, 0x0);
  }
  // stop
  else {
    Serial.println("stop");
    digitalWrite(in1, 0x0);
    digitalWrite(in2, 0x0);
    digitalWrite(in3, 0x0);
    digitalWrite(in4, 0x0);
  }
}

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(in1, 0x0);
  digitalWrite(in2, 0x1);
  digitalWrite(in3, 0x0);
  digitalWrite(in4, 0x1);

  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }

  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }

  // Now turn off motors
  digitalWrite(in1, 0x0);
  digitalWrite(in2, 0x0);
  digitalWrite(in3, 0x0);
  digitalWrite(in4, 0x0);
}

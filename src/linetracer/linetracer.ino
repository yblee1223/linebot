// InfraRed ray sensor
#define IRL 10
#define IRM 11
#define IRR 12

// Motor A connections Left
#define enA 9
#define in1 8 // ccw
#define in2 7 // cw

// Motor B connections Right
#define enB 3
#define in3 5 // cw
#define in4 4 // ccw

int speed = 50;


void linetracing();

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(9600);
}

void loop() 
{
    linetracing();

}

void linetracing()
{
    // move forward
    if (digitalRead(IRL)==HIGH && digitalRead(IRR)==HIGH){
        analogWrite(in2, 0);
        analogWrite(in1, speed);

        analogWrite(in3, speed);
        analogWrite(in4, 0);
    }

    // control left
    else if (digitalRead(IRL)==HIGH && digitalRead(IRR)==LOW){
        analogWrite(in2, 0);
        analogWrite(in1, speed);

        analogWrite(in3, 0);
        analogWrite(in4, speed);
    }

    // control right
    else if (digitalRead(IRL)==LOW && digitalRead(IRR)==HIGH){
        analogWrite(in2, speed);
        analogWrite(in1, 0);

        analogWrite(in3, speed);
        analogWrite(in4, 0);
    }

    // stop
    else if (digitalRead(IRL)==LOW && digitalRead(IRR)==LOW){
        analogWrite(in2, 0);
        analogWrite(in1, 0);

        analogWrite(in3, 0);
        analogWrite(in4, 0);
    }
}



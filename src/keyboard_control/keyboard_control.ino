// Motor A connections Left
#define enA 9
#define in1 8 // ccw
#define in2 7 // cw

// Motor B connections Right
#define enB 3
#define in3 5 // cw
#define in4 4 // ccw


void setup()
{
    // Set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    analogWrite(enA, 255);
    analogWrite(enB, 255);

    // Turn off motors - Initial state
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    Serial.begin(9600);
    Serial.println("Hello robot!");
}

void loop()
{
    int cmd = Serial.read(); // direcrtion
    if (cmd == 'w'){
        forward();
    }
    else if (cmd == 's'){
        backward();
    }
    else if (cmd == 'a'){
        left();
    }
    else if (cmd == 'd'){
        right();
    }
    else if (cmd == 'x'){
        stop();
    }
    // delay(1000);
}

// forward
void forward(){
    Serial.println("forward");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

// backward
void backward(){
    Serial.println("backward");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

// turn left
void left(){
    Serial.println("turn left");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

// turn right
void right(){
    Serial.println("turn right");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

// stop
void stop(){
    Serial.println("stop");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

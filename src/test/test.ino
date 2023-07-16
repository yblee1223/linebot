void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int a = Serial.read();
    if (a != -1){
        Serial.println("Hello People");
    }
    Serial.println("Hello ino");
}


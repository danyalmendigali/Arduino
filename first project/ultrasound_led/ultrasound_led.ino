int trig = 7;
int echo = 2;
int red = 5;
void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(red, OUTPUT);

    Serial.begin(9600);

}

void loop() {
    long dur, dist;
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    dur = pulseIn(echo, HIGH);
    dist = dur * 0.034 / 2;

    if(dist < 100){
        digitalWrite(red, HIGH);
        delay(500);
        digitalWrite(red, LOW);
        delay(500);
    }

}

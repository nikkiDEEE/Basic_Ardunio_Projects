int BUTTON1 = 9;
int BUTTON2 = 10;
int BUTTON3 = 11;
int BLUE = 3;
int GREEN = 5;
int RED = 6;

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}



void loop() {
  if (digitalRead(BUTTON1) == HIGH) {
    digitalWrite(BLUE, 1);
  } else {
    digitalWrite(BLUE, 0);
  }
  if (digitalRead(BUTTON2) == HIGH) {
    digitalWrite(RED, 1);
  } else {
    digitalWrite(RED, 0);
  }
  if (digitalRead(BUTTON3) == HIGH) {
    digitalWrite(GREEN, 1);
  } else {
    digitalWrite(GREEN, 0);
  }
}

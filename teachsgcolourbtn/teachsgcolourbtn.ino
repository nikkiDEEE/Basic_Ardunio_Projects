int BUTTON1 = 9;
int BUTTON2 = 10;
int BUTTON3 = 11;
int BLUE = 3;
int GREEN = 5;
int RED = 6;

const int trigPin = 12;
const int echoPin = 13;
float duration, distance;

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}



void loop() {



  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
//  delay(100);

  //  if (digitalRead(BUTTON1) == HIGH) {
  //    digitalWrite(BLUE, 1);
  //  } else {
  //    digitalWrite(BLUE, 0);
  //  }
  //  if (digitalRead(BUTTON2) == HIGH) {
  //    digitalWrite(RED, 1);
  //  } else {
  //    digitalWrite(RED, 0);
  //  }
  //  if (digitalRead(BUTTON3) == HIGH) {
  //    digitalWrite(GREEN, 1);
  //  } else {
  //    digitalWrite(GREEN, 0);
  //  }


  if (distance < 10.00) {
    digitalWrite(RED, 0);
    digitalWrite(GREEN, 0);
    digitalWrite(BLUE, 0);
  }

  if (distance >= 10.00 && distance < 20.00) {
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 0);
    digitalWrite(BLUE, 0);
  }

  if (distance >= 20.00 && distance < 30.00) {
    digitalWrite(RED, 0);
    digitalWrite(GREEN, 1);
    digitalWrite(BLUE, 0);
  }

  if (distance >= 30.00) {
    digitalWrite(RED, 0);
    digitalWrite(GREEN, 0);
    digitalWrite(BLUE, 1);
  }

  if (distance >= 40.00) {
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 1);
    digitalWrite(BLUE, 1);
  }

  delay(100);

  //
  //  if (digitalRead(BUTTON1) == HIGH) {
  //    digitalWrite(BLUE, 1);
  //  } else {
  //    digitalWrite(BLUE, 0);
  //  }
  //  if (digitalRead(BUTTON2) == HIGH) {
  //    digitalWrite(RED, 1);
  //  } else {
  //    digitalWrite(RED, 0);
  //  }
  //  if (digitalRead(BUTTON3) == HIGH) {
  //    digitalWrite(GREEN, 1);
  //  } else {
  //    digitalWrite(GREEN, 0);
  //  }
}

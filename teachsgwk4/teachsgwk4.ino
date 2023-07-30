const int A = 7;
const int B = 6;
const int C = 4;
const int D = 3;
const int E = 2;
const int F = 8;
const int G = 9;

int random_int = 0;
int previous_random_int = -1; 
int btn_pressed_prev = 0;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, OUTPUT); // Set buzzer - pin 13 as an output
  Serial.begin(9600);
}

void loop() {
  int pusshed = digitalRead(12);
  if (pusshed == HIGH) 
  {
    random_int = random(1, 7);
    one();
    delay(20);
    two();
    delay(20);
    three();
    delay(20);
    four();
    delay(20);
    five();
    delay(20);
    six();
    delay(20);
    btn_pressed_prev = 1; 
  }
  else
  {
    switch (random_int)
    {
      case 1: one();
        break;
      case 2: two();
        break;
      case 3: three();
        break;
      case 4: four();
        break;
      case 5: five();
        break;
      case 6: six();
        break;
    }
    delay(200);
    
    if (previous_random_int == random_int) {
      sound_buzzer();
      previous_random_int = -1;
    }  
    
    if (btn_pressed_prev) {
      previous_random_int = random_int;  
      random_int = 0;
    }
    
    btn_pressed_prev = 0; 
  }
}


void sound_buzzer() {
  tone(13, 1000); // Send 1KHz sound signal...
  delay(500);        // ...for 1 sec
  noTone(13);     // Stop sound...
  delay(500);        // ...for 1sec  
}


void one() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void two() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void three() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void four() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void five() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void six() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

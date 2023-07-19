const int BUTTON_IN = 2;
const int PIN_RED = 5;
const int PIN_GREEN = 6;
const int PIN_BLUE = 9;
const int PIN_YELLOW = 8;

volatile bool buttonPressed = false;
bool isRed = false;

void setup() {
  pinMode(BUTTON_IN, INPUT_PULLUP);   // Enable internal pull-up resistor for the button
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(BUTTON_IN), buttonISR, FALLING);
}

void loop() {
  RGBColor();
  delay(250);
}

void RGBColor() {
  int randomNumber = random(3);

  if (randomNumber == 0) {
    // RED
    analogWrite(PIN_RED, 255);
    analogWrite(PIN_GREEN, 0);
    analogWrite(PIN_BLUE, 0);
    isRed = true;
  } else if (randomNumber == 1) {
    // GREEN
    analogWrite(PIN_RED, 0);
    analogWrite(PIN_GREEN, 255);
    analogWrite(PIN_BLUE, 0);
    isRed = false;
  } else if (randomNumber == 2) {
    // BLUE
    analogWrite(PIN_RED, 0);
    analogWrite(PIN_GREEN, 0);
    analogWrite(PIN_BLUE, 255);
    isRed = false;
  }
}

void buttonISR() {
  buttonPressed = true;
  if (isRed && buttonPressed) {
    digitalWrite(PIN_YELLOW, HIGH);
    buttonPressed=false;
  } else {
    digitalWrite(PIN_YELLOW, LOW);
    buttonPressed=false;
  }
}

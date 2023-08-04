#include <Arduino.h>

// Define the pins for the LEDs and buttons
const int ledPins[] = {2, 3, 4, 5};
const int buttonPins[] = {6, 7, 8, 9};

// Define the pattern sequence
const int sequence[] = {0, 1, 2, 3};

// Define the length of the pattern
const int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);

void setup() {
  // Initialize LED pins as output
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Initialize button pins as input with internal pull-up resistors
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Initialize random seed based on analog pin noise
  randomSeed(analogRead(0));

  // Blink all LEDs to indicate the start of the game
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  // Generate a new random sequence for each round
  int gameSequence[sequenceLength];
  for (int i = 0; i < sequenceLength; i++) {
    gameSequence[i] = random(0, 4);
  }

  // Show the generated sequence to the player
  for (int i = 0; i < sequenceLength; i++) {
    digitalWrite(ledPins[gameSequence[i]], HIGH);
    delay(500);
    digitalWrite(ledPins[gameSequence[i]], LOW);
    delay(100);
  }

  // Wait for the player to repeat the sequence
  int playerSequence[sequenceLength];
  int playerScore = 0;

  for (int i = 0; i < sequenceLength; i++) {
    // Check which button the player presses
    int pressedButton = -1;
    while (pressedButton == -1) {
      for (int j = 0; j < 4; j++) {
        if (digitalRead(buttonPins[j]) == LOW) {
          pressedButton = j;
          break;
        }
      }
    }

    // Light up the corresponding LED for the pressed button
    digitalWrite(ledPins[pressedButton], HIGH);
    delay(200);
    digitalWrite(ledPins[pressedButton], LOW);

    // Store the player's input in the sequence
    playerSequence[i] = pressedButton;

    // Check if the player's input matches the game sequence
    if (playerSequence[i] != gameSequence[i]) {
      // Player loses the game
      // Flash all LEDs rapidly to indicate the end of the game
      for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 4; j++) {
          digitalWrite(ledPins[j], HIGH);
        }
        delay(100);
        for (int j = 0; j < 4; j++) {
          digitalWrite(ledPins[j], LOW);
        }
        delay(100);
      }

      // Restart the game
      break;
    }

    // Increment player score for each correct button press
    playerScore++;

    // Pause briefly before displaying the next button in the sequence
    delay(200);
  }

  // Player completed the sequence successfully
  // Flash all LEDs to indicate the end of the round
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(500);
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  
  // Display player score on LEDs (LEDs 1-4 represent the score in binary)
  for (int i = 0; i < playerScore; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(2000);
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

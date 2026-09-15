#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

// LED pins matching ATtiny84 arduino pinout
const uint8_t LED_PINS[3] = {5, 6, 7};

// Button pins MATCH ORDER TO BUTTONS OR GAME WILL NOT WORK
const uint8_t BUTTON_PINS[3] = {2, 3, 4}; // Order matters to match LED outputs

// Game constants
const uint8_t Max_Sequence = 15;
const unsigned long LED_ON_TIME = 300;
const unsigned long LED_OFF_TIME = 150;

// Game sequence
uint8_t sequence[Max_Sequence];

// Game states
enum GameState {
  START,
  Show_Sequence,
  Player_Input,
  Game_Over,
  WIN
};

GameState gameState = START;
uint8_t sequenceLength = 1;

// Empty ISR wakes the mcu up when a pin is changed 
ISR(PCINT0_vect) {
}

void setup() {
  for (uint8_t i = 0; i < 3; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  for (uint8_t i = 0; i < 3; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(0));

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  GIMSK |= (1 << PCIE0);                                    // enable pin-change interrupts on PORTA
  PCMSK0 |= (1 << PCINT2) | (1 << PCINT3) | (1 << PCINT4);  // watch pins 2, 3, 4
}
//state machine inside loop controls game 
void loop() {
  switch (gameState) {
    case START:
      sequenceLength = 1;
      addToSequence();
      gameState = Show_Sequence;
      break;

    case Show_Sequence:
      showSequence();
      gameState = Player_Input;
      break;

    case Player_Input:
      if (getPlayerInput()) {
        if (sequenceLength >= Max_Sequence) {
          gameState = WIN;
        } else {
          sequenceLength++;
          addToSequence();
          gameState = Show_Sequence;
        }
      } else {
        gameState = Game_Over;
      }
      break;

    case Game_Over:
      gameOver();
      gameState = START;
      break;

    case WIN:
      winGame();
      gameState = START;
      break;
  }
}

void flashLED(uint8_t led) {
  digitalWrite(LED_PINS[led], HIGH);
  delay(LED_ON_TIME);
  digitalWrite(LED_PINS[led], LOW);
  delay(LED_OFF_TIME);
}

int8_t waitForButton() {
  while (true) {
    bool anyPressed = false;
    for (uint8_t i = 0; i < 3; i++) {
      if (digitalRead(BUTTON_PINS[i]) == LOW) anyPressed = true;
    }

    if (!anyPressed) {
      sleep_mode();      // Waits for input to wake it
      continue;
    }
// button debouncing function
    for (uint8_t i = 0; i < 3; i++) {
      if (digitalRead(BUTTON_PINS[i]) == LOW) {
        delay(20);
        if (digitalRead(BUTTON_PINS[i]) != LOW) continue; // was noise, not a real press

        while (digitalRead(BUTTON_PINS[i]) == LOW);        // wait for release
        delay(20);                                          // debounce the release

        return i;
      }
    }
  }
}

void addToSequence() {
  sequence[sequenceLength - 1] = random(0, 3);
}

void showSequence() {
  for (uint8_t i = 0; i < sequenceLength; i++) {
    flashLED(sequence[i]);
  }
}

bool getPlayerInput() {
  for (uint8_t i = 0; i < sequenceLength; i++) {
    int8_t playerInput = waitForButton();
    if (playerInput != sequence[i]) {
      return false;
    }
  }
  return true;
}
// sequence showing game was lost
void gameOver() {
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(LED_PINS[i], HIGH);
  }
  delay(500);
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
  delay(500);
}
// Victory celebration for if the game is beaten
void winGame() {
  for (uint8_t i = 0; i < 3; i++) {
    flashLED(i);
  }
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(LED_PINS[i], HIGH);
  }
  delay(500);
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
}
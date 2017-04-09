#include "TimerOne.h"

// -----------------------------------------------------------------------------
// PORTD: Data Bus
// Digital  0 = PORTD 0
// reserved for serial

// Digital  1 = PORTD 1
// reserved for serial

// Digital  2 = PORTD 2
#define PIN_RED 2

// Digital  3 = PORTD 3
#define PIN_GREEN 3

// Digital  4 = PORTD 4
#define PIN_BLUE 4

// Digital  5 = PORTD 5
#define PIN_CLOCK 5

// Digital  6 = PORTD 6
#define PIN_BRIGHT 6

// Digital  7 = PORTD 7
#define PIN_RESET 7

// -----------------------------------------------------------------------------
// PORTB: Select lines
// Digital  8 = PORTB 0
#define PIN_SELECT1 0

// Digital  9 = PORTB 1
#define PIN_SELECT2 1

// Digital 10 = PORTB 2
#define PIN_SELECT3 2

// Digital 11 = PORTB 3
#define PIN_SELECT4 3

// Digital 12 = PORTB 4
// not used

// Digital 13 = PORTB 5
// not used

// -----------------------------------------------------------------------------
#define ROWS 16 
#define COLS 16
#define PANELS 4

const int panelSelect[] = {
  PIN_SELECT1,
  PIN_SELECT2,
  PIN_SELECT3,
  PIN_SELECT4
};

// 0x01: green
// 0x02: red
byte framebuffer[] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

int rowOffset = 0;
int panelOffset = 0;
int colOffset = 0;
int pixelCounter = 0;

//x |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
//x &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.

void setup() {
  initializeFramebuffer();
  initializePins();
  resetPins();
  initializePanels();
  //setupTimer();
  //setupSerial();
}

void initializeFramebuffer() {
  for(int i = 0; i < 1024; i++) {
    framebuffer[i] = 0x02;
  }
}

void initializePins() {
  DDRD |= ((1<<PIN_RED) | (1<<PIN_GREEN) | (1<<PIN_CLOCK) | (1<<PIN_BRIGHT) | (1<<PIN_RESET));
  DDRB |= ((1<<PIN_SELECT1) | (1<<PIN_SELECT2) | (1<<PIN_SELECT3) | (1<<PIN_SELECT4));
}

void resetPins() {
  PORTD = B00000000;
  PORTB = B00000000;
}

void initializePanels() {
  // reset and bright: high
  PORTD |= ((1<<PIN_RESET) | (1<<PIN_BRIGHT));
  // reset and bright: low
  PORTD &= ~((1<<PIN_RESET) | (1<<PIN_BRIGHT));
}

void setupTimer() {
  // 30fps
  Timer1.initialize(33333);
  Timer1.attachInterrupt(redrawPanels);
}

void setupSerial() {
  // asd
  Serial.begin(38400);
}

//TODO debug redrawPanels
// IO pins auf high/low setyen und ueber oszi messen
void redrawPanels() {
  // write each panel sequentially
  for(int panel = 0; panel < PANELS-1; panel++) {
    // panel select high
    PORTB |= (1<<panelSelect[panel]);
    // bright for panel high
    PORTD |= (1<<PIN_BRIGHT);
    
    // pixel data
    for(int col = 0; col < COLS-1; col++) {
      for(int row = 0; row < ROWS-1; row++) {
        rowOffset = row*(PANELS*COLS);
        panelOffset = panel*COLS;
        colOffset = rowOffset + panelOffset + col;

        PORTD &= ~((1 << PIN_RED) | (1 << PIN_GREEN));
        if(framebuffer[colOffset] & 0x01) {
          PORTD |= (1<<PIN_GREEN);
        }
        if(framebuffer[colOffset] & 0x02) {
          PORTD |= (1<<PIN_RED);
        }

        // clock high, then low
        PORTD |= (1<<PIN_CLOCK);
        PORTD &= ~(1<<PIN_CLOCK);
      }
    }

    // panel select+bright low
    PORTB &= ~(1<<panelSelect[panel]);
    PORTD &= ~(1<<PIN_BRIGHT);
  }
}

void loop() {
  // update framebuffer via serial console
  //if (Serial.available() > 0) {
  //  framebuffer[pixelCounter++] = Serial.read();
  //  if(pixelCounter >= 1024) {
  //    pixelCounter = 0;
  //  }
  //}
  redrawPanels();
}

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
// not used

// Digital  9 = PORTB 1
#define PIN_SELECT1 1

// Digital 10 = PORTB 2
#define PIN_SELECT2 2

// Digital 11 = PORTB 3
#define PIN_SELECT3 3

// Digital 12 = PORTB 4
#define PIN_SELECT4 4

// Digital 13 = PORTB 5
// not used

// -----------------------------------------------------------------------------
#define ROWS 16 
#define COLS 16
#define PANELS 4

const int panelSelectPin[] = {
  PIN_SELECT1,
  PIN_SELECT2,
  PIN_SELECT3,
  PIN_SELECT4
};

// 0x01: green
// 0x02: red
byte framebuffer[] = {
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00,
  0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00,
  0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01,     0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
};

int rowOffset = 0;
int panelOffset = 0;
int colOffset = 0;
int panel = 0;
int row = 0;
int col = 0;
int pixelCounter = 0;

//x |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
//x &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.

void setup() {
  initializePins();
  initializePanels();
  redrawPanels();
  //setupTimer();
  setupSerial();
}

void initializePins() {
  DDRD |= ((1<<PIN_RED) | (1<<PIN_GREEN) | (1<<PIN_CLOCK) | (1<<PIN_BRIGHT) | (1<<PIN_RESET));
  DDRB |= ((1<<PIN_SELECT1) | (1<<PIN_SELECT2) | (1<<PIN_SELECT3) | (1<<PIN_SELECT4));
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
  Timer1.initialize((1/30)*1000000);
  Timer1.attachInterrupt(redrawPanels);
}

void setupSerial() {
  Serial.begin(115200);
  Serial.println("Ready");
}

void redrawPanels() {
  for(panel = 0; panel < PANELS; panel++) {
    redrawPanel(panel);
  }
}

void redrawPanel(int panel) {
  // panel select high
  PORTB |= (1<<panelSelectPin[panel]);

  for(row = 0; row < ROWS; row++) {  
    for(col = 0; col < COLS; col++) {
      rowOffset = row*(PANELS*COLS);
      panelOffset = panel*COLS;
      colOffset = rowOffset + panelOffset + col;

      if(framebuffer[colOffset] & 0x01) {
        PORTD |= (1<<PIN_GREEN);
      }
      if(framebuffer[colOffset] & 0x02) {
        PORTD |= (1<<PIN_RED);
      }

      // clock high, then low
      PORTD |= (1<<PIN_CLOCK);
      PORTD &= ~(1<<PIN_CLOCK);

      // reset red and green data
      PORTD &= ~((1 << PIN_RED) | (1 << PIN_GREEN));
    }
  }

  // panel select low
  PORTB &= ~(1<<panelSelectPin[panel]);
}

void loop() {
  if(Serial.available()) {
    updateFramebufferFromSerial();
  }
  redrawPanels();
}

void updateFramebufferFromSerial() {
  char inByte = Serial.read();
  switch(inByte) {
    case 'i':
      reset();
      Serial.print("reset");
      break;
    case 'o':
      update(0x00);
      break;
    case 'g':
      update(0x01);
      break;
    case 'r':
      update(0x02);
      break;
    case 'y':
      update(0x03);
      break;
    default:
      break;
  }
}

void reset() {
  pixelCounter = 0;
  for(int i = 0; i < 1024; i++) {
    framebuffer[i] = 0;
  }
}

void update(byte value) {
    framebuffer[pixelCounter] = value;
    pixelCounter++;
    if(pixelCounter >= 1024) {
      pixelCounter = 0;
    }
}

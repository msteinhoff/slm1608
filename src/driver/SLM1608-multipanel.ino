//20 - 2 - brtclk
//25 - 3 - brtwrt (always high)
//30 - 4 - select (always high after reset)
//35 - 5 - red
//40 - 6 - green
//45 - 7 - clock
//50 - 8 - bright
//55 - 9 - reset

// 1: 30 select
// 2: 55 reset
// 3: 45 clock
// 4: 50 bright
#include "TimerOne.h"

#define PIN_RED 2
#define PIN_GREEN 3
#define PIN_CLOCK 5
#define PIN_BRIGHT 6
#define PIN_RESET 7

#define PIN_SELECT1 8
#define PIN_SELECT2 9
#define PIN_SELECT3 10
#define PIN_SELECT4 11

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

void setup() {
  for(int i = 0; i < 1024; i++) {
    framebuffer[i] = 0x03;
  }
  
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_BRIGHT, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_SELECT1, OUTPUT);
  pinMode(PIN_SELECT2, OUTPUT);
  pinMode(PIN_SELECT3, OUTPUT);
  pinMode(PIN_SELECT4, OUTPUT);

  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GREEN, LOW);
  digitalWrite(PIN_CLOCK, LOW);
  digitalWrite(PIN_BRIGHT, LOW);  
  digitalWrite(PIN_RESET, LOW);
  digitalWrite(PIN_SELECT1, LOW);
  digitalWrite(PIN_SELECT2, LOW);
  digitalWrite(PIN_SELECT3, LOW);
  digitalWrite(PIN_SELECT4, LOW);

  digitalWrite(PIN_RESET, HIGH);
  digitalWrite(PIN_BRIGHT, HIGH);
  digitalWrite(PIN_RESET, LOW);
  digitalWrite(PIN_BRIGHT, LOW);
  
  // 30fps
  //Timer1.initialize(33333);
  //Timer1.attachInterrupt(updateDisplay);
  
  Serial.begin(38400);
}


//TODO debug updateDisplay
// IO pins auf high/low setyen und ueber oszi messen
void updateDisplay() {
  // write each panel sequentially
  for(int panel = 0; panel < PANELS-1; panel++) {
    digitalWrite(panelSelect[panel], HIGH);
    digitalWrite(PIN_BRIGHT, HIGH);
    
    // write individual panel data
    for(int row = 0; row < ROWS-1; row++) {
      for(int col = 0; col < COLS-1; col++) {
        rowOffset = row*(PANELS*COLS);
        panelOffset = panel*COLS;
        colOffset = rowOffset + panelOffset + col;
        digitalWrite(PIN_GREEN, framebuffer[colOffset] & 0x01 ? HIGH : LOW);
        digitalWrite(PIN_RED, framebuffer[colOffset] & 0x02 ? HIGH : LOW);
        digitalWrite(PIN_CLOCK, HIGH);
        digitalWrite(PIN_CLOCK, LOW);
      }
    }

    digitalWrite(panelSelect[panel], LOW);
    digitalWrite(PIN_BRIGHT, LOW);
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
  updateDisplay();
}

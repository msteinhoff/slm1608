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

#define PIN_BRTCLK 2
#define PIN_BRTWRT 3
#define PIN_SELECT 4
#define PIN_RED 5
#define PIN_GREEN 6
#define PIN_CLOCK 7
#define PIN_BRIGHT 8
#define PIN_RESET 9

void setup() {
  //pinMode(PIN_BRTCLK, OUTPUT);
  //pinMode(PIN_BRTWRT, OUTPUT);
  pinMode(PIN_SELECT, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_BRIGHT, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  //digitalWrite(PIN_BRTCLK, LOW);
  //digitalWrite(PIN_BRTWRT, LOW);
  digitalWrite(PIN_SELECT, LOW);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GREEN, LOW);
  digitalWrite(PIN_CLOCK, LOW);
  digitalWrite(PIN_BRIGHT, LOW);  
  digitalWrite(PIN_RESET, LOW);

  digitalWrite(PIN_RESET, HIGH);
  digitalWrite(PIN_BRIGHT, HIGH);
  digitalWrite(PIN_RESET, LOW);
  digitalWrite(PIN_BRIGHT, LOW);
  digitalWrite(PIN_SELECT, HIGH);
}

void loop() {
      
  for(int row = 0; row < 16; row++) {
      for(int col = 0; col < 16; col++) {
        digitalWrite(PIN_GREEN, LOW);
        digitalWrite(PIN_RED, LOW);
        if(row % 2 == 0) {
          if(col % 2 == 0) {
            digitalWrite(PIN_GREEN, HIGH);
          }
        } else {
          if(col % 2 != 0) {
            digitalWrite(PIN_GREEN, HIGH);
          }
        }
        tick();
  digitalWrite(PIN_BRIGHT, HIGH);
  delay(10);
  digitalWrite(PIN_BRIGHT, LOW);
  delay(10);
      }
  }

}

void tick() {
        digitalWrite(PIN_CLOCK, HIGH);
        digitalWrite(PIN_CLOCK, LOW);
}

#include <avr/io.h>
#include <avr/interrupt.h> 
#include <stdint.h>


#define F_CPU 8000000UL
#include <util/delay.h> 

#define BAUD        38400UL
#define UBRR_BAUD   ((F_CPU/(16UL*BAUD))-1)


#define red  0
#define green  1
#define clock  2
#define bright  3
#define reset  4
#define brtwrt  6
#define brtclk  5

#define cres  1
#define cclk  0

volatile uint16_t datar[144];
volatile uint16_t datag[144];

volatile uint8_t i;

volatile uint8_t col = 0;
volatile uint8_t row = 0;

volatile uint8_t module = 0;


void slm1608()
{
  PORTC &= ~(1<<reset); //reset
  PORTC |= (1<<bright);
  PORTC |= (1<<reset);
  PORTC &= ~(1<<bright);
  PORTC &= ~(1<<reset);

  PORTC |= (1<<bright); //bright auf high

  PORTC |= (1<<brtwrt); //brgwrt an

  for(col = 0; col < 16; col++){
    for(row = 0; row < 16; row++){
      if( (datar[(module*16)+col]) & (1 << row) ){
        PORTC |= (1<<red);
      }
      if( (datag[(module*16)+col]) & (1 << row) ){
        PORTC |= (1<<green);
      }

      PORTC |= (1<<clock);      
      PORTC |= (1<<brtclk);
      PORTC &= ~(1<<brtclk);
      PORTC &= ~(1<<clock);

      PORTC &= ~(1<<red);
      PORTC &= ~(1<<green);
    }

    PORTC &= ~(1<<bright);
    _delay_us(200);
    PORTC |= (1<<bright);
  }

  if(module == 2)
  {
    PORTA |= (1<<cres);  //reset high
    PORTA &= ~(1<<cres); //reset low

    for(i = 0; i<6; i++){
      PORTA &= ~(1<<cclk); //clock low
      PORTA |= (1<<cclk);  //clock high
    }

    datar[3] = 2134;

    module = 0;
  }

  PORTA &= ~(1<<cclk); //clock low
  PORTA |= (1<<cclk);  //clock high

  module ++;


}


void uart_init(void)
{
    // Baudrate einstellen (Normaler Modus)
    UBRRH = (unsigned char) (UBRR_BAUD>>8);
    UBRRL = (unsigned char) (UBRR_BAUD & 0x0ff);

    // Aktivieren des Empfängers, des Senders und des "Daten empfangen"-Interrupts
    UCSRB = (1<<RXCIE)|(1<<RXEN)|(1<<TXEN);

    // Einstellen des Datenformats: 8 Datenbits, 1 Stoppbit
    UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}


int main(void)
{
  uart_init();


    sei();

  DDRA = 0xFF; //4017
  DDRC = 0xFF; //Data SLM1608

  PORTC = 0;
  PORTA = 0;

  _delay_ms(1);
  PORTA |= (1<<cres);  //reset high
  _delay_ms(1);
  PORTA &= ~(1<<cres); //reset low
  _delay_ms(1);

  for(i = 0; i<144; i++){
    datar[i] = 0;
  }

  for(i = 0; i<6; i++){
    PORTA |= (1<<cclk);  //clock high
    _delay_ms(1);
    PORTA &= ~(1<<cclk); //clock low
    _delay_ms(1);
  }

  
  datar[0] = 51503;
  datag[2] = 65535;

  module = 0;

  while(1){
    slm1608();
  }

}


ISR(USART_RXC_vect)  //Interrupt für UARTSIG_UART_RECV
{

  unsigned char buffer;

    // Daten aus dem Puffer lesen ...
    buffer = UDR;

    // ... warten bis der Sendepuffer leer ist ...
    while ( !( UCSRA & (1<<UDRE)) )
        ;

    datar[5] = 3123 // wenn ein Zeichen gekommen ist, wird ROT[5] auf 3123 gesetzt

  UDR = 0x30; // 0 senden 
}

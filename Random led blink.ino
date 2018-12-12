/*
	Konsta Siekkeli TTV17SA
*/


#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>

int rand_init(void)
{
  //Initialize ADC and seed the rand() function
  ADMUX = 0b11000000;
  ADCSRA = 0b10100100;

  ADCSRA |= 1<<ADSC;
  _delay_ms(10);
  srand((unsigned)ADC);

  ADCSRA &= ~(1<<ADSC);
  ADCSRA &= ~(1<<ADEN);
  return 0;
}

int ledControl(void)
{
 int randNum = rand() % 8+1;

 PORTD = 0xFF;
 switch(randNum)
 {
  case 1:
    PORTD &= ~(1<<PORTD0); 
    break;
  case 2:
    PORTD &= ~(1<<PORTD1);
    break;
  case 3:
    PORTD &= ~(1<<PORTD2);
    break;
  case 4:
    PORTD &= ~(1<<PORTD3);
    break;
  case 5:
    PORTD &= ~(1<<PORTD4);
    break;
  case 6:
    PORTD &= ~(1<<PORTD5);
    break;
  case 7:
    PORTD &= ~(1<<PORTD6);
    break;
  case 8:
    PORTD &= ~(1<<PORTD7);
    break;    
  default:
    //Lights pin13 connected led if some error
    PORTB |= (1<<PORTB5);
    break;
 }
 _delay_ms(2000); 
}

int main(void)
{ 
  rand_init();
  //Defining whole PortD and PortB5 as outputs
  DDRD = 0xFF;
  PORTD = 0xFF;
  
  DDRB |= (1<<PORTB5);
  PORTB &= ~(1<<PORTB5);
  //LED test. Keeps all leds ON to test are them functional
  _delay_ms(1000); 
  while(1)
  {
    ledControl();
  }
}

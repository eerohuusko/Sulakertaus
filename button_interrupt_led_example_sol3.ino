/*****************************************************************************************
Niko Kyllönen                                                          2.10.2018
Henna Korhonen
Niko Friman
TTV17SA
SULAUTETTUJEN JÄRJESTELMIEN OHJELMOINTI

ARDUINO UNO / ATMEGA328
******************************************************************************************/
/*************************************INCLUDES********************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
/*************************************DEFINES*********************************************/
#define BUTTON1 PD2
#define BUTTON2 PD3
#define LED1 PD7
#define LED2 PD6
/*************************************FUNCTIONS*******************************************/
ISR(INT0_vect) // Ulkoinen keskeytys INT0
{
  PORTD |= (1<<LED1); //Sytytä LEDI
  PORTD &= ~(1<<LED2); //Sammuta LEDI
}
ISR(INT1_vect) // Ulkoinen keskeytys INT1
{
  PORTD |= (1<<LED2);
  PORTD &= ~(1<<LED1);
}
/*************************************MAIN***********************************************/
int main(void)
{
  DDRD &= ~(1<<BUTTON1)|(1<<BUTTON2); // Sisään tulot
  DDRD |= (1<<LED1)|(1<<LED2); //Lähdöt
  
  PORTD &= ~((1<<LED1)|(1<<LED2)); //Sammuttaa Ledit
  
  EIMSK |= (1<<INT0)|(1<<INT1); // INT0 sallittu
  EICRA |= (1<<ISC10)|(1<<ISC00); // muutos generoi keskeytyksen
  sei(); // globaali keskeytys sallittu

  while(1)
  {
  }
}


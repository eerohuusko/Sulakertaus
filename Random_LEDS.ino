#include <avr/io.h>
#include <util/delay.h>

#define LEDD PORTD //D6, D7
#define LEDB PORTB //D8, D9, D10, D11, D12, D13

int main(void)
{
  randomSeed(analogRead(0));
  
  DDRD |= 0xC0;   //0b11000000
  DDRB |= 0x3F;   //0b00111111

  //Ledit HIGH = Sammuu
  LEDD |= 0xC0;   //0b11000000
  LEDB |= 0x3F;   //0b00111111
  
  while(1)
  {
    int R = random(8);
    
    if (R > 5) LEDD &= ~(1<<R); //Bitit 6 ja 7 D portista LOW jos random on > 5
    else LEDB &= ~(1<<R);       //Bitit 5,4,3,2,1,0 B portista LOW jos random on < 6
    
    _delay_ms(10); //Viivettä

    //Ledit HIGH = Sammuu
    LEDD |= 0xC0; //0b11000000
    LEDB |= 0x3F; //0b00111111
  }
}
// Kyl tää aika helppo oli...

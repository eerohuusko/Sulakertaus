#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define pin6 (1 << PD6) //green led
#define pin7 (1 << PD7) //yellow led

ISR (PCINT2_vect)
{
    static uint8_t pd6 = 0;
    static uint8_t pd7 = 0;
    uint8_t tmp6;
    uint8_t tmp7;

    // Get the current state of the two pins
    tmp6 = (PIND & (1 << PD6));
    tmp7 = (PIND & (1 << PD7));

    if (tmp6 != pd6)
    {
        // PD6 toggled, save current value and
        // toggle associated LED
        pd6 = tmp6;
        PORTB ^= (1 << PB0);
        PORTB &= ~(1 << PB1);
       
        
    }

    if (tmp7 != pd7)
    {
        // PD7 toggled, save current value and
        // toggle associated LED
        pd7 = tmp7;
        PORTB ^= (1 << PB1);
        PORTB &= ~(1 << PB0);
               
    }
}

int main()
{
    // Set PD6 and PD7 as inputs
    DDRD &= ~((1 << PD6) | (1 << PD7));

    // Set PB0 and PB1 as output (LED indicators)
    DDRB |= (1 << PB0) | (1 << PB1);

    // Set Leds off state

    PORTB &= ~(1 << PB0) | (1 << PB1);

    // Specify pins PD6 and PD7 as interrupt
    // sources. See data sheet 12.2.6
    PCMSK2 |= (1 << PCINT23) | (1 << PCINT22);

    // enable pin change interrupt for pins
    // PCINT23 - 16
    PCICR |= (1 << PCIE2);

    // Enable interrupts globaly
    sei ();

    for (;;)
    {
      //empty
    }
}


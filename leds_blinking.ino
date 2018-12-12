//Example:

  //  PORTD &= ~(1<<PD5);     // Put PortD bit 5 LOW

//This code is for excersizing bit operations to manage digital output.

  //  leds_blinking.ino

    // 
    // Description:

    // Each Arduino pin 5, 6 and 7 pin is connected to a LED.

    // This code is for excersizing bit operations to manage digital output.

    // AVR-GCC uses bit operations heavily to interface I/O.

    // Atmega8 PortD bit | Arduino pin

    // 5                 | 5

    // 6                 | 6

    // 7                 | 7

    #include <avr/io.h>

    #include <util/delay.h>

    void delay(int); //function prototype
    
  //Main loop begins here
  
    int main(void){

    // put PortD bit 5, 6 and 7 as output

    DDRD = (1<<PD5)|(1<<PD6)|(1<<PD7);

    for(;;){

    //***** Exercising HIGH and LOW
    /*
     * Switch off bits)

DDRB = 0b11111111;

DDRB &= ~(1<<5);

-> DDRB = 11101111

Example:

    PORTD &= ~(1<<PD5);     // Put PortD bit 5 LOW
*/
     

    PORTD |= (1<<PD5);     // Put PortD bit 5 HIGH

    delay(1000);

    PORTD = PORTD | (1<<PD6) | (1<<PD7);     // Put PortD bit 6 and 7 HIGH

    delay(1000);

    PORTD &= ~(1<<PD5);     // Put PortD bit 5 LOW

    delay(1000);

    PORTD = PORTD & ~(1<<PD6) & ~(1<<PD7);     // Put PortD bit 6 and 7 LOW

    delay(3000);

    //***** Exercising TOGGLE
    /*
     * ^ – bitwise Inclusive OR (Toggle bits on/off)

DDRB = 0b0001001;

DDRB ^= ob00010000;

-> DDRB = 00000001

Example:

    PORTD ^= (1<<PD6);     // Toggle PortD bit 6
*/
     

    PORTD ^= (1<<PD6); // Toggle PortD bit 6

    delay(1000);

    PORTD = PORTD ^ (1<<PD5) ^ (1<<PD7); // Toggle PortD bit 5 and 7

    delay(1000);

    PORTD = PORTD ^ (1<<PD5) ^ (1<<PD6) ^ (1<<PD7); // Toggle PortD bit 5, 6 and 7

    delay(5000);

    // Result shows following LED flow

    // Aruduion pin | 5 | 6 | 7

    //              |   |   |     Exercise HIGH and LOW

    //              | * |   |

    //              | * | * | *

    //              |   | * | *

    //              |   |   |     Exercise TOGGLE

    //              |   | * |

    //              | * | * | *

    //              |   |   |

    }

    return 0;

    }

    void delay(int ms) {

    ms /= 100;

    char i;

    for(i = 0; i < ms; i++){

    _delay_ms(100);      // max is 262.14 ms / F_CPU in MHz

    }

    }

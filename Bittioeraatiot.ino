      #include <avr/io.h>
  #include <inttypes.h>
  #include <util/delay.h>

//M‰‰ritell‰‰n kytkin
	#define KYTKIN1 PB0
	#define KYTKIN2 PB1
//M‰‰ritell‰‰n ledit
	#define LED1 PB5

    int main(void)
    {
       uint8_t nappula;

       DDRB &= ~(1 << DDB0);   // DDRB-rekisterin arvo on jo oletuksena nolla, mutta t‰ll‰ komennolla voisimme nollata PB0-pinniin vaikuttavan bitin.
       
	/* Kyseinen bittioperaatio siis tarkoittaa, ett‰ ensin otamme luvun jossa ykkˆst‰ shiftataan sopiva m‰‰r‰, 
	jotta se osuu PB0-pinnin kohdalle (nyt 0 kertaa), sitten otamme kyseisest‰ luvusta negaation, 
	eli siis k‰‰nn‰mme kaikki bitit vastakkaiseen arvoon, jolloin PB0-pinni‰ vastaava bitti on ainoa, joka on '0'. 
	T‰m‰n j‰lkeen luemme DDRB-rekisterin nykyisen arvon ja otamme bitti-AND:n rekisterin arvon ja ‰sken luomamme bittimaskin v‰lill‰, 
	tuloksena on arvo, jossa PB0-pinni‰ vastaava bitti on nollautunut ja muut bitit on s‰ilytetty ennallaan. Lopuksi kirjoitamme kyseisen 
	arvon DDRB-rekisteriin.*/

       PORTB = (1 << PB0);   // Aktivoimme ylˆsvetovastuksen PB0-pinniin.

       while(1)
       {
   

			//Jos kytkint‰ 1 on painettu
		if(~PINB & (1<<KYTKIN1))
		{

			DDRB |= (1<<LED1);
		//	DDRB &= ~((1<<KYTKIN1));

			
			//Sytytet‰‰n halutut ledit
			PORTB &= ~(1<<LED1);
	//		_delay_ms(1000);
		

			//Sammutetaan kaikki ledit
	//		PORTB |= (1<<LED1);
		}
		
			//Jos kytkint‰ 2 on painettu
		else if(~PINB & (1<<KYTKIN2))
		{

		
			//Sammutetaan kaikki ledit
			PORTB |= (1<<LED1);
				
          }
		  
       
		}
       return 0;
    }

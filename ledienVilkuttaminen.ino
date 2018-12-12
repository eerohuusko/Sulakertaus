/*Ledbarin ledien vilkuttaminen satunnaisesti.*/
 
#include <avr/io.h>
#include <util/delay.h>


int randomValue;


void setup() {
 //Pinnit 2-7 asetetaan ulostuloiksi. 
 DDRD = (1<<PD1) | (1<<PD2) | (1<<PD3) | (1<<PD4) | (1<<PD5) | (1<<PD6) | (1<<PD7);
 //Ja pinnit 8-9
 DDRB = (1<<PB0) | (1<<PB1);
 
 //Aluksi kaikki ledit pois päältä
 PORTD = B11111111;
 PORTB = B11111111;
 //Alustetaan sarjaliikenne
 Serial.begin(9600);
}


//Varsinainen ohjelma pyörii loopissa.
void loop() {

//Arvotaan joka loopissa uusi satunnaisluku välillä 1-8.
  randomValue = random(1,8);
  Serial.println(randomValue);
  delay(1000);  
  

  switch(randomValue)
  {
    case 1:
    PORTB = B00000010;
    break;

    case 2: 
    PORTB = B00000001;
    break;

    case 3: 
    PORTD = B11111011;
    break;

    case 4:
    PORTD = B11110111;
    break;

    case 5:
    PORTD = B11101111;
    break;

    case 6:
    PORTD = B11011111;
    break;
    
    case 7:
    PORTD = B10111111;
    break;

    case 8:
    PORTD = B01111111;
    break;
   
    default:
    break;  
  }

//Sekunnin viive:
delay(1000);  
//Ja ledit takaisin pois päältä:
PORTD = B11111111;
PORTB = B11111111;
}

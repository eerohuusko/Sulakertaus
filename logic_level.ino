void setup() {

DDRB |= (1<<DDB5) ;//pin 13 is in output mode

DDRB&=~(1<<DDB0); //pin 8 is in input mode


Serial.begin(9600);

}

void loop() {

Serial.println((PINB&B00000001));

if ((PINB & B00000001)==1){//

PORTB |=(1<< PORTB5);//make pin 13 high and power on the led

}

else{

PORTB &=~ (1<<PORTB5);//make pin 13 low and power off the led

}

}

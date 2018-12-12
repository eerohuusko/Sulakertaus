#include <avr/io.h>
#include <Arduino.h>

//Alustus
#define Led PORTB
#define Led_CLK PB0
#define Led_Data PB1

//Funktio prototyypit
void Write_Bus(int);
void Make_Clk();

//Globaalit muuttujat
int Command_1[9] = {0,0,1,0,0,0,1,0};
int Command_2[9] = {0,0,0,0,0,0,1,1};
int Command_3[9] = {1,1,1,1,1,1,1,0}; // All ON
int Command_4[9] = {1,1,1,1,0,0,0,1};
int Command_5[9] = {0,0,0,0,0,0,1,0};
int Command_6[9] = {1,0,0,0,0,0,1,1};
int Command_7[9] = {0,0,0,0,0,0,1,0};
int Command_8[9] = {0,0,0,0,0,0,1,0};
int Command_9[9] = {0,0,0,0,0,0,1,0};
int Command_0[9] = {1,1,1,1,0,0,0,1};

/*****************************************
Alustaa suuntarekisterit
LED_Data = output = Port_b 1
LED_CLK = output = Port_b 0
******************************************/
void setup() {
  DDRB|= (1<<Led_CLK) | (1<<Led_Data); //kello ja data

  Led|= (1<< Led_Data); //Data Ylös
  Led|= (1<< Led_CLK);  //Kello Ylös

}
/******************************
Pääohjelman looppi
********************************/
void loop() {
  int i;

  for(i=0;i<8;i++){
    Write_Bus(i);       
    }
}
/******************************
Väylään kirjoitus

********************************/
void Write_Bus (int iRmc){

int iByte = iRmc;  

    Led&= ~ (1<<Led_Data); // Data alas
    _delay_ms(2);
    Led&= ~ (1<<Led_CLK); // Kello Alas 

  // Tehdään mekaanisesti kellopulssit 
    for(iByte=0; iByte<7; iByte++){ 
                  
      _delay_ms(2);

      if(Command_1[iByte] == 1)     // Jos data "1"
        Led|= (1<< Led_Data);   // Data Ylös  
      else 
        Led&= ~ (1<<Led_Data);  // Data Alas  
        
      _delay_ms(2);

      Make_Clk();  
    }  
}

void Make_Clk(){
  
      Led|= (1<< Led_CLK); //Kello Ylös
      _delay_ms(10);
      Led&= ~ (1<<Led_CLK); // Kello Alas
      _delay_ms(10);    
  }
    


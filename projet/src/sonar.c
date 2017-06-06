#include "sonar.h"


void init_sonar(){//parametrage du compteur.
  
  TCCR1A = 0;
  TCCR1B = 3;
}

void distance(){
  int i = 0;//variable pour le résultat
  bit_clear(PORTB,PORTB4);
  bit_set(DDRB,DDB4);//pin capteur en sortie
  //printf("ping\n");
  _delay_us(2);
  bit_set(PORTB,PORTB4);//debut de l'impulsion
  _delay_us(10);
  bit_clear(PORTB,PORTB4);//fin de l'impultion
  bit_clear(DDRB,DDB4);//ptin capteur en entrée
  while(!test_bit(PINB,PINB4));//attente du début de l'impulsion retour
  TCNT1L=0;//on reset le compteur
  TCNT1H=0;
  while(test_bit(PINB,PINB4));//attente de la fin de l'impultsion retour
  TCCR1B=0;//on arête le capteur
  i= (TCNT1H<<8) | TCNT1L; //on récupère le résultat
  _delay_us(20);// augment if parasitic echo exists.
  TCCR1B=3;//on redémare le compteur
  return i*2;//résultat en us.

}

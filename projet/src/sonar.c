#include "sonar.h"


void init_sonar(){//parametrage du compteur.
  
  TCCR1A = 0;
  TCCR1B = 3;
}

int distance(){
  uint16_t i = 0;//variable pour le résultat
  clear_bit(PORTB,PORTB4);
  set_bit(DDRB,DDB4);//pin capteur en sortie
  //printf("ping\n");
  _delay_us(2);
  set_bit(PORTB,PORTB4);//debut de l'impulsion
  _delay_us(10);
  clear_bit(PORTB,PORTB4);//fin de l'impultion
  clear_bit(DDRB,DDB4);//pin capteur en entrée
  while(!test_bit(PINB,PINB4));//attente du début de l'impulsion retour
  TCNT1=0;//on reset le compteur
  while(test_bit(PINB,PINB4));//attente de la fin de l'impultsion retour
  TCCR1B=0;//on arête le capteur
  i= TCNT1; //on récupère le résultat
  _delay_us(20);// augment if parasitic echo exists.
  TCCR1B=3;//on redémare le compteur
  return i;//résultat en us.

}

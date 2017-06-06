#include "line.h"

ISR(PCINT0_vect){
  toggle = PORTB^old_PORTB;//on regarde quel bit a changé
  if(test_bit(toggle,PCINT1); // on modifie les bits correspondant aux sorties du capteur dans tracking.
    tracking|=1;
  }
  else{
    tracking&= ~ 1;
  }
  if(test_bit(toggle,PCINT2)){
    tracking|=2;
  }
  else{
    tracking&= ~ 2;
  }
  old_PORTB=PORTB;
  
}


void init(){
  //parametrage des interruption sur les entrées:
  set_bit(PCICR,PCIEO);//interuption activées
  set_bit(PCMSK0,PCINT1);//interuption sur les deux io du suiveur de ligne
  set_bit(PCMSK0,PCINT2);
  sei();
}

int tracking(){//simple fonction pour récuperer les dernières sorties du tracking.
  return tracking;
}

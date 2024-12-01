#include <stdio.h>
#include "automaton.h"

#ifndef INTERFACE_H
#define INTERFACE_H

void menu();
void menuCaminho();
void opcaoCaminho();
void legenda();
void validaCaminho( AutomatoPilha** at );
void validaSemaforo( AutomatoPilha** at );
void menuSemaforo();


#endif
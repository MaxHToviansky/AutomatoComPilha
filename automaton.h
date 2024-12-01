#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

#ifndef AUTOMATON_H
#define AUTOMATON_H


typedef struct transicao{
    int dest;
    char simbFita, leitPilha, escPilha;
} Transicao;

typedef struct automatoPilha{
    int qntEstados, estInicial;
    Transicao*** producoes;
    int *estFinal, *capEst, *transEst;  
} AutomatoPilha;




Transicao* buildTrans(int dest, char simbFita,char leitPilha,char escPilha);
AutomatoPilha* buildAuto(int n);
void inserirTransicao(AutomatoPilha* pl, int estado, Transicao* tr);
int avaliar(char* s, AutomatoPilha* at, int posCru);
int explore(int est,char* s, int i, Pilha* p, AutomatoPilha* at, int posCru);


#endif
    

#include <stdlib.h>

#ifndef PILE_H
#define PILE_H

typedef struct pilha{
    char *p;
    int topo, cap;
} Pilha;


Pilha* buildPilha();
char pTop(Pilha* p);
void push(Pilha* p, char c);
void pop(Pilha*p);

#endif


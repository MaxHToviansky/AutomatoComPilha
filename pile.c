#include "pile.h"

Pilha* buildPilha(){
    Pilha* p = malloc(sizeof(Pilha));
    p->cap=1;
    p->topo=-1;
    p->p = malloc(sizeof(char));
}

char pTop(Pilha* p){
    if(p->topo<0) exit(1);
    return p->p[p->topo];
}

void push(Pilha* p, char c){
    if(p->topo+1 >= p->cap){
        p->cap = (3*p->cap+1)/2;
        p->p = realloc(p->p,p->cap);
    }   
    p->topo++;
    p->p[p->topo]=c;
}

void pop(Pilha* p){
    if(p->topo<0) return;
    p->topo--;
}


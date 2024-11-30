#include "automaton.h"
#include <stdio.h>

int main(){
    AutomatoPilha* at = buildAuto(4);   
    at->estInicial=0;
    at->estFinal[0]=1;
    at->estFinal[1]=1;
    at->estFinal[2]=1;
    Transicao **tr = malloc(12*sizeof(Transicao*));
    
    tr[0] = buildTrans(0,'&','O','&');
    tr[1] = buildTrans(0,'O','&','O');
    tr[2] = buildTrans(1,'N','&','N');
    tr[3] = buildTrans(2,'S','&','S');
    
    tr[4] = buildTrans(1,'&','N','&');
    tr[5] = buildTrans(1,'N','&','N');
    tr[6] = buildTrans(0,'O','&','O');
    tr[7] = buildTrans(2,'S','&','S');
    
    tr[8] = buildTrans(2,'&','S','&');
    tr[9] = buildTrans(2,'S','&','S');
    tr[10] = buildTrans(0,'O','&','O');
    tr[11] = buildTrans(1,'N','&','N');
    
    
    for(int i = 0; i < 4; i++)
        inserirTransicao(at,0,tr[i]);
    for(int i = 4; i < 8; i++)
        inserirTransicao(at,1,tr[i]);
    for(int i = 8; i < 12; i++)
        inserirTransicao(at,2,tr[i]);
    char *c = "M\0";
    printf("%i\n",avaliar(c,at));
    printf("AAAAAAAAAAAAAAA nao dei segfault!!!!!!!!!!!!!!!!!!!!!!\n");
    

}
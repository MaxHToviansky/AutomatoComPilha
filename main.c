#include "automaton.h"
#include <stdio.h>

int main(){
    AutomatoPilha* at = buildAuto(6);   
    at->estInicial=0;
    at->estFinal[4]=1;
    Transicao **tr = malloc(18*sizeof(Transicao*));
    
    tr[0] = buildTrans(1,'N','?','N');
    tr[1] = buildTrans(2,'O','?','O');
    tr[2] = buildTrans(3,'S','?','S');
    
    tr[3] = buildTrans(1,'&','N','&');
    tr[4] = buildTrans(1,'N','&','N');
    tr[5] = buildTrans(2,'O','?','O');
    tr[6] = buildTrans(3,'S','?','S');
    tr[7] = buildTrans(4,'?','?','&');

    tr[8] = buildTrans(2,'&','O','&');
    tr[9] = buildTrans(2,'O','&','O');
    tr[10] = buildTrans(1,'N','?','N');
    tr[11] = buildTrans(3,'S','?','S');
    tr[12] = buildTrans(4,'?','?','&');
    
    tr[13] = buildTrans(3,'&','S','&');
    tr[14] = buildTrans(3,'S','&','S');
    tr[15] = buildTrans(2,'O','?','O');
    tr[16] = buildTrans(1,'N','?','N');
    tr[17] = buildTrans(4,'?','?','&');
    
    
    for(int i = 0; i < 3; i++)
        inserirTransicao(at,0,tr[i]);
    for(int i = 3; i < 8; i++)
        inserirTransicao(at,1,tr[i]);
    for(int i = 8; i < 13; i++)
        inserirTransicao(at,2,tr[i]);
    for(int i = 13; i < 18; i++)
        inserirTransicao(at,3,tr[i]);
    char *c = "NNS\0";
    printf("%i\n",avaliar(c,at, 2));
    printf("AAAAAAAAAAAAAAA nao dei segfault!!!!!!!!!!!!!!!!!!!!!!\n");
    

}
#include "automaton.h"
#include <stdio.h>

int main(){
    // Construção dos automatos
    AutomatoPilha** at = malloc( 3 * sizeof(AutomatoPilha*) );
    Transicao ***tr = malloc(3*sizeof(Transicao*));
    for( int i = 0; i < 2; i++ ) {
        at[i] = buildAuto(6);
        at[i]->estInicial=0;
        at[i]->estFinal[4]=1;
        tr[i] = malloc(18*sizeof(Transicao*));
    }   

    // Construção das transições do automato do cruzamento 2
    tr[0][0] = buildTrans(1,'N','?','N');
    tr[0][1] = buildTrans(2,'O','?','O');
    tr[0][2] = buildTrans(3,'S','?','S');
    
    tr[0][3] = buildTrans(1,'&','N','&');
    tr[0][4] = buildTrans(1,'N','&','N');
    tr[0][5] = buildTrans(2,'O','?','O');
    tr[0][6] = buildTrans(3,'S','?','S');
    tr[0][7] = buildTrans(4,'?','?','&');

    tr[0][8] = buildTrans(2,'&','O','&');
    tr[0][9] = buildTrans(2,'O','&','O');
    tr[0][10] = buildTrans(1,'N','?','N');
    tr[0][11] = buildTrans(3,'S','?','S');
    tr[0][12] = buildTrans(4,'?','?','&');
    
    tr[0][13] = buildTrans(3,'&','S','&');
    tr[0][14] = buildTrans(3,'S','&','S');
    tr[0][15] = buildTrans(2,'O','?','O');
    tr[0][16] = buildTrans(1,'N','?','N');
    tr[0][17] = buildTrans(4,'?','?','&');
    
    // Inserção das transições no automato do cruzamento 2
    for(int i = 0; i < 3; i++)
        inserirTransicao(at[0],0,tr[0][i]);
    for(int i = 3; i < 8; i++)
        inserirTransicao(at[0],1,tr[0][i]);
    for(int i = 8; i < 13; i++)
        inserirTransicao(at[0],2,tr[0][i]);
    for(int i = 13; i < 18; i++)
        inserirTransicao(at[0],3,tr[0][i]);

    // Modificação das transições em 2 para o cruzamento 3
    tr[1][0] = buildTrans(1,'N','?','N');
    tr[1][1] = buildTrans(2,'L','?','L');
    tr[1][2] = buildTrans(3,'S','?','S');
    
    tr[1][3] = buildTrans(1,'&','N','&');
    tr[1][4] = buildTrans(1,'N','&','N');
    tr[1][5] = buildTrans(2,'L','?','L');
    tr[1][6] = buildTrans(3,'S','?','S');
    tr[1][7] = buildTrans(4,'?','?','&');

    tr[1][8] = buildTrans(2,'&','L','&');
    tr[1][9] = buildTrans(2,'L','&','L');
    tr[1][10] = buildTrans(1,'N','?','N');
    tr[1][11] = buildTrans(3,'S','?','S');
    tr[1][12] = buildTrans(4,'?','?','&');
    
    tr[1][13] = buildTrans(3,'&','S','&');
    tr[1][14] = buildTrans(3,'S','&','S');
    tr[1][15] = buildTrans(2,'L','?','L');
    tr[1][16] = buildTrans(1,'N','?','N');
    tr[1][17] = buildTrans(4,'?','?','&');

    // Inserção das transições no automato do cruzamento 3
    for(int i = 0; i < 3; i++)
        inserirTransicao(at[1],0,tr[1][i]);
    for(int i = 3; i < 8; i++)
        inserirTransicao(at[1],1,tr[1][i]);
    for(int i = 8; i < 13; i++)
        inserirTransicao(at[1],2,tr[1][i]);
    for(int i = 13; i < 18; i++)
        inserirTransicao(at[1],3,tr[1][i]);

    char *c2 = "NNSOO\0";
    char *c3 = "NNSLL\0";
    printf("%i\n",avaliar(c2,at[0], 2));
    printf("%i\n", avaliar(c3,at[1], 3));
    printf("AAAAAAAAAAAAAAA nao dei segfault!!!!!!!!!!!!!!!!!!!!!!\n");
    

}
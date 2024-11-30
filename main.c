#include "automaton.h"
#include <stdio.h>

void initialize( AutomatoPilha **at, Transicao ***tr );

int main(){
    AutomatoPilha** at = malloc( 11 * sizeof(AutomatoPilha*) );
    Transicao ***tr = malloc(11*sizeof(Transicao*));
    initialize( at, tr );

}

void initialize( AutomatoPilha **at, Transicao ***tr ) {
    // Construção dos automatos com pilha (Controle do tráfego)
    for( int i = 0; i < 2; i++ ) {
        at[i] = buildAuto(6);
        at[i]->estInicial=0;
        at[i]->estFinal[4]=1;
        tr[i] = malloc(18*sizeof(Transicao*));
    }

    // Construção das transições do automato com pilha do cruzamento 2
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
    
    // Inserção das transições do automato com pilha do cruzamento 2
    for(int i = 0; i < 3; i++)
        inserirTransicao(at[0],0,tr[0][i]);
    for(int i = 3; i < 8; i++)
        inserirTransicao(at[0],1,tr[0][i]);
    for(int i = 8; i < 13; i++)
        inserirTransicao(at[0],2,tr[0][i]);
    for(int i = 13; i < 18; i++)
        inserirTransicao(at[0],3,tr[0][i]);

    // Contrução das transições do automato com pilha do cruzamento 3
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
    
    // Construção dos caminhos dos carros (AFDs)

    // Construção dos caminhos a partir de 'A' e 'B', sem curvas nos pontos do semáforo
    for( int i = 2; i < 4; i++ ) {
        at[i] = buildAuto(8);
        at[i]->estInicial=0;
        at[i]->estFinal[7]=1;
        tr[i] = malloc(8*sizeof(Transicao*));
        tr[i][0] = buildTrans(1,'S','&','&');
        tr[i][1] = buildTrans(7,'E','&','&');
        tr[i][2] = buildTrans(2,'S','&','&');
        tr[i][3] = buildTrans(3,'S','&','&');
        tr[i][4] = buildTrans(4,'N','&','&');
        tr[i][5] = buildTrans(5,'N','&','&');
        tr[i][6] = buildTrans(6,'N','&','&');
        tr[i][7] = buildTrans(7,'E','&','&');
        inserirTransicao(at[i],0,tr[i][0]);
        inserirTransicao(at[i],0,tr[i][1]);
        inserirTransicao(at[i],1,tr[i][2]);
        inserirTransicao(at[i],2,tr[i][3]);
        inserirTransicao(at[i],3,tr[i][4]);
        inserirTransicao(at[i],4,tr[i][5]);
        inserirTransicao(at[i],5,tr[i][6]);
        inserirTransicao(at[i],6,tr[i][7]);
    }
    char *a = "SSSNNNE\0";
    char *b = "SSSNNNE\0";
    printf("%i\n",avaliar(a,at[2], 0));
    printf("%i\n", avaliar(b,at[3], 0));

    // Construção do caminho a partir de 'C', sem curvas nos pontos do semáforo
    at[4] = buildAuto(5);
    at[4]->estInicial = 0;
    at[4]->estFinal[4] = 1;
    tr[4] = malloc(4*sizeof(Transicao*));
    tr[4][0] = buildTrans(1,'L','&','&');
    tr[4][1] = buildTrans(2,'L','&','&');
    tr[4][2] = buildTrans(3,'L','&','&');
    tr[4][3] = buildTrans(4,'E','&','&');
    inserirTransicao(at[4],0,tr[4][0]);
    inserirTransicao(at[4],1,tr[4][1]);
    inserirTransicao(at[4],2,tr[4][2]);
    inserirTransicao(at[4],2,tr[4][3]);
    char *c = "LLL\0";
    printf("%i\n",avaliar(c,at[4], 0));
    
    // Construção do caminho a partir de 'D', sem curvas nos pontos do semáforo
    at[5] = buildAuto(6);
    at[5]->estInicial = 0;
    at[5]->estFinal[4] = 1;
    at[5]->estFinal[5] = 1;
    tr[5] = malloc(5*sizeof(Transicao*));
    tr[5][0] = buildTrans(1,'O','&','&');
    tr[5][1] = buildTrans(2,'O','&','&');
    tr[5][2] = buildTrans(3,'O','&','&');
    tr[5][3] = buildTrans(4,'E','&','&');
    tr[5][4] = buildTrans(5,'E','&','&');
    inserirTransicao(at[5],0,tr[5][0]);
    inserirTransicao(at[5],1,tr[5][1]);
    inserirTransicao(at[5],1,tr[5][3]);
    inserirTransicao(at[5],2,tr[5][2]);
    inserirTransicao(at[5],2,tr[5][4]);
    char *d = "OOE\0";
    printf("%i\n",avaliar(d,at[5], 0));
}
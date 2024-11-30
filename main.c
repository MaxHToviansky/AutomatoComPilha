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

    // Estado inicial
    tr[0][0] = buildTrans(1,'N','?','N');
    tr[0][1] = buildTrans(2,'O','?','O');
    tr[0][2] = buildTrans(3,'S','?','S');
    
    // Estado de abertura para Norte
    tr[0][3] = buildTrans(1,'&','N','&');
    tr[0][4] = buildTrans(1,'N','&','N');
    tr[0][5] = buildTrans(2,'O','?','O');
    tr[0][6] = buildTrans(3,'S','?','S');
    tr[0][7] = buildTrans(4,'?','?','&');

    // Estado de abertura para Oeste
    tr[0][8] = buildTrans(2,'&','O','&');
    tr[0][9] = buildTrans(2,'O','&','O');
    tr[0][10] = buildTrans(1,'N','?','N');
    tr[0][11] = buildTrans(3,'S','?','S');
    tr[0][12] = buildTrans(4,'?','?','&');
    
    // Estado de abertura para Sul
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
    // Estado inicial
    tr[1][0] = buildTrans(1,'N','?','N');
    tr[1][1] = buildTrans(2,'L','?','L');
    tr[1][2] = buildTrans(3,'S','?','S');
    
    // Estado de abertura para Norte
    tr[1][3] = buildTrans(1,'&','N','&');
    tr[1][4] = buildTrans(1,'N','&','N');
    tr[1][5] = buildTrans(2,'L','?','L');
    tr[1][6] = buildTrans(3,'S','?','S');
    tr[1][7] = buildTrans(4,'?','?','&');

    // Estado de abertura para Leste
    tr[1][8] = buildTrans(2,'&','L','&');
    tr[1][9] = buildTrans(2,'L','&','L');
    tr[1][10] = buildTrans(1,'N','?','N');
    tr[1][11] = buildTrans(3,'S','?','S');
    tr[1][12] = buildTrans(4,'?','?','&');
    
    // Estado de abertura para Sul
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


    // Sem curvas nos semáforos
    // Construção dos caminhos a partir de 'A' e 'B', sem curvas nos pontos do semáforo
    for( int i = 2; i < 4; i++ ) {
        at[i] = buildAuto(8);
        at[i]->estInicial=0;
        at[i]->estFinal[7]=1;
        tr[i] = malloc(8*sizeof(Transicao*));
        tr[i][0] = buildTrans(1,'S','&','&');   // i = 2: A->C1     i = 3: B->C2
        tr[i][1] = buildTrans(7,'E','&','&');   // i = 2: A->Pa     i = 3: B->Pb
        tr[i][2] = buildTrans(2,'S','&','&');   // i = 2: C1->C3    i = 3: C2->C4
        tr[i][3] = buildTrans(3,'S','&','&');   // i = 2: C3->R2    i = 3: C4->R3
        tr[i][4] = buildTrans(4,'N','&','&');   // i = 2: R2->C3'   i = 3: R3->C4'
        tr[i][5] = buildTrans(5,'N','&','&');   // i = 2: C3'->C1'  i = 3: C4'->C2'
        tr[i][6] = buildTrans(6,'N','&','&');   // i = 2: C1'->A'   i = 3: C2'->B'
        tr[i][7] = buildTrans(7,'E','&','&');   // i = 2: A'->Pa    i = 3: A'->Pb
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
    tr[4][0] = buildTrans(1,'L','&','&');   // C->C1
    tr[4][1] = buildTrans(2,'L','&','&');   // C1->C2
    tr[4][2] = buildTrans(3,'L','&','&');   // C2->R4
    tr[4][3] = buildTrans(4,'E','&','&');   // C2->Pr2
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
    tr[5][0] = buildTrans(1,'O','&','&');   // D->C4
    tr[5][1] = buildTrans(2,'O','&','&');   // C4->C3
    tr[5][2] = buildTrans(3,'O','&','&');   // C3->R1
    tr[5][3] = buildTrans(4,'E','&','&');   // C4->Pm
    tr[5][4] = buildTrans(5,'E','&','&');   // C3->Pr1
    inserirTransicao(at[5],0,tr[5][0]);
    inserirTransicao(at[5],1,tr[5][1]);
    inserirTransicao(at[5],1,tr[5][3]);
    inserirTransicao(at[5],2,tr[5][2]);
    inserirTransicao(at[5],2,tr[5][4]);
    char *d = "OOE\0";
    printf("%i\n",avaliar(d,at[5], 0));

    // Com curvas nos semáforos
    // Construção dos caminhos começando em 'A'
    at[6] = buildAuto(10);
    at[6]->estInicial=0;
    at[6]->estFinal[8]=1;
    at[6]->estFinal[9]=1;
    tr[6] = malloc(12*sizeof(Transicao*));
    tr[6][0] = buildTrans(1,'S','&','&');   // A->C1
    tr[6][1] = buildTrans(8,'E','&','&');   // A->Pa
    tr[6][2] = buildTrans(2,'S','&','&');   // C1->C3
    tr[6][3] = buildTrans(3,'S','&','&');   // C3->R2
    tr[6][4] = buildTrans(7,'O','&','&');   // C3->R1
    tr[6][5] = buildTrans(9,'E','&','&');   // C3->Pr1
    tr[6][6] = buildTrans(4,'N','&','&');   // R2->C3'
    tr[6][7] = buildTrans(5,'N','&','&');   // C3'->C1'
    tr[6][8] = buildTrans(7,'O','&','&');   // C3'->R1
    tr[6][9] = buildTrans(9,'E','&','&');   // C3'->Pr1
    tr[6][10] = buildTrans(6,'N','&','&');  // C1'->A'
    tr[6][11] = buildTrans(8,'E','&','&');  // A'->Pa
    inserirTransicao(at[6],0,tr[6][0]);
    inserirTransicao(at[6],0,tr[6][1]);
    inserirTransicao(at[6],1,tr[6][2]);
    inserirTransicao(at[6],2,tr[6][3]);
    inserirTransicao(at[6],2,tr[6][4]);
    inserirTransicao(at[6],2,tr[6][5]);
    inserirTransicao(at[6],3,tr[6][6]);
    inserirTransicao(at[6],4,tr[6][7]);
    inserirTransicao(at[6],4,tr[6][8]);
    inserirTransicao(at[6],4,tr[6][9]);
    inserirTransicao(at[6],5,tr[6][10]);
    inserirTransicao(at[6],6,tr[6][11]);
    char *ac = "SSSNNNE\0";
    printf("%i\n",avaliar(ac,at[6], 0));

    // Construção dos caminhos começando em 'B'
    at[7] = buildAuto(10);
    at[7]->estInicial=0;
    at[7]->estFinal[8]=1;
    at[7]->estFinal[9]=1;
    tr[7] = malloc(12*sizeof(Transicao*));
    tr[7][0] = buildTrans(1,'S','&','&');   // B->C2
    tr[7][1] = buildTrans(8,'E','&','&');   // B->Pb
    tr[7][2] = buildTrans(2,'S','&','&');   // C2->C4
    tr[7][3] = buildTrans(7,'L','&','&');   // C2->R4
    tr[7][4] = buildTrans(9,'E','&','&');   // C2->Pr4
    tr[7][5] = buildTrans(3,'S','&','&');   // C4->R3
    tr[7][6] = buildTrans(4,'N','&','&');   // R3->C4'
    tr[7][7] = buildTrans(5,'N','&','&');   // C4'->C2'
    tr[7][8] = buildTrans(7,'L','&','&');   // C2'->R4
    tr[7][9] = buildTrans(9,'E','&','&');   // C2'->Pr4
    tr[7][10] = buildTrans(6,'N','&','&');  // C2'->B'
    tr[7][11] = buildTrans(9,'E','&','&');  // B'->Pb
    inserirTransicao(at[7],0,tr[7][0]);
    inserirTransicao(at[7],0,tr[7][1]);
    inserirTransicao(at[7],1,tr[7][2]);
    inserirTransicao(at[7],1,tr[7][3]);
    inserirTransicao(at[7],1,tr[7][4]);
    inserirTransicao(at[7],2,tr[7][5]);
    inserirTransicao(at[7],3,tr[7][6]);
    inserirTransicao(at[7],4,tr[7][7]);
    inserirTransicao(at[7],5,tr[7][8]);
    inserirTransicao(at[7],5,tr[7][9]);
    inserirTransicao(at[7],5,tr[7][10]);
    inserirTransicao(at[7],6,tr[7][11]);

    char *bc = "E\0";
    printf("%i\n",avaliar(bc,at[7], 0));

    // Construção dos caminhos começando em 'C'
    at[8] = buildAuto(11);
    at[8]->estInicial=0;
    at[8]->estFinal[9]=1;
    at[8]->estFinal[10]=1;
    tr[8] = malloc(13*sizeof(Transicao*));
    tr[8][0] = buildTrans(1,'L','&','&');   // C->C1
    tr[8][1] = buildTrans(2,'L','&','&');   // C1->C2
    tr[8][2] = buildTrans(3,'N','&','&');   // C2->B
    tr[8][3] = buildTrans(4,'L','&','&');   // C2->R4
    tr[8][4] = buildTrans(5,'S','&','&');   // C2->C4
    tr[8][5] = buildTrans(9,'E','&','&');   // C2->Pr4
    tr[8][6] = buildTrans(10,'E','&','&');  // B->Pb
    tr[8][7] = buildTrans(6,'S','&','&');   // C4->R3
    tr[8][8] = buildTrans(6,'N','&','&');   // R3->C4'
    tr[8][9] = buildTrans(7,'N','&','&');   // C4'->C2'
    tr[8][10] = buildTrans(4,'L','&','&');  // C2'->R4
    tr[8][11] = buildTrans(3,'N','&','&');  // C2->B
    tr[8][12] = buildTrans(9,'E','&','&');  // C2'->Pr4
    inserirTransicao(at[8],0,tr[8][0]);
    inserirTransicao(at[8],1,tr[8][1]);
    inserirTransicao(at[8],2,tr[8][2]);
    inserirTransicao(at[8],2,tr[8][3]);
    inserirTransicao(at[8],2,tr[8][4]);
    inserirTransicao(at[8],2,tr[8][5]);
    inserirTransicao(at[8],3,tr[8][6]);
    inserirTransicao(at[8],5,tr[8][7]);
    inserirTransicao(at[8],6,tr[8][8]);
    inserirTransicao(at[8],7,tr[8][9]);
    inserirTransicao(at[8],8,tr[8][10]);
    inserirTransicao(at[8],8,tr[8][11]);
    inserirTransicao(at[8],8,tr[8][12]);

    char *cc = "LLSE\0";
    printf("%i\n",avaliar(cc,at[8], 0));

    // Construção dos caminhos começando em 'D'
    at[9] = buildAuto(11);
    at[9]->estInicial=0;
    at[9]->estFinal[8]=1;
    at[9]->estFinal[9]=1;
    at[9]->estFinal[10]=1;
    tr[9] = malloc(13*sizeof(Transicao*));
    tr[9][0] = buildTrans(1,'O','&','&');   // D->C4
    tr[9][1] = buildTrans(2,'O','&','&');   // C4->C3
    tr[9][2] = buildTrans(8,'E','&','&');   // C4->Pm
    tr[9][3] = buildTrans(3,'O','&','&');   // C3->R1
    tr[9][4] = buildTrans(4,'S','&','&');   // C3->R2
    tr[9][5] = buildTrans(9,'E','&','&');   // C3->Pr1
    tr[9][6] = buildTrans(5,'N','&','&');   // C3->C1
    tr[9][7] = buildTrans(6,'N','&','&');   // R2->C3'
    tr[9][8] = buildTrans(3,'O','&','&');   // C3'->R1
    tr[9][9] = buildTrans(5,'N','&','&');   // C3'->C1
    tr[9][10] = buildTrans(9,'E','&','&');  // C3'->Pr1
    tr[9][11] = buildTrans(7,'N','&','&');  // C1->A
    tr[9][12] = buildTrans(10,'E','&','&'); // A->Pa
    inserirTransicao(at[9],0,tr[9][0]);
    inserirTransicao(at[9],1,tr[9][1]);
    inserirTransicao(at[9],1,tr[9][2]);
    inserirTransicao(at[9],2,tr[9][3]);
    inserirTransicao(at[9],2,tr[9][4]);
    inserirTransicao(at[9],2,tr[9][5]);
    inserirTransicao(at[9],2,tr[9][6]);
    inserirTransicao(at[9],4,tr[9][7]);
    inserirTransicao(at[9],6,tr[9][8]);
    inserirTransicao(at[9],6,tr[9][9]);
    inserirTransicao(at[9],6,tr[9][10]);
    inserirTransicao(at[9],5,tr[9][11]);
    inserirTransicao(at[9],7,tr[9][12]);

    char *dc = "OONNE\0";
    printf("%i\n",avaliar(dc,at[9], 0));
}
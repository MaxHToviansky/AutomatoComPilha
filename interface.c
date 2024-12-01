#include "interface.h"

void menu() {
    printf("Escolha uma opcao:\n");
    printf("0 - Sair do programa\n");
    printf("1 - Possivel caminho para um estacionamento\n");
    printf("2 - Controle do trafego por semaforos\n\n");
}

void menuCaminho() {
    printf("Escolha uma opcao:\n");
    printf("0 - Sair\n");
    printf("1 - Caminho sem curva nos semaforos\n");
    printf("2 - Caminho com curva nos semaforos\n\n");
}

void opcaoCaminho() {
    printf("Escolha o ponto que deseja iniciar:\n");
    printf("Possibilidades: A,B,C,D\n\n");
}

void legenda() {
    printf("Legenda:\n");
    printf("N - Norte\n");
    printf("S - Sul\n");
    printf("O - Oeste\n");
    printf("L - Leste\n");
    printf("E - Estacionar\n\n");
}

void validaCaminho( AutomatoPilha** at ) {
    int opt = -1, conf = 0;
    char origem = '\0';
    char *caminho = calloc(100, sizeof(char));
    menuCaminho();
    scanf("%i", &opt );
    do {
        switch (opt)
        {
        case 0:
            printf("Saindo...\n\n");
            break;
        
        case 1:
            opcaoCaminho();
            scanf(" %c", &origem );
            legenda();
            printf("Digite um caminho a partir desse ponto inicial para um estacionamento\n");
            switch (origem)
            {
            case 'A':
                printf("Possibilidades de movimento: S,N,E\n");
                scanf("%s", caminho );
                conf = avaliar( caminho, at[2], 0 );
                break;
                
            case 'B':
                printf("Possibilidades de movimento: S,N,E\n");
                scanf("%s", caminho );
                conf = avaliar( caminho, at[3], 0 );
                break;

            case 'C':
                printf("Possibilidades de movimento: L,E\n");
                scanf("%s", caminho );
                conf = avaliar( caminho, at[4], 0 );
                break;

            case 'D':
                printf("Possibilidades de movimento: O,E\n");
                scanf("%s", caminho );
                conf = avaliar( caminho, at[5], 0 );
                break;
            default:
                printf("Esse ponto inicial nao existe.\n\n");
                break;
            }
            break;
        case 2:
            opcaoCaminho();
            scanf(" %c", &origem );
            legenda();
            printf("Digite um caminho a partir desse ponto inicial para um estacionamento\n");
            switch (origem)
            {
            case 'A':
                printf("Possibilidades de movimento: S,O,N,E\n");
                scanf("%s", caminho );
                conf = avaliar( caminho, at[6], 0 );
                break;
                
            case 'B':
                printf("Possibilidades de movimento: S,L,N,E\n");
                scanf("%s", caminho );
                conf = avaliar( caminho, at[7], 0 );
                break;

            case 'C':
                printf("Possibilidades de movimento: L,S,N,E\n");
                scanf("%s", caminho );
                conf = avaliar( caminho, at[8], 0 );
                break;

            case 'D':
                printf("Possibilidades de movimento: O,S,N,E\n");
                scanf("%s", caminho );
                conf = avaliar( caminho, at[9], 0 );
                break;
            default:
                printf("Esse ponto inicial nao existe.\n\n");
                break;
            }
        default:
            break;
        }
    } while( origem != 'A' && origem != 'B' && origem != 'C' && origem != 'D' );
    if( conf == 1 ) {
        printf("Esse caminho existe\n\n");
    } else {
        printf("Esse caminho eh invalido\n\n");
    }
}

void menuSemaforo() {
    printf("Escolha uma opcao abaixo:\n");
    printf("2 - Cruzamento 2\n");
    printf("3 - Cruzamento 3\n");
}

void validaSemaforo( AutomatoPilha** at ) {
    int opt = -1;
    char *possibilidades = calloc(100, sizeof(char));
    menuSemaforo();
    scanf("%i", &opt);
    legenda();
    do {
        printf("Digite de onde estao vindo carros:\n");
        switch (opt)
        {
        case 2:
            printf("Possibilidades: N,O,S\n\n");
            scanf(" %s", possibilidades);
            avaliar(possibilidades, at[0], 2 );
            break;
        
        case 3:
            printf("Possibilidades: N,L,S\n\n");
            scanf(" %s", possibilidades);
            avaliar(possibilidades, at[1], 3 );
            break;
        default:
            break;
        }
    } while( opt != 2 && opt != 3 );
}
#include "automaton.h"


// Implementação de um automato com pilha. Pode ser utilizado com automatos sem pilha usando leituras
// e escritas vazias na pilha. 
// Não tem suporte para automatos com rejeição por loop.
// Não tem suporte para remoção e adição de estados, apenas a quantidade alocada na sua criação.
// Pode inserir transições, mas não as remove.


Transicao* buildTrans(int dest, char simbFita,char leitPilha,char escPilha){
    Transicao *trans = malloc(sizeof(Transicao));
    trans->dest=dest;
    trans->simbFita=simbFita;
    trans->leitPilha=leitPilha;
    trans->escPilha=escPilha;
    return trans;
}


AutomatoPilha* buildAuto(int n){
    AutomatoPilha *at = malloc(sizeof(AutomatoPilha));
    at->qntEstados = n;
    at->estFinal = calloc(n,sizeof(int));
    at->producoes = calloc(n,sizeof(Transicao**));
    at->capEst = calloc(n,sizeof(int));
    for(int i = 0; i < n; i++){
        at->producoes[i] = calloc(1,sizeof(Transicao*));
        at->capEst[i]=1;
    }
    at->transEst = calloc(n,sizeof(int));
    return at;
}


void inserirTransicao(AutomatoPilha* pl, int estado, Transicao* tr){
    if(pl->capEst[estado] <= pl->transEst[estado]+1){ // Implementação de vetor dinâmico
        pl->capEst[estado] = (3*pl->capEst[estado]+1)/2;
        pl->producoes[estado] = realloc(pl->producoes[estado], pl->capEst[estado]*(sizeof(Transicao*)));
    }
    pl->producoes[estado][pl->transEst[estado]] = tr;
    pl->transEst[estado]++;
}

// Dado uma fita e um automato, valida a fita. Automatos NÃO podem ter casos de loop.
int avaliar(char* s, AutomatoPilha* at, int posCru){
    Pilha* p = buildPilha();
    return explore(at->estInicial,s,0,p,at, posCru);
}

int explore(int est,char* s, int i, Pilha* p, AutomatoPilha* at, int posCru){
    
    int res = 0;
    if(at->estFinal[est] && s[i]=='\0' && p->topo==-1) return 1;
    for(int j = 0; j < at->transEst[est]; j++){
        
        Transicao tr = *at->producoes[est][j];
        
        
        if(tr.simbFita!='&' && tr.simbFita!='?' && s[i]!=tr.simbFita) continue; // Lê fita
        if(tr.simbFita=='?' && s[i]!='\0') continue; // Verifica fita vazia caso leia '?'
        
        int popado = 0; 
        if(tr.leitPilha!='&'){ //Caso necessario lê da pilha

            if(tr.leitPilha!='?'){ 
                if(p->topo<0 || tr.leitPilha!=pTop(p)) continue; //Lê pilha
                pop(p);
                popado=1;
            }else if(p->topo>=0) continue; // Verificação de pilha vazia

        }

        if(tr.escPilha!='&') push(p,tr.escPilha); // Escreve na pilha
        if( tr.simbFita != '&' ) { // Funções de print
            switch (posCru)
            {
            case 2:
                switch( tr.dest ) {
                case 1:
                    printf("Origem\tNorte\tOeste\tSul\n%c\tAberto\tFechado\tFechado\n\n", s[i]);
                    break;
                case 2:
                    printf("Origem\tNorte\tOeste\tSul\n%c\tFechado\tAberto\tFechado\n\n", s[i]);
                    break;
                case 3:
                    printf("Origem\tNorte\tOeste\tSul\n%c\tFechado\tFechado\tAberto\n\n", s[i]);
                    break;
                default:
                    printf("Origem\tNorte\tOeste\tSul\nSem\tFechado\tFechado\tFechado\n\n");
                }
                break;
            case 3:
                switch( tr.dest ) {
                case 1:
                    printf("Origem\tNorte\tLeste\tSul\n%c\tAberto\tFechado\tFechado\n\n", s[i]);
                    break;
                case 2:
                    printf("Origem\tNorte\tLeste\tSul\n%c\tFechado\tAberto\tFechado\n\n", s[i]);
                    break;
                case 3:
                    printf("Origem\tNorte\tLeste\tSul\n%c\tFechado\tFechado\tAberto\n\n", s[i]);
                    break;
                default:
                    printf("Origem\tNorte\tLeste\tSul\nSem\tFechado\tFechado\tFechado\n\n");
                }
            
            default:
                break;
            }
        }
        
        res |= explore(tr.dest,s,i+(tr.simbFita!='&'),p,at, posCru); 
        
        if(tr.escPilha!='&') pop(p); // Remove o que foi alterado da pilha, para manter apenas uma pilha no programa
        if(popado) push(p,tr.leitPilha); // devolve o que foi retirado da pilha 
        if(res) return 1; // encerra se um caminho aceito foi encotrado
    }
    return 0;
}





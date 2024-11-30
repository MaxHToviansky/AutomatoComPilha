#include "automaton.h"



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
void inserirTransicao(AutomatoPilha* pl, int a, Transicao* tr){
    if(pl->capEst[a] <= pl->transEst[a]+1){
        pl->capEst[a] = (3*pl->capEst[a]+1)/2;
        pl->producoes[a] = realloc(pl->producoes[a], pl->capEst[a]*(sizeof(Transicao*)));
    }
    pl->producoes[a][pl->transEst[a]] = tr;
    pl->transEst[a]++;
}
int avaliar(char* s, AutomatoPilha* at){
    Pilha* p = buildPilha();
    return explore(at->estInicial,s,0,p,at);
}

int explore(int est,char* s, int i, Pilha* p, AutomatoPilha* at){
    
    int res = 0;
    if(at->estFinal[est] && s[i]=='\0' && p->topo==-1) return 1;
    for(int j = 0; j < at->transEst[est]; j++){
        
        Transicao tr = *at->producoes[est][j];
        
        if(tr.simbFita!='&' && s[i]!=tr.simbFita) continue;
        int popado = 0;
        if(tr.leitPilha!='&'){

            if(tr.leitPilha!='?'){
                if(p->topo<0 || tr.leitPilha!=pTop(p)) continue;
                pop(p);
                popado=1;
            }else if(p->topo>=0) continue;

        }

        if(tr.escPilha!='&') push(p,tr.escPilha);
        
        res |= explore(tr.dest,s,i+(tr.simbFita!='&'),p,at);
        
        if(tr.escPilha!='&') pop(p);
        if(popado) push(p,tr.leitPilha);
        if(res) return 1;
    }
    return 0;
}





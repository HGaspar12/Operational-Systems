#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include <windows.h>
#include "bibEscalonador.h"


int main (void) {

    struct processos *plist, *ptmp; //lista com 10 processos
    plist       = init_processos(1, 10, 3);			//numero do processo, tempo e prioridade;
    plist->prox = init_processos(2,  10, 1); ptmp = plist->prox;
    ptmp->prox  = init_processos(3,  10, 3); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(4,  10, 1); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(5,  10, 2); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(6,  10, 2); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(7,  10, 3); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(8,  10, 3); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(9,  10, 2); ptmp = ptmp->prox;
    ptmp->prox  = init_processos(10,  10, 2);

    /* Simulações executadas*/
    listaprocs(plist);
    fifo(plist);
    prioridade(plist);
    //rr(plist,0);

    while (plist != NULL) {
        ptmp = plist;
        plist = plist->prox;
        free(ptmp);
    };

    return(0);
};

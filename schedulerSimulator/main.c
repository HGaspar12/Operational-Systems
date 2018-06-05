#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include <windows.h>
#include "bibEscalonador.h"

//===========================================================================

//====== Inicializando lista de processos
struct processos *init_processos (int id, int tempo, int prioridade) {
    struct processos *proc;
 proc = (struct processos*)malloc(sizeof(struct processos));
  if (proc == NULL) {
        printf("Erro Fatal: Falha na Alocacao de memoria.");
        exit(1);
    };
    proc->id = id;
    proc->tempo = tempo;
    proc->prioridade = prioridade;
    proc->execucao = 0;
    proc->espera = 0;
    proc->prox = NULL;
    return(proc);
};
//===========================================================================
//LISTA DE PROCESSOS
void listaprocs (struct processos *proc) {
  struct processos *tmp = proc;
  printf("\tLista de Processos\n");
  printf("\n");
  while (tmp != NULL) {
    printf("PID: %d\tPrioridade: %d\tTempo: %d\n", tmp->id, tmp->prioridade, tmp->tempo);
    tmp = tmp->prox;
  };
  printf("\n\n");
 };
//===========================================================================
//FIFO (First In First Out) - Semelhante a uma fila, onde o primeiro processo a chegar é o primeiro a sair
void fifo (struct processos *proc) {
    int time = 0, inicio, fim;
  struct processos *tmp = proc;
    printf("\t FIFO - FIRST IN FIRST OUT\n");
    printf("\n");

  while (tmp != NULL) {
    inicio = time;
    time += tmp->tempo;
    fim = time;
    Sleep(1000);
    printf("PID: %d\tTempo: %d\tPrioridade: %d\n", tmp->id, tmp->tempo, tmp->prioridade);
    tmp = tmp->prox;
  };
    printf("\n\n");
};
//===========================================================================
// ESCALONAMENTO POR PRIORIDADE
// O processo de menor valor de prioridade obtem prioridade maior na fila dos processos
void prioridade (struct processos *proc) {
  int time, inicio, fim, maior;
  struct processos *copia, *tmpsrc, *tmp, *maiorprimeiro;
  printf("\tEscalonamento por Prioridade\n");
   printf("\n");

     /* Replicando Lista de Processos */
  tmpsrc = proc;
  copia = tmp = NULL;
  while (tmpsrc != NULL) {
    if (copia == NULL) {
        copia = init_processos(tmpsrc->id, tmpsrc->tempo, tmpsrc->prioridade);
        tmp = copia;
    }
    else {
        tmp->prox = init_processos(tmpsrc->id, tmpsrc->tempo, tmpsrc->prioridade);
        tmp = tmp->prox;
    };
    tmpsrc = tmpsrc->prox;
  };

  /* Programa Principal */
  time = 0;
//busca proximo processo para executar
  while (copia != NULL) {
    maiorprimeiro = NULL;
    maior = copia->prioridade; //prioridade do primeiro processo
    tmp = copia->prox;
    tmpsrc = copia;

    while (tmp != NULL) {
        if (tmp->prioridade < maior) {
            maior = tmp->prioridade;
            maiorprimeiro = tmpsrc;
        };
        Sleep(900);
        tmpsrc = tmp;
        tmp = tmp->prox;
    };

//Verifica se o primeiro processo possui maior prioridade
     if (maiorprimeiro == NULL) {
        inicio = time;
        time += copia->tempo;
        fim = time;
        printf("Processo: %d\tTempo: %d\tEspera: %d\n", copia->id, time, inicio, tmp->prioridade);
        tmpsrc = copia->prox;
        free(copia);
        copia = tmpsrc;
    }
//Verifica se o primeiro processo não possui maior prioridade
     else {
        tmp = maiorprimeiro->prox;
        inicio = time;
        time += tmp->tempo;
        fim = time;
        printf("Processo: %d\tTempo: %d\tEspera: %d\tPrioridade: %d\n", tmp->id, time, inicio, tmp->prioridade);
        maiorprimeiro->prox = tmp->prox;
        free(tmp);
    };
  };
  printf("\n\n");
};
/*
/* Escalonamento Round-Robin
void rr (struct processos *proc, int quantum) {
  int jobsremain, passes;
  struct processos *copia, *tmpsrc, *tmp, *slot;
  printf("\tEscalonamento Round-Robin - Quantum: %d)\n", quantum);
  printf("\n");
  tmpsrc = proc;
  copia = tmp = NULL;
  while (tmpsrc != NULL) {
    if (copia == NULL) {
    copia = init_processos(tmpsrc->id, tmpsrc->tempo, tmpsrc->prioridade);
    tmp = copia;
    } else {
    tmp->prox = init_processos(tmpsrc->id, tmpsrc->tempo, tmpsrc->prioridade);
    tmp = tmp->prox;
    };
    tmpsrc = tmpsrc->prox;
  };
  /* Programa rotina de análise de prioridade
  jobsremain = 2;
  slot = NULL;
  while (jobsremain) {
    jobsremain = 0;
    /* Seleciona o próximo processo efetuando sua alocação
    if (slot == NULL) {
    slot = copia;
    jobsremain = 2;
    } else {
    passes = 0;
    do {
      if (slot->prox == NULL) {
        passes++;
        slot = copia;
      } else {
        slot = slot->prox;
      };
    } while (passes <= 3 && slot->tempo == slot->execucao);
    if (passes <= 3) {
      jobsremain = 2;
    };
    };
     Executa um ciclo
    tmp = copia;
    while (tmp != NULL) {
    if (tmp->tempo > tmp->execucao) {
      if (tmp == slot) {
        tmp->execucao += quantum;
      } else {
        tmp->espera += quantum;
      };
    };
    tmp = tmp->prox;
    };
  };
   Exibe os resultados e elimina as replicações
  tmp = copia;
  while (tmp != NULL) {
    printf("Processo: %d\tTempo: %d\tEspera: %d\tRetorno: %d\n", tmp->id, tmp->tempo, tmp->espera, tmp->execucao + tmp->espera);
    tmpsrc = tmp;
    tmp = tmp->prox;
    free(tmpsrc);
  };
  printf("\n");

}
*/

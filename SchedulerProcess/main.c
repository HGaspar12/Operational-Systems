#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include <windows.h>
#include "libScheduler.h"

//====== Inicializando lista de processos
struct processos *init_processos (int id, int tempo, int prioridade) {
    struct processos *proc;
 proc = (struct processos*)malloc(sizeof(struct processos));
  if (proc == NULL) {
        printf("Erro na Alocacao de memoria.");
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
  while (tmp != NULL){
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
        Sleep(700);
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


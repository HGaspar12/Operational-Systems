#ifndef LIBSCHEDULER_H_INCLUDED
#define LIBSCHEDULER_H_INCLUDED


/* Estrutura dos Processos */
struct processos {
    int id;                   //Identifi��o do processo
 	int tempo;                //Tempo de dura��o do processo
    int prioridade;           //prioridade do process
    int execucao;             //Tempo de execu��o do processo
    int espera;               // Tempo de espera do processo
    struct processos *prox;
};

    // Declara��es de Prot�tipos de fun��es

    struct processos *init_processos (int id, int tempo, int prioridade);

    //fun�ao para o algoritmo FCFS
    void fifo (struct processos *proc);

    //fun�ao para listar os processos
    void listaprocs (struct processos *proc);
    //fun�ao para verificar prioridade
    void prioridade (struct processos *proc);



#endif // LIBSCHEDULER_H_INCLUDED

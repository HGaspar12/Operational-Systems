#ifndef LIBSCHEDULER_H_INCLUDED
#define LIBSCHEDULER_H_INCLUDED


/* Estrutura dos Processos */
struct processos {
    int id;                   //Identifição do processo
 	int tempo;                //Tempo de duração do processo
    int prioridade;           //prioridade do process
    int execucao;             //Tempo de execução do processo
    int espera;               // Tempo de espera do processo
    struct processos *prox;
};

    // Declarações de Protótipos de funções

    struct processos *init_processos (int id, int tempo, int prioridade);

    //funçao para o algoritmo FCFS
    void fifo (struct processos *proc);

    //funçao para listar os processos
    void listaprocs (struct processos *proc);
    //funçao para verificar prioridade
    void prioridade (struct processos *proc);



#endif // LIBSCHEDULER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct semaphore{
    int count;
    pthread_cond_t got_request;
    pthread_mutex_t request_mutex;
    pthread_mutex_t count_mutex;
} semaphore;

semaphore init_semaphore(semaphore *s){
    s->count = 0;
}

semaphore destroy_semaphore(semaphore *s){

}

void semWait(semaphore *s){
        pthread_mutex_lock(&(s->request_mutex));
        if (s->count < 0){
                pthread_cond_wait(&(s->got_request), &(s->request_mutex));
                s->count--;
        }
        pthread_mutex_unlock(&(s->request_mutex));
}

void semSignal(semaphore *s){
    pthread_mutex_lock(&(s->request_mutex));
    if (s->count <= 0){
		pthread_cond_signal(&(s->got_request));
		s->count++;
    }
    pthread_mutex_unlock(&(s->request_mutex));
}

int main(void){
}

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "reunion.h"

struct reunion {
    int size,votos;
    pthread_mutex_t m;
    pthread_cond_t cond;
};

/* Implemente estas funciones en reunion.c */
Reunion *nuevaReunion() {
    Reunion *r = malloc(sizeof(Reunion));
    r->size = 0;
    r->votos = 0;
    pthread_mutex_init(&r->m,NULL);
    pthread_cond_init(&r->cond,NULL);
    return r;
}

void entrar(Reunion *r) {
    pthread_mutex_lock(&r->m);
    while(r->votos != r->size) {
        pthread_cond_wait(&r->cond,&r->m);
    }
    r->size++;
    pthread_cond_broadcast(&r->cond);
    pthread_mutex_unlock(&r->m);
}

void concluir(Reunion *r) {
    pthread_mutex_lock(&r->m);
    r->votos++;
    while(r->votos != r->size) {
        pthread_cond_wait(&r->cond, &r->m);
    }
    pthread_cond_broadcast(&r->cond);
    pthread_mutex_unlock(&r->m);
}


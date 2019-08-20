#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>

#include "jsocket.h"
#include "util.h"

typedef void *(*Thread_fun)(void *);

char estacionamientos[5][100];

pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond= PTHREAD_COND_INITIALIZER;

int estDisp(char xd) {
  int espc = xd - '0';
  if (espc == 5) {
    for (int i=0;i <= 4;i++) {
      if (strcmp(estacionamientos[i],"") != 0) {
        return -1;
      }
    }
    return 0;
  }
  if (espc == 4) {
    if (strcmp(estacionamientos[0],"") == 0 && strcmp(estacionamientos[1],"") == 0 && strcmp(estacionamientos[2],"") == 0 && strcmp(estacionamientos[3],"") == 0) {
      return 0;
    }
    else if (strcmp(estacionamientos[4],"") == 0 && strcmp(estacionamientos[1],"") == 0 && strcmp(estacionamientos[2],"") == 0 && strcmp(estacionamientos[3],"") == 0) {
        return 1;
    }
    else {
      return -1;
    }
  }
  if (espc == 3) {
    for (int i=0;i <= 2;i++) {
      if (strcmp(estacionamientos[i],"") == 0 && strcmp(estacionamientos[i+1],"") == 0 && strcmp(estacionamientos[i+2],"") == 0) {
        return i;
      }
    }
    return -1;
  }
  if (espc == 2) {
    for (int i=0;i <= 3;i++) {
      if (strcmp(estacionamientos[i],"") == 0 && strcmp(estacionamientos[i+1],"") == 0) {
        return i;
      }
    }
    return -1;
  }
  if (espc == 1) {
    for (int i=0;i <= 4;i++) {
      if (strcmp(estacionamientos[i],"") == 0) {
        return i;
      }
    }
    return -1;
  }
  else {
    return -2;
  }
}

void *assign(void *ptr) {
  int s2 = (intptr_t)ptr;
  char accion;
  char espacios;
  char *nombre;
  read(s2,&accion,1);
  if (accion == 'r') {
    int e;
    nombre = getstr(s2);
    read(s2,&espacios,1);
    int m = espacios - '0';
    pthread_mutex_lock(&mutex);
    if (estDisp(espacios) == -2) {
      fprintf(stderr, "%s\n","Numero de espacios invalido");
      exit(1);
    }
    while((e = estDisp(espacios)) == -1) {
      pthread_cond_wait(&cond,&mutex);
    }
    for (int x = e; x < e+m; x++) {
      strcpy(estacionamientos[x],nombre);
    }
    for (int k = 0; k <= 4; k++) {
      if (strcmp(estacionamientos[k],"") != 0) {
        fprintf(stderr, "%s","*");
      }
      else {
        fprintf(stderr, "%d",k);
      }
    }
    fprintf(stderr, "%s\n","");
    pthread_mutex_unlock(&mutex);
    char test = e + '0';
    write(s2,&test,1);
  }
  if (accion == 'l') {
    nombre = getstr(s2);
    pthread_mutex_lock(&mutex);
    for (int j = 0; j <= 4; j++) {
      if (strcmp(estacionamientos[j],nombre) == 0) {
        strcpy(estacionamientos[j],"");
      }
    }
    for (int k = 0; k <= 4; k++) {
      if (strcmp(estacionamientos[k],"") != 0) {
        fprintf(stderr, "%s","*");
      }
      else {
        fprintf(stderr, "%d",k);
      }
    }
    fprintf(stderr, "%s\n","");
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
  }
  close(s2);
  return NULL;
}

int main(int argc, char **argv) {
  int s;
  int port = atoi(argv[1]); // ?
  pthread_t pid;
  signal(SIGPIPE,SIG_IGN);
  printf("%s\n","01234");
  s = j_socket();
  if (j_bind(s,port) < 0) {
    fprintf(stderr, "%s\n", "fallo bind");
    exit(1);
  }
  strcpy(estacionamientos[0],"");
  strcpy(estacionamientos[1],"");
  strcpy(estacionamientos[2],"");
  strcpy(estacionamientos[3],"");
  strcpy(estacionamientos[4],"");

  for (;;) {
    intptr_t s2 = j_accept(s);
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    if (pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED) < 0) {
      fprintf(stderr, "%s\n","fallo detach state");
      exit(1);
    }
    if (pthread_create(&pid,&attr,(Thread_fun)assign,(void *)s2) != 0) {
      fprintf(stderr, "%s\n","fallo create" );
      exit(1);
    }
    pthread_attr_destroy(&attr);
  }
  return 0;
}

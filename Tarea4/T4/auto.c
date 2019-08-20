#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "jsocket.h"
#include "util.h"

// auto juan r 1
int main(int argc, char **argv) {
  char resp;
  char *port;
  char *port_name;
  int port_number;
  port = getenv("PARKING");
  const char xd[2] = ":";
  port_name = strtok(port,xd);
  port_number = atoi(strtok(NULL,xd));
  int s = j_socket();
  if (j_connect(s,port_name,port_number) < 0) {
    fprintf(stderr, "%s\n",port_name);
    fprintf(stderr, "%d\n",port_number);
    fprintf(stderr, "%s\n","fallo conexion");
    exit(1);
  }
  write(s,argv[2],1);
  sendstr(s,argv[1]);
  write(s,argv[3],1);
  read(s,&resp,1);
  printf("%c\n",resp );
  close(s);
  return 0;
}

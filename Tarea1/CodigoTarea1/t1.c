#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t1.h"

typedef unsigned int uint;

uint borrar_bits(uint x, uint pat, int len) {
    uint m = (1 << len)-1;
    uint r = x;

    while (pat < x) {
        if((x & m) == pat) {
            r &= (~m);
        }
        pat <<= 1;
        m <<= 1;
    }
    return r;
}


char * reemplazo(char *s, char c, char *pal) {
    char *l =s;
    char *l2 = pal;
    int con = 0;
    int len2 = l2-pal-1;
    int len = l-s;
    char *r = malloc(len+con);
    char *edit = r;
    while(*l2) {
        l2++;
    }
    while(*l) {
        if (*l == c) {
            con += len2-1;
        }
        l++;
    }
    for (char *p = s; p < l; p++) {
        if (*p == c) {
            for (char *q = pal; q <l2; q++) {
                *edit = *q;
                edit++;
            }
        }
        else {
            *edit = *p;
            edit++;
        }
    }
    edit++;
    *edit='\0';
    return r;
}

void reemplazar(char*s,char c, char *pal) {
    char *l = s;
    char *l2 = pal;
    int cont = 0;
    char *cl = s;
    while(*l) {
        l++;
    }
    while(*l2) {
        l2++;
    }
    while(*cl) {
        if (*cl == c) {
            cont += 1;
        }
        cl++;
    }

    if (*pal == NULL) {
        char *inicial=s;
        for (s; s < l; s++) {
            if (*s == c) {
            }
            else {
                *inicial = *s;
                inicial++;
            }
        }
        *inicial = '\0';
    }

    if (l2-pal == 1) {
        for (char *p = s; p<l; p++ ) {
            if (*p == c) {
                *p = *pal;
            }
        }
    }

    else {
        int largo_s = l-s;
        int largo_pal = l2-pal;
        char *final = l + cont * (largo_pal - 1);
        *final = '\0';
        final--;
        l--;
        for (int i = 0; i < largo_s; i++) {
            if (*l == c) {
                char *q = pal + largo_pal-1;
                for (int j = 0; j < largo_pal; j++) {
                    *final = *q;
                    final--;
                    q--;
                }
                l--;
            }
            else {
                *final = *l;
                final--;
                l--;
            }
        }
    }
}

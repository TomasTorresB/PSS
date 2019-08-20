#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "colapri.h"
#include "colapri-lista.h"

typedef struct nodo {
    void *valor;
    struct nodo *siguiente;
}Nodo;
typedef struct listaEnlazada { //estructura lista enlazada
    Nodo *nodoLista;
}ListaEnlazada;

typedef struct { //cola de prioridad
    ColaPriOps *ops; //puntero con las operaciones de la cola
    CompPri comp; //comparador para los elementos de la lista
    ListaEnlazada *lista; // lista enlazada con los elementos
    int n; //numero de elementos
} ColaPriLista;


static void agregar(ColaPri colapri, void *a);
static void* extraer(ColaPri colapri);
static void* mejor(ColaPri colapri);
static int tamano(ColaPri colapri);
static void destruir(ColaPri colapri);  /*debe estar vacia*/
static IterColaP iterador(ColaPri colapri);


static ColaPriOps colapri_lista_ops= { //operaciones en la cola
        agregar, extraer, mejor, tamano, destruir, iterador
};

/* Cola de prioridades implementada con una lista enlazada */

/* Entrega una nueva cola de prioridades:
 * comp es el comparador de prioridades
 */
ColaPri nuevaColaPriLista(CompPri comp) {
    ColaPriLista *cp = malloc(sizeof(ColaPriLista));
    cp->comp = comp;
    cp->lista = NULL;
    cp->ops = &colapri_lista_ops;
    cp->n = 0;
    return (ColaPri)cp; // cast ColaPri a puntero ColaPriLista (?)
}

static void agregar(ColaPri colapri,void *objeto) {

    ColaPriLista *cp = (ColaPriLista*) colapri;
    cp->n++;
    if (cp->lista == NULL) { //la lista enlazada esta vacia
        ListaEnlazada *nuevaLista = (ListaEnlazada *)malloc(sizeof(ListaEnlazada));
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        nuevoNodo->valor = objeto;
        nuevoNodo->siguiente = NULL;
        nuevaLista->nodoLista = nuevoNodo;
        cp->lista = nuevaLista;
    }
    else {
        Nodo **ppnodo = &cp->lista->nodoLista;
        Nodo *lista = cp->lista->nodoLista;
        while (lista != NULL)  {
            int rel = (cp->comp)(lista->valor, objeto);
            if (rel < 0) {
                ppnodo = &lista->siguiente;
                lista = *ppnodo;
            }
            else {
                break;
            }
        }
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        nuevoNodo->valor = objeto;
        nuevoNodo->siguiente = lista;
        *ppnodo = nuevoNodo;
    }
}

static void* extraer(ColaPri colapri) {
    ColaPriLista *cp = (ColaPriLista*) colapri;
    if (cp->n == 1) {
        cp->n--;
        void *result = cp->lista->nodoLista->valor;
        cp->lista = NULL;
        return  result;
    }
    else {
        cp->n--;
        void *result = cp->lista->nodoLista->valor;
        cp->lista->nodoLista = cp->lista->nodoLista->siguiente;
        return result;
    }
}

static int tamano(ColaPri colapri) {
    ColaPriLista *cp = (ColaPriLista*)colapri;
    return cp->n;
}

static void* mejor(ColaPri colapri) {
    ColaPriLista *cp = (ColaPriLista *) colapri;
    return cp->lista->nodoLista->valor;
}

static void destruir(ColaPri colapri) {
    ColaPriLista *cp = (ColaPriLista *) colapri;
    free(cp);
}

typedef struct {
    IterColaPOps *ops;
    ColaPriLista *cp;
    Nodo *Nodo;
} IterColaLista;

static int continua(IterColaP iter);
static void* proximo(IterColaP iter);
static void destruirIter(IterColaP iter);

static IterColaPOps iterOps= { continua, proximo, destruirIter };

IterColaP iterador(ColaPri colapri) {
    IterColaLista *iter= malloc(sizeof(IterColaLista));
    iter->ops= &iterOps;
    iter->cp= (ColaPriLista*)colapri;
    iter->Nodo = iter->cp->lista->nodoLista;
    return (IterColaP)iter;
}

static int continua(IterColaP itercp) {
    IterColaLista *iter= (IterColaLista*)itercp;
    return iter->Nodo != NULL;
}

static void *proximo(IterColaP itercp) {
    IterColaLista *iter= (IterColaLista*)itercp;
    void *p = iter->Nodo->valor;
    iter->Nodo = iter->Nodo->siguiente;
    return p;
}

static void destruirIter(IterColaP iter) {
    free(iter);
}
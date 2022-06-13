#ifndef LIST_FUNCTIONS
#define LIST_FUNCTIONS

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bloco Bloco;
typedef struct Item{
    char *palavra;
}Item;

struct Bloco{
    Item dado;
    Bloco *prox;
};

typedef struct Lista{
    Bloco* cabeca;
    Bloco* cauda;
}Lista;

void FLVazia(Lista *l);
void insertLista(Lista *l,char palavra[]);
void preencheLista();
void removeListaItem(Lista *l, int item);
void printLista(Lista *l);
#endif
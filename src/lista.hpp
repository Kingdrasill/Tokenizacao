#ifndef LIST_FUNCTIONS
#define LIST_FUNCTIONS

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct Bloco Bloco;
typedef struct Item{
    string palavra;
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
void preencheLista(Lista *l);
void removeListaItem(Lista *l, int item);
void printLista(Lista *l);
#endif
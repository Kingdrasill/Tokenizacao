#ifndef LIST_FUNCTIONS
#define LIST_FUNCTIONS

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct Item Item;
typedef struct Bloco Bloco;
typedef struct Lista Lista;

struct Item{
    string palavra;
};

struct Bloco{
    Item dado;
    Bloco *prox;
};

struct Lista{
    Bloco* cabeca;
    Bloco* cauda;
};

void FLVazia(Lista *l);
void insertLista(Lista *l,char palavra[]);
void preencheLista(Lista *l);
void removeListaItem(Lista *l, int item);
void printLista(Lista *l);
#endif
#ifndef LISTAPALS_HPP
#define LISTAPALS_HPP

#include "palavra.hpp"

using namespace std;

typedef struct Palavras Palavras;
typedef struct Bloco Bloco;
typedef struct ListPals ListPals;

// Estrutura que guarda uma lista de palavras de tamanho n
struct Palavras{
    WordList listPal;
    int qtd;
    int tam;
};

// Estrutura para criar uma corrente de listas de palavras
struct Bloco{
    Palavras dado;      // Dados da palavra
    Bloco *prox;    // Ponteiro para próxima palavra
};

// Estrutura que armazena a cabeça e a cauda da corrente de listas de palavras
struct ListPals{
    Bloco* cabeca;  // Início da corrente
    Bloco* cauda;   // Fim da corrente
};

void FLPTVazia(ListPals *lista);                         // Esvazia uma lista de lista de palavras
void insertLPTamanho(ListPals *lista, string palavra);        // Insere uma palavra em uma lista de palavras de tamanho n
void removeLPTamanho(ListPals *lista, string palavra);   // Remove uma uma palavra em uma lista de palavras de tamanho n
void printLPTamanho(ListPals *lista);                    // Printa uma lista de lista de palavras

#endif
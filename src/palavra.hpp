#ifndef PALAVRA_HPP
#define PALAVRA_HPP

#include <iostream>
#include <string>

using namespace std;

typedef struct Word Word;
typedef struct Block Block;
typedef struct WordList WordList;

// Estrutura que guarda os dados de uma palavra
struct Word{
    string palavra;     // Aonde a palavra é guarda mesmo
    short int qtd;      // Quantidade de vezes que a palavra apareceu
    short int value;    // O valor ASCii da palavra
    char initial;       // A inicial da palavra
};

// Estrutura para criar uma corrente de palavras
struct Block{
    Word dado;      // Dados da palavra
    Block *prox;    // Ponteiro para próxima palavra
};

// Estrutura que armazena a cabeça e a cauda da corrente de palavras
struct WordList{
    Block* cabeca;  // Início da corrente
    Block* cauda;   // Fim da corrente
};

void FLPVazia(WordList *lista);                             // Esvazia uma lista de palavras
void insertListaPalavra(WordList *lista, string palavra);   // Insere uma palavra em uma lista de palavras
int removeListaPalavra(WordList *lista, string palavra);   // Remove uma palavra de uma lista de palavras
void printListaPalavra(WordList *lista);                    // Printa uma lista de palavras
short int calcularValorPalavra(string palavra);             // Calcula o valor ASCii de uma palavra

#endif
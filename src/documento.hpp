#ifndef DOCUMENTO_HPP
#define DOCUMENTO_HPP

#include "listaPals.hpp"

using namespace std;

typedef struct Documento Documento;
typedef struct Bloque Bloque;
typedef struct ListDocument ListDocument;

// Estrutura que guarda um documento
struct Documento{
    ListPals documento;
    string nome;
    int qtd;
};

// Estrutura para criar uma corrente de documentos
struct Bloque{
    Documento dado;  // Dados do documento
    Bloque *prox;    // Ponteiro para próxima palavra
};

// Estrutura que armazena a cabeça e a cauda da corrente de documentos
struct ListDocument{
    Bloque* cabeca;  // Início da corrente
    Bloque* cauda;   // Fim da corrente
};

void FLDVazia(ListDocument *lista);                                            // Esvazia uma lista de documentos
void createDocument(ListDocument *lista, string nome);                         // Cria um novo documento
void insertLPDocument(ListDocument *lista, string nome, ListPals palavras);    // Insere palavras em um documento
void removeDocument(ListDocument *lista, string nome);                         // Remove um documento
void printLPDocument(ListDocument *lista);                                     // Printa uma lista de documentos

#endif
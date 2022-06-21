#include "documento.hpp"

// Função para esvaziar uma lista de documentos
void FLDVazia(ListDocument *lista) {
    lista->cabeca = (Bloque*)malloc(sizeof(Bloque));
    lista->cauda = lista->cabeca;
    lista->cauda->prox = NULL;
}

// Função para criar um novo documento
void createDocument(ListDocument *lista, string nome) {
    Documento doc;
    doc.nome = nome;
    doc.qtd = 0;
    FLPTVazia(&doc.documento);
    lista->cauda->prox = (Bloque*)malloc(sizeof(Bloque));
    lista->cauda = lista->cauda->prox;
    lista->cauda->dado = doc;
    lista->cauda->prox=NULL;
}

// Função para inserir palavras em um documento
void insertLPDocument(ListDocument *lista, string nome, ListPals palavras) {
    Bloque* aux;
    aux = lista->cabeca;
    while(aux->prox != NULL) {
        if(aux->prox->dado.nome == nome) {
            aux->prox->dado.documento = palavras;
        }
        aux = aux->prox;
    }
}

// Função para remover um documento
void removeDocument(ListDocument *lista, string nome) {
    Bloque *aux, *freeBloco;
    
    aux = lista->cabeca;
    while (aux->prox!=NULL)
    {
        if (aux->prox->dado.nome == nome)   // Verifica se a palavra da próxima posição tem a mesma
        {                                                                                                                       // inicial, o mesmo valor ASCii e se é a mesma palavra que
            if (aux->prox == lista->cauda)                                                                                      // a palavra dada
            {
                free(aux->prox);
                aux->prox = NULL;
                lista->cauda = aux;
            }
            else {
                freeBloco = aux->prox;
                aux->prox = aux->prox->prox;
                free(freeBloco);
            }
        }
        else {
            aux=aux->prox;
        }
    }
}

// Função para printar uma lista de documentos
void printLPDocument(ListDocument *lista) {
    Bloque* aux;
    aux = lista->cabeca;
    while (aux->prox != NULL)
    {
        cout << "Documento " << aux->prox->dado.nome << ": " << endl;
        printLPTamanho(&aux->prox->dado.documento);
        aux=aux->prox;
    }
}
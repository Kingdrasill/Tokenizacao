#include "documento.hpp"

// Função para criar um novo documento
void createDocument(List<Documento> *lista, std::string nome) {
    Documento doc;
    doc.nome = nome;
    doc.qtd = 0;
    FLVazia(&doc.documento);
    lista->cauda->prox = new Block<Documento>;
    lista->cauda = lista->cauda->prox;
    lista->cauda->dado = doc;
    lista->cauda->prox=nullptr;
}

// Função para inserir palavras em um documento
void insertLPDocument(List<Documento> *lista, std::string nome, List<Palavras> palavras) {
    Block<Documento>* aux;
    aux = lista->cabeca;
    while(aux->prox != nullptr) {
        if(aux->prox->dado.nome == nome) {
            aux->prox->dado.documento = palavras;
        }
        aux = aux->prox;
    }
}

// Função para remover um documento
void removeDocument(List<Documento> *lista, std::string nome) {
    Block<Documento> *aux, *freeBloco;
    
    aux = lista->cabeca;
    while (aux->prox!=nullptr)
    {
        if (aux->prox->dado.nome == nome)   // Verifica se a palavra da próxima posição tem a mesma
        {                                                                                                                       // inicial, o mesmo valor ASCii e se é a mesma palavra que
            if (aux->prox == lista->cauda)                                                                                      // a palavra dada
            {
                free(aux->prox);
                aux->prox = nullptr;
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
void printLPDocument(List<Documento> *lista) {
    Block<Documento>* aux;
    aux = lista->cabeca;
    while (aux->prox != nullptr)
    {
        printf("Documento %s: \n", aux->prox->dado.nome.c_str());
        printLPTamanho(&aux->prox->dado.documento);
        aux=aux->prox;
    }
}
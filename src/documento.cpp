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
    lista->qtd++;
}

// Função para inserir palavras em um documento
void insertLPDocument(List<Documento> *lista, std::string nome, List<Palavras> palavras) {
    Block<Documento>* aux;
    aux = lista->cabeca;
    while(aux->prox != nullptr) {
        if(aux->prox->dado.nome == nome) {
            aux->prox->dado.documento = palavras;
            aux->prox->dado.qtd = palavras.qtd;
        }
        aux = aux->prox;
    }
}

// Função para remover um documento
void removeDocument(List<Documento> *lista, std::string nome) {
    Block<Documento> *aux, *freeBloco;
    bool removed = false;
    aux = lista->cabeca;
    while (aux->prox!=nullptr)
    {
        if (aux->prox->dado.nome == nome)   // Verifica se a palavra da próxima posição tem a mesma
        {  
            removed = true;                                                                                                                     // inicial, o mesmo valor ASCii e se é a mesma palavra que
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
    if(removed)
        lista->qtd--;
}

// Função para remover uma palavra de todos documentos
void removeWordFromDocuments(List<Documento> *lista, std::string palavra) {
    Block<Documento> *aux;

    aux = lista->cabeca;
    while(aux->prox != nullptr) {
        aux = aux->prox;
        int x = removeLPTamanho(&aux->dado.documento, palavra);
        aux->dado.documento.qtd =aux->dado.documento.qtd-x;
        aux->dado.qtd = aux->dado.qtd - x;
    }
}

// Função para printar uma lista de documentos
void printLPDocument(List<Documento> *lista) {
    Block<Documento>* aux;
    aux = lista->cabeca;
    while (aux->prox != nullptr)
    {
        printf("Documento %s,%d: \n", aux->prox->dado.nome.c_str(), aux->prox->dado.qtd);
        printLPTamanho(&aux->prox->dado.documento);
        aux=aux->prox;
    }
}


/// Verifica em quantos documentos uma palavra aparece
float calculaAparicaoPalavra(List<Documento> *lista,std::string palavra)
{
    Block<Documento> *aux;
    float soma=0;

    aux=lista->cabeca;
    while (aux->prox!=nullptr)
    {
        if(buscaLPTamanho(&aux->prox->dado.documento,palavra)==true)
            soma++;
        aux=aux->prox;    
    }

    return soma;
}


bool buscaPDocument(Block<Documento>*doc,std::string palavra)
{
    return buscaLPTamanho(&doc->dado.documento,palavra);
}

// Função para printar uma lista de documentos por relevância
void printDocOrd(List<Documento> *lista) {
    Block<Documento>* aux;
    aux = lista->cabeca;
    short int cont=1;
    while (aux->prox != nullptr)
    {
        printf("%dº Documento: %s\n", cont,aux->prox->dado.nome.c_str());
        aux=aux->prox;
        cont++;
    }
}
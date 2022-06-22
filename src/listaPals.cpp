# include "listaPals.hpp"

// Função para esvaziar uma lista de lista de palavras
void FLPTVazia(ListPals *lista) {
    lista->cabeca = new Bloco;
    lista->cauda = lista->cabeca;
    lista->cauda->prox = nullptr;
}

// Função para inserir uma palavra em uma lista de palavras de tamanho n
void insertLPTamanho(ListPals *lista, std::string palavra) {
    Palavras palavras;
    int tam = static_cast<int> (palavra.size());
    palavras.tam = tam;

    if(lista->cabeca == lista->cauda)   // Caso a lista esteja vazia
    {
        palavras.qtd = 1;
        palavras.tam = tam;
        FLPVazia(&palavras.listPal);
        insertListaPalavra(&palavras.listPal, palavra);  // Inseri a palavra na lista de palavra de tamanha n

        lista->cauda->prox = new Bloco;
        lista->cauda = lista->cauda->prox;
        lista->cauda->dado = palavras;
        lista->cauda->prox=nullptr;
    }
    else {
        Bloco* tmp = new Bloco; // Caso necessário um novo elemento na lista
        Bloco* aux;                                 // Variável auxiliar para andar na lista

        aux = lista->cabeca;
        while (aux->prox != nullptr && aux->prox->dado.tam < tam) {
            aux = aux->prox;
        }

        if(aux->prox != nullptr && aux->prox->dado.tam == tam)
        {
            aux->prox->dado.qtd++;
            insertListaPalavra(&aux->prox->dado.listPal, palavra);
        }
        else {
            palavras.qtd = 1;
            palavras.tam = tam;
            FLPVazia(&palavras.listPal);
            insertListaPalavra(&palavras.listPal, palavra);  // Inseri a palavra na lista de palavra de tamanha n

            tmp->dado = palavras;
            tmp->prox = aux->prox;
            aux->prox = tmp;
            if(tmp->prox == nullptr)
                lista->cauda = tmp;
        }
    }
}

// Função para remover uma uma palavra em uma lista de palavras de tamanho n
int removeLPTamanho(ListPals *lista, std::string palavra) {
    Bloco* aux;
    int tam = static_cast<int> (palavra.size());
    int removed = 0;

    aux = lista->cabeca;
    while(aux->prox != nullptr) {
        if(aux->prox->dado.tam == tam) {
            removed = removeListaPalavra(&aux->prox->dado.listPal, palavra);
            aux->prox->dado.qtd = aux->prox->dado.qtd - removed;
        }
        aux = aux->prox;
    }

    return removed;
}

// Função para printar uma lista de lista de palavras de tamanho n
void printLPTamanho(ListPals *lista) {
    Bloco* aux;
    aux = lista->cabeca;
    while (aux->prox != nullptr)
    {
        printf("Palavras de tamanho %d - Quantidade %d :\n", aux->prox->dado.tam, aux->prox->dado.qtd);
        printListaPalavra(&aux->prox->dado.listPal);
        aux=aux->prox;
    }
}
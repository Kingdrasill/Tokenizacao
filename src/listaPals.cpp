# include "listaPals.hpp"

// Função para esvaziar uma lista de lista de palavras
void FLPTVazia(ListPals *lista) {
    lista->cabeca = (Bloco*)malloc(sizeof(Bloco));
    lista->cauda = lista->cabeca;
}

// Função para inserir uma palavra em uma lista de palavras de tamanho n
void insertLPTamanho(ListPals *lista, string palavra) {
    Palavras palavras;
    int tam = (int)palavra.size();
    palavras.tam = tam;

    if(lista->cabeca == lista->cauda)   // Caso a lista esteja vazia
    {
        palavras.qtd = 1;
        palavras.tam = tam;
        FLPVazia(&palavras.listPal);
        insertListaPalavra(&palavras.listPal, palavra);  // Inseri a palavra na lista de palavra de tamanha n

        lista->cauda->prox = (Bloco*)malloc(sizeof(Bloco));
        lista->cauda = lista->cauda->prox;
        lista->cauda->dado = palavras;
        lista->cauda->prox=NULL;
    }
    else {
        Bloco* tmp = (Bloco*)malloc(sizeof(Bloco)); // Caso necessário um novo elemento na lista
        Bloco* aux;                                 // Variável auxiliar para andar na lista

        aux = lista->cabeca;
        while (aux->prox != NULL && aux->prox->dado.tam < tam) {
            aux = aux->prox;
        }

        if(aux->prox != NULL && aux->prox->dado.tam == tam)
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
            if(tmp->prox == NULL)
                lista->cauda = tmp;
        }
    }
}

// Arrumar este !!!!!!!!!!!!!!!!!!!!!!!!
// Função para remover uma uma palavra em uma lista de palavras de tamanho n
void removeLPTamanho(ListPals *lista, string palavra) {
    Bloco* aux;
    int tam = (int)palavra.size();

    aux = lista->cabeca;
    while(aux->prox != NULL) {
        if(aux->prox->dado.tam == tam) {
            int removed = removeListaPalavra(&aux->prox->dado.listPal, palavra);
            aux->prox->dado.qtd = aux->prox->dado.qtd - removed;
        }
    }
}

// Função para printar uma lista de lista de palavras de tamanho n
void printLPTamanho(ListPals *lista) {
    Bloco* aux;
    aux = lista->cabeca;
    while (aux->prox != NULL)
    {
        cout << "Palavras de tamanho " << aux->prox->dado.tam << ":" << endl;
        printListaPalavra(&aux->prox->dado.listPal);
        aux=aux->prox;
    }
    printf("\n");
}
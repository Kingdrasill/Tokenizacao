#include "palavra.hpp"

// Função para esvaziar luma lista de palavras
void FLPVazia(WordList *lista) {
    lista->cabeca = (Block*)malloc(sizeof(Block));
    lista->cauda = lista->cabeca;
    lista->cauda->prox = NULL;
}

// Função para inserir uma palavra em uma lista de palavras
void insertListaPalavra(WordList *lista, Word word) {
    word.initial = word.palavra.at(0);
    word.value = calcularValorPalavra(word.palavra);

    if(lista->cabeca != lista->cauda)               // Caso a lista não esteja vazia
    {
        Block* tmp = (Block*)malloc(sizeof(Block)); // Novo elemento na lista
        Block* aux;                                 // Variável auxiliar para andar na lista

        tmp->dado = word;
        aux = lista->cabeca;
        while (aux->prox != NULL && aux->prox->dado.value < word.value) {   // Achar a posição em que a nova palavra deve ser inserida, está posição
            aux = aux->prox;                                                // é em que o valor ASCii da palavra é maior do que o valor da palavra anterior
        }
        tmp->prox = aux->prox;
        aux->prox = tmp;
        if(tmp->prox == NULL)
            lista->cauda = tmp;
    } 
    else {        // Caso a lista estiver vazia adionar a palavra de uma vez na lista
        lista->cauda->prox = (Block*)malloc(sizeof(Block));
        lista->cauda = lista->cauda->prox;
        lista->cauda->dado = word;
        lista->cauda->prox=NULL;
    }
}

// Função para remover uma palavra de uma lista de palavras
void removeListaPalavra(WordList *lista, string palavra) {
    Block *aux, *freeBloco;
    short int valor = calcularValorPalavra(palavra);
    
    aux = lista->cabeca;
    while (aux->prox!=NULL)
    {
        if (aux->prox->dado.initial == palavra.at(0) && aux->prox->dado.value == valor && aux->prox->dado.palavra == palavra)   // Verifica se a palavra da próxima posição tem a mesma
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

// Função para printar uma lista de palavras
void printListaPalavra(WordList *lista) {
    Block* aux;
    aux = lista->cabeca;
    while (aux->prox != NULL)
    {
        cout<< aux->prox->dado.palavra << "\t" << aux->prox->dado.initial << "\t" << aux->prox->dado.value << endl;
        aux=aux->prox;
    }
    printf("\n");
}

// Função para calcula o valor ASCii de uma palavra
short int calcularValorPalavra(string palavra) {
    short int value = 0;

    for(size_t i=0; i < palavra.size(); i++) {    // Pega o valor ASCii de cada caracter de uma palavra e os soma
        value += palavra[i];
    }

    return value;
}
#include "palavra.hpp"

// Função para inserir uma palavra em uma lista de palavras
void insertListaPalavra(List<Word> *lista, std::string palavra) {
    Word word;
    word.palavra = palavra;
    word.qtd = 1;
    word.initial = palavra.at(0);
    word.value = calcularValorPalavra(palavra);

    if(lista->cabeca != lista->cauda)               // Caso a lista não esteja vazia
    {
        Block<Word>* tmp = new Block<Word>; // Novo elemento na lista
        Block<Word>* aux;                                 // Variável auxiliar para andar na lista

        tmp->dado = word;
        aux = lista->cabeca;
        while (aux->prox != nullptr && aux->prox->dado.value < word.value) {   // Achar a posição em que a nova palavra deve ser inserida, está posição
            aux = aux->prox;                                                   // é em que o valor ASCii da palavra é maior do que o valor da palavra anterior
        }
        if(aux->prox != nullptr && aux->prox->dado.value == word.value && aux->prox->dado.initial == word.initial && aux->prox->dado.palavra == word.palavra)
        {
            aux->prox->dado.qtd++;
        }
        else {
            tmp->prox = aux->prox;
            aux->prox = tmp;
            if(tmp->prox == nullptr)
                lista->cauda = tmp;
        }
    } 
    else {        // Caso a lista estiver vazia adionar a palavra de uma vez na lista
        lista->cauda->prox = new Block<Word>;
        lista->cauda = lista->cauda->prox;
        lista->cauda->dado = word;
        lista->cauda->prox=nullptr;
    }
    lista->qtd++;
}

// Função para remover uma palavra de uma lista de palavras
int removeListaPalavra(List<Word> *lista, std::string palavra) {
    int removed = 0;
    Block<Word> *aux, *freeBloco;
    short int valor = calcularValorPalavra(palavra);
    
    aux = lista->cabeca;
    while (aux->prox!=nullptr)
    {
        if (aux->prox->dado.value == valor && aux->prox->dado.initial == palavra.at(0) && aux->prox->dado.palavra == palavra)   // Verifica se a palavra da próxima posição tem a mesma
        {                                                                                                                       // inicial, o mesmo valor ASCii e se é a mesma palavra que
            if (aux->prox == lista->cauda)                                                                                      // a palavra dada
            {
                removed = aux->prox->dado.qtd;
                free(aux->prox);
                aux->prox = nullptr;
                lista->cauda = aux;
            }
            else {
                freeBloco = aux->prox;
                removed = freeBloco->dado.qtd;
                aux->prox = aux->prox->prox;
                free(freeBloco);
            }
        }
        else {
            aux=aux->prox;
        }
    }

    lista->qtd = lista->qtd - removed;

    if(lista->cabeca == lista->cauda && lista->qtd > 0) {
        removed += lista->qtd;
        lista->qtd = lista->qtd - removed;
    }

    return removed;
}

// Função para printar uma lista de palavras
void printListaPalavra(List<Word> *lista) {
    Block<Word>* aux;
    aux = lista->cabeca;
    while (aux->prox != nullptr)
    {
        printf("%s\t %c\t%d\t%d\n",aux->prox->dado.palavra.c_str(), aux->prox->dado.initial, aux->prox->dado.value, aux->prox->dado.qtd);
        aux=aux->prox;
    }
    printf("\n");
}

// Função para calcula o valor ASCii de uma palavra
short int calcularValorPalavra(std::string palavra) {
    short int value = 0;

    for(size_t i=0; i < palavra.size(); i++) {    // Pega o valor ASCii de cada caracter de uma palavra e os soma
        value += palavra[i];
    }

    return value;
}
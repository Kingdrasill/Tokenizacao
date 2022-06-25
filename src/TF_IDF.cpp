#include "TF_IDF.hpp"

float TF(List<Documento>*list)
{
    Block<Documento> *aux;
    Block<Palavras> *percorre;
    Block<Word> *palavras;

    aux=list->cabeca;
    while (aux->prox!=nullptr)
    {
        percorre=aux->prox->dado.documento.cabeca;
        while(percorre->prox!=nullptr)
        {
            palavras=percorre->prox->dado.listPal.cabeca;
            while(palavras->prox!=nullptr)
            {
                palavras->prox->dado.tf=(palavras->prox->dado.qtd/aux->prox->dado.qtd);
                palavras=palavras->prox;
            }
            percorre=percorre->prox;
        }
        aux=aux->prox;
    }
}

float IDF(List<Documento>*list)
{
    Block<Documento> *aux;
    Block<Palavras> *percorre;
    Block<Word> *palavras;

    aux=list->cabeca;
    while (aux->prox!=nullptr)
    {
        percorre=aux->prox->dado.documento.cabeca;
        while(percorre->prox!=nullptr)
        {
            palavras=percorre->prox->dado.listPal.cabeca;
            while(palavras->prox!=nullptr)
            {
                palavras->prox->dado.idf=log10(aux->dado.qtd/palavras->dado.qtdapa);
                palavras=palavras->prox;
            }
            percorre=percorre->prox;
        }
        aux=aux->prox;
    }
}

float TFIDF(List<Documento>*list)
{
    Block<Documento> *aux;
    Block<Palavras> *percorre;
    Block<Word> *palavras;

    aux=list->cabeca;
    while (aux->prox!=nullptr)
    {
        percorre=aux->prox->dado.documento.cabeca;
        while(percorre->prox!=nullptr)
        {
            palavras=percorre->prox->dado.listPal.cabeca;
            while(palavras->prox!=nullptr)
            {
                palavras->prox->dado.tfidf=(palavras->prox->dado.tf*palavras->prox->dado.idf);
                palavras=palavras->prox;
            }
            percorre=percorre->prox;
        }
        aux=aux->prox;
    }

}
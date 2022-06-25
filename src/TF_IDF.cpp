#include "TF_IDF.hpp"

void TF(List<Documento>*list)
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
                palavras->prox->dado.tfidf=((palavras->prox->dado.qtd)/(static_cast<float> (aux->prox->dado.qtd)));
                palavras=palavras->prox;
            }
            percorre=percorre->prox;
        }
        aux=aux->prox;
    }
    IDF(list);
}

void IDF(List<Documento>*list)
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
                if(buscaPDocument(aux->prox,palavras->prox->dado.palavra))
                {
                   palavras->prox->dado.tfidf=1*log10(aux->dado.qtd/calculaAparicaoPalavra(list,palavras->prox->dado.palavra)); 
                }
                palavras=palavras->prox;
            }
            percorre=percorre->prox;
        }
        aux=aux->prox;
    }
}
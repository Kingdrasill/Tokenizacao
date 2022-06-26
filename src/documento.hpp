#ifndef DOCUMENTO_HPP
#define DOCUMENTO_HPP

#include "listaPals.hpp"

// Estrutura que guarda um documento
struct Documento{
    List<Palavras> documento;
    std::string nome;
    int qtd;
    float value;
};

void createDocument(List<Documento> *lista, std::string nome);                               // Cria um novo documento
void insertLPDocument(List<Documento> *lista, std::string nome, List<Palavras> palavras);    // Insere palavras em um documento
void removeDocument(List<Documento> *lista, std::string nome);                               // Remove um documento
void removeWordFromDocuments(List<Documento> *lista, std::string palavra);                        // Remove uma palavra de todos documentos
void printLPDocument(List<Documento> *lista);                                                // Printa uma lista de documentos
void removeDocument(List<Documento> *lista, std::string nome);                         // Remove um documento
void printLPDocument(List<Documento> *lista);                                     // Printa uma lista de documentos
int calculaAparicaoPalavra(List<Documento> *lista,std::string palavra);     /// Verifica em quantos documentos uma palavra aparece
bool buscaPDocument(Block<Documento>*doc, std::string palavra);
void printDocOrd(List<Documento> *lista);                                                    //Printa documentos de uma lista ja ordenada

#endif
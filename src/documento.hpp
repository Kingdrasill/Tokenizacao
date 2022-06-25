#ifndef DOCUMENTO_HPP
#define DOCUMENTO_HPP

#include "listaPals.hpp"

// Estrutura que guarda um documento
struct Documento{
    List<Palavras> documento;
    std::string nome;
    int qtd;
};

void createDocument(List<Documento> *lista, std::string nome);                         // Cria um novo documento
void insertLPDocument(List<Documento> *lista, std::string nome, List<Palavras> palavras);    // Insere palavras em um documento
void removeDocument(List<Documento> *lista, std::string nome);                         // Remove um documento
void printLPDocument(List<Documento> *lista);                                     // Printa uma lista de documentos
int calculaAparicaoPalavra(std::string palavra);      /// Verifica em quantos documentos uma palavra aparece
#endif
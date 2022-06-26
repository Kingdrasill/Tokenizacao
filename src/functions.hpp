#ifndef FILE_ENTRY
#define FILE_ENTRY

#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "documento.hpp"

void preencheLista(List<Documento> *l);
void preencheListaStpW(List<Palavras> *lPal);
void removeStopWords(List<Documento> *docs, List<Palavras> *stopWords);
void ranking(List<Documento> *lDoc);
void BubbleSort(List<Documento> *Doc);
Block<Documento>* CaminharAteJ(List<Documento> *Doc,Block<Documento> *auxj);
void swap(Block<Documento> *auxj,Block<Documento> *auxi);

#endif
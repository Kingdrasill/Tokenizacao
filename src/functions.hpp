#ifndef FILE_ENTRY
#define FILE_ENTRY

#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <chrono>
#include "documento.hpp"

std::chrono::steady_clock::time_point preencheLista(List<Documento> *l);
void preencheListaStpW(List<Palavras> *lPal);
void removeStopWords(List<Documento> *docs, List<Palavras> *stopWords);
std::chrono::steady_clock::time_point ranking(List<Documento> *lDoc);
void BubbleSort(List<Documento> *Doc);
void swap(Block<Documento> *auxj,Block<Documento> *auxi);

#endif
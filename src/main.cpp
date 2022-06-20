#include "palavra.hpp"

int main(){
	WordList L;
	Word aux;
	string palavra = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int i=0;

	FLPVazia(&L);
	
	while(i < 1000) {
		for(size_t j=0; j<palavra.size(); j++) {
			palavra.at(j) = static_cast<char>(rand()%93+33);
		}
		aux.palavra = palavra;
		insertListaPalavra(&L, aux);
		i++;
	}

	printListaPalavra(&L);

	return 0;
}

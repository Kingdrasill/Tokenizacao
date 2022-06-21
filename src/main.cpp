#include "listaPals.hpp"

int main(){
	ListPals L;
	string palavra;

	FLPTVazia(&L);
	
	palavra = "ola";
	insertLPTamanho(&L, palavra);
	palavra = "ola";
	insertLPTamanho(&L, palavra);
	palavra = "olo";
	insertLPTamanho(&L, palavra);
	palavra = "casa";
	insertLPTamanho(&L, palavra);
	palavra = "casal";
	insertLPTamanho(&L, palavra);
	palavra = "carpinteiro";
	insertLPTamanho(&L, palavra);

	printLPTamanho(&L);

	return 0;
}

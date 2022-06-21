#include "documento.hpp"

int main(){
	ListDocument LD;
	ListPals L;
	string palavra;

	FLDVazia(&LD);
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

	palavra = "doc1.txt";
	createDocument(&LD, palavra);
	insertLPDocument(&LD, palavra, L);
	
	palavra = "doc2.txt";
	createDocument(&LD, palavra);
	insertLPDocument(&LD, palavra, L);

	printLPDocument(&LD);

	return 0;
}

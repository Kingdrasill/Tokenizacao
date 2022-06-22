#include "lista.hpp"

int main(){
	List<Documento> LD;
	List<Palavras> StpW;
	FLVazia(&LD);
	FLVazia(&StpW);
	preencheLista(&LD);
	preencheListaStpW(&StpW);
	printLPDocument(&LD);
	printLPTamanho(&StpW);

	return 0;
}

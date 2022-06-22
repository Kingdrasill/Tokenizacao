#include "lista.hpp"

int main(){
	ListDocument LD;
	ListPals StpW;
	FLDVazia(&LD);
	FLPTVazia(&StpW);
	preencheLista(&LD);
	preencheListaStpW(&StpW);
	printLPDocument(&LD);
	printLPTamanho(&StpW);

	return 0;
}

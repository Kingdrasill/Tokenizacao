#include "lista.hpp"

int main(){
	ListDocument LD;
	ListPals StpW;
	FLDVazia(&LD);
	FLPTVazia(&StpW);
	preencheLista(&LD);
	printLPDocument(&LD);
	printLPTamanho(&StpW);

	return 0;
}

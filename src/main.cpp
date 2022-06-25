#include "TF_IDF.hpp"

int main(){
	List<Documento> LD;
	List<Palavras> StpW;
	FLVazia(&LD);
	FLVazia(&StpW);
	preencheLista(&LD);
	preencheListaStpW(&StpW);
	TF(&LD);
	printLPDocument(&LD);
	///printLPTamanho(&StpW);

	return 0;
}

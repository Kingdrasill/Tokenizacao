#include "TF_IDF.hpp"

int main(){
	List<Documento> LD;
	List<Palavras> StpW;
	std::string palavra;
	std::string nome;
	FLVazia(&LD);
	FLVazia(&StpW);
	preencheLista(&LD);
	preencheListaStpW(&StpW);
	removeStopWords(&LD, &StpW);
	printLPDocument(&LD);
	TF(&LD);
	///printLPTamanho(&StpW);

	return 0;
}

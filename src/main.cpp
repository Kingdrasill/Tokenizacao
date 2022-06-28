#include "TF_IDF.hpp"

int main(){
	List<Documento> LD;
	List<Palavras> StpW;
	char resposta='S';
	FLVazia(&LD);
	FLVazia(&StpW);
	preencheLista(&LD);
	preencheListaStpW(&StpW);
	removeStopWords(&LD, &StpW);
	TF(&LD);
	while (resposta=='S')
	{
		ranking(&LD);
		//printf("Deseja buscar outra frase? (S/N)\n");
		//std::cin.ignore(10000, '\n');
		//std::cin>>resposta;
		//resposta=std::toupper(resposta);
		resposta='N';
	}

	return 0;
}

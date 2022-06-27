#include "TF_IDF.hpp"

int main(){
	List<Documento> LD;
	List<Palavras> StpW;
	char resposta='S';
	FLVazia(&LD);
	FLVazia(&StpW);
	std::chrono::steady_clock::time_point comeco=preencheLista(&LD);
	preencheListaStpW(&StpW);
	removeStopWords(&LD, &StpW);
	TF(&LD);
	while (resposta=='S')
	{
		std::chrono::steady_clock::time_point fim=ranking(&LD);
		printf("%ld\n", std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count());
		printDocOrd(&LD);
		printf("Deseja buscar outra frase? (S/N)\n");
		std::cin.ignore(10000, '\n');
		std::cin>>resposta;
		resposta=std::toupper(resposta);
	}

	return 0;
}
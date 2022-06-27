#include "TF_IDF.hpp"

int main(){
	List<Documento> LD;
	List<Palavras> StpW;
	char resposta='S';
	FLVazia(&LD);
	FLVazia(&StpW);
	std::chrono::steady_clock::time_point time = preencheLista(&LD);
	preencheListaStpW(&StpW);
	removeStopWords(&LD, &StpW);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	printf("%ld\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - time).count());
	TF(&LD);
	while (resposta=='S')
	{
		ranking(&LD);
		printDocOrd(&LD);
		printf("Deseja buscar outra frase? (S/N)\n");
		std::cin.ignore(10000, '\n');
		std::cin>>resposta;
		resposta=std::toupper(resposta);
	}

	return 0;
}
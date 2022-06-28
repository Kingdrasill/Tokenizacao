#include "TF_IDF.hpp"

int main(){
	std::chrono::steady_clock::time_point comeco = std::chrono::steady_clock::now();
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
	std::chrono::steady_clock::time_point fim=std::chrono::steady_clock::now();
	printf("%ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count());
	return 0;
}

#include "functions.hpp"

void preencheLista(List<Documento> *lDoc){
	List<Palavras> lPal;
    std::fstream myFile;
    int quantidadeArquivos;
    std::string nomeArquivo,caminho,palavras,linha;
	printf("Quantos arquivos deseja inserir?\n");
    scanf("%d\n",&quantidadeArquivos);
	printf("Escreva o nome dos arquivos:\n");
    for (int i = 0; i < quantidadeArquivos; i++)
    {
        getline(std::cin, nomeArquivo);
	    createDocument(lDoc, nomeArquivo);
    }
    Block<Documento> *aux;
    aux=lDoc->cabeca;
    while (aux->prox!=nullptr)
    {
	    FLVazia(&lPal);
        caminho="arquivos/";
        myFile.open(caminho.append(aux->prox->dado.nome));
        if (!myFile)
            printf("Arquivo não encontrado\n");
        else{
            while (getline(myFile,linha,'\n'))
            {
                std::stringstream X(linha);
                while (getline(X, palavras, ' ')){
                    if (palavras.size()>0)
                    {
                        while(palavras.back() == ',' || palavras.back() =='.' || palavras.back() =='!' || palavras.back() =='?' || palavras.back() ==';' || palavras.back() ==':' || palavras.back() ==')' || palavras.back() =='-' || palavras.back() =='\'' || palavras.back() =='\"' || palavras.back() =='/')
                            palavras.pop_back();
                        while(palavras.front()=='('||palavras.front()=='-'||palavras.front()=='\''||palavras.front()=='\"')
                            palavras.erase(palavras.begin());
                        std::transform(palavras.begin(), palavras.end(), palavras.begin(),[](unsigned char c){ return std::tolower(c); });
                        insertLPTamanho(&lPal,palavras);
                    }
                }
            }
            insertLPDocument(lDoc,aux->prox->dado.nome,lPal);
        }
        aux=aux->prox;
        myFile.close();
    }
    
}
void preencheListaStpW(List<Palavras> *lPal){
    std::fstream myFile;
    std::string caminho,palavras;
    caminho="arquivos/stopwords.txt";
    myFile.open(caminho);
    if (!myFile)
        printf("Arquivo não encontrado\n");
    else{
        while (getline(myFile,palavras,'\n')){
            if (palavras.back()==' ')
                palavras.pop_back();
            insertLPTamanho(lPal,palavras);
        }
    }
    myFile.close();
    
}


void removeStopWords(List<Documento> *docs, List<Palavras> *stopWords) {
    Block<Palavras> *SWRunner;
    Block<Word> *WordRunner;

    SWRunner = stopWords->cabeca;
    while(SWRunner->prox != NULL) {
        SWRunner = SWRunner->prox;
        WordRunner = SWRunner->dado.listPal.cabeca;
        while(WordRunner->prox != NULL) {
            WordRunner = WordRunner->prox;
            removeWordFromDocuments(docs, WordRunner->dado.palavra);
        }
    }

    FLVazia(stopWords);
}
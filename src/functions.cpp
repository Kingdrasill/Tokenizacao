#include "functions.hpp"

void preencheLista(List<Documento> *lDoc){
    Block<Documento> *aux;
    List<Palavras> lPal;
    std::fstream myFile;
    int quantidadeArquivos, valor;
    std::string nomeArquivo,caminho,palavras,linha;
	printf("Quantos arquivos deseja inserir?\n");
    scanf("%d",&quantidadeArquivos);
	printf("Escreva o nome dos arquivos:\n");
    for (int i = 0; i < quantidadeArquivos; i++)
    {
        caminho="arquivos/";
        std::cin>>nomeArquivo;
        myFile.open(caminho.append(nomeArquivo));
        if (!myFile)
            printf("Arquivo não encontrado\n");
        else
	        createDocument(lDoc, nomeArquivo);
        myFile.close();
    }
    aux=lDoc->cabeca;
    while (aux->prox!=nullptr)
    {
        caminho="arquivos/";
	    FLVazia(&lPal);
        myFile.open(caminho.append(aux->prox->dado.nome));
        while (getline(myFile,linha,'\n'))
        {
            linha.append(" ");
            std::stringstream X(linha);
            while (getline(X, palavras, ' ')){
                while(palavras.back() == ',' || palavras.back() =='.' || palavras.back() =='!' || palavras.back() =='?' || palavras.back() ==';' || palavras.back() ==':' || palavras.back() ==')' || palavras.back() =='-' || palavras.back() =='\'' || palavras.back() =='\"' || palavras.back() =='/')
                    palavras.pop_back();
                while(palavras.front()=='('||palavras.front()=='-'||palavras.front()=='\''||palavras.front()=='\"')
                    palavras.erase(palavras.begin());
                valor=palavras[1];
                if(palavras.front()==-61 && valor>=-128 && valor<=-99)
                    palavras[1]=palavras[1]+32;
                std::transform(palavras.begin(), palavras.end(), palavras.begin(),[](unsigned char c){ return std::tolower(c); });
                if (palavras.size()>0)
                    insertLPTamanho(&lPal,palavras);
            }
        }
        insertLPDocument(lDoc,aux->prox->dado.nome,lPal);
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
        printf("Arquivo stopwords não encontrado\n");
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
    while(SWRunner->prox != nullptr) {
        SWRunner = SWRunner->prox;
        WordRunner = SWRunner->dado.listPal.cabeca;
        while(WordRunner->prox != nullptr) {
            WordRunner = WordRunner->prox;
            removeWordFromDocuments(docs, WordRunner->dado.palavra);
        }
    }
    FLVazia(stopWords);
}

void ranking(List<Documento> *Doc){
    Block<Documento> *docRunner;
    std::string linha,palavra;
    linha="avanço tecnológico";
    linha.append(" ");

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    docRunner = Doc -> cabeca;
    while(docRunner->prox != nullptr) {
        docRunner->prox->dado.value = 0;
        std::stringstream X(linha);
        while(getline(X, palavra, ' ')){
            std::transform(palavra.begin(), palavra.end(), palavra.begin(),[](unsigned char c){ return std::tolower(c); });
            docRunner->prox->dado.value = docRunner->prox->dado.value + buscaTFIDF(&docRunner->prox->dado.documento, palavra);
        }
        docRunner = docRunner->prox;
    }
    BubbleSort(Doc);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	printf("%ld\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count());
}
void BubbleSort(List<Documento> *Doc){
    Block<Documento> *auxi,*auxj;
    auxi=Doc->cabeca->prox;
    while(auxi->prox!=nullptr){
        auxj=auxi->prox;
        while(auxj!=nullptr){
            if (auxj->dado.value>auxi->dado.value)
                swap(auxj,auxi);
            auxj=auxj->prox;
        }					
        auxi=auxi->prox;
    }
}

void swap(Block<Documento> *a,Block<Documento> *b){
	Documento aux;
    aux=a->dado;
    a->dado=b->dado;
    b->dado=aux;
}
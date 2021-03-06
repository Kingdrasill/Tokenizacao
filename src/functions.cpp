#include "functions.hpp"

void preencheLista(List<Documento> *lDoc){
    Block<Documento> *aux;
    List<Palavras> lPal;
    std::fstream myFile;
    int quantidadeArquivos=6, valor;
    std::string nomeArquivo,caminho,palavras,linha;
    std::string arquivos[6]={"filosofia.txt","filosofia2.txt","globalizacao.txt","politica.txt","ti.txt","ti2.txt"};
    
	//printf("Quantos arquivos deseja inserir?\n");
    //scanf("%d",&quantidadeArquivos);
	//printf("Escreva o nome dos arquivos:\n");
    for (int i = 0; i < quantidadeArquivos; i++)
    {
        caminho="arquivos/";
        //std::cin>>nomeArquivo;
        nomeArquivo=arquivos[i];
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
    std::fstream myFile;
    Block<Documento> *docRunner;
    std::string linha,palavra;
    int valor;

    // printf("Escreva a Frase que deseja procurar:\n");
    // std::cin>>linha;
    myFile.open("arquivos/frases.txt");
    if (!myFile)
        printf("Arquivo não encontrado\n");
    else{
        while (getline(myFile,linha,'\n'))
        {
            linha.append(" ");

            docRunner = Doc -> cabeca;
            while(docRunner->prox != nullptr) {
                docRunner->prox->dado.value = 0;
                std::stringstream X(linha);
                while(getline(X, palavra, ' ')){
                    while(palavra.back() == ',' || palavra.back() =='.' || palavra.back() =='!' || palavra.back() =='?' || palavra.back() ==';' || palavra.back() ==':' || palavra.back() ==')' || palavra.back() =='-' || palavra.back() =='\'' || palavra.back() =='\"' || palavra.back() =='/')
                        palavra.pop_back();
                    while(palavra.front()=='('||palavra.front()=='-'||palavra.front()=='\''||palavra.front()=='\"')
                        palavra.erase(palavra.begin());
                    valor=palavra[1];
                    if(palavra.front()==-61 && valor>=-128 && valor<=-99)
                        palavra[1]=palavra[1]+32;
                    std::transform(palavra.begin(), palavra.end(), palavra.begin(),[](unsigned char c){ return std::tolower(c); });
                    if (palavra.size()>0)
                        docRunner->prox->dado.value = docRunner->prox->dado.value + buscaTFIDF(&docRunner->prox->dado.documento, palavra);
                }
                docRunner = docRunner->prox;
            }
            BubbleSort(Doc);
            printf("Ranqueamento da frase \"%s\":\n",linha.c_str());
            printDocOrd(Doc);
            printf("\n");
        }
    }
    myFile.close();
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
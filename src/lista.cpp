#include "lista.hpp"

void preencheLista(ListDocument *lDoc){
	ListPals lPal;
    fstream myFile;
    int quantidadeArquivos;
    string nomeArquivo,caminho,palavras,linha;
	printf("Quantos arquivos deseja inserir? (Max 100)\n");
    scanf("%d\n",&quantidadeArquivos);
    for (int i = 0; i < quantidadeArquivos; i++)
    {
        caminho="arquivos/";
        getline(cin, nomeArquivo);
        caminho.append(nomeArquivo);
	    createDocument(lDoc, nomeArquivo);
    }
    Bloque *aux;
    aux=lDoc->cabeca;
    while (aux->prox!=NULL)
    {
	    FLPTVazia(&lPal);
        myFile.open(aux->prox->dado.nome, ios::in);
        if (!myFile)
            cout<< "Arquivo não encontrado"<<endl;
        else{
            while (getline(myFile,linha,'\n'))
            {
                stringstream X(linha);
                while (getline(X, palavras, ' ')){
                    if(palavras.back() == ',' || palavras.back() =='.' || palavras.back() ==';' || palavras.back() ==':' || palavras.back() =='\'' || palavras.back() =='\"' || palavras.back() =='/')
                        palavras.pop_back();
                    if (palavras.front()=='\''||palavras.front()=='\"'||palavras.front()=='('){
                        palavras.pop_back();
                        palavras.erase(palavras.begin());
                    }
                    //insertLista(l,palavras);
                    insertLPTamanho(&lPal,palavras);
                }
            }
        }
        aux=aux->prox;
    }
    
}
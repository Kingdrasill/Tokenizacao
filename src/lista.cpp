#include "lista.hpp"

void FLVazia(Lista *l){
    l->cabeca=(Bloco*)malloc(sizeof(Bloco));
    l->cauda=l->cabeca;
    l->cauda->prox=NULL;
}
void insertLista(Lista *l,string palavras){
    l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
    l->cauda=l->cauda->prox;
    l->cauda->dado.palavra.assign(palavras);
    l->cauda->prox=NULL;
}
void preencheLista(Lista *l){
    fstream myFile;
    int quantidadeArquivos;
    string nomeArquivo,caminho,palavras,linha,linhaCorrigida, arquivo[100];
	printf("Quantos arquivos deseja inserir? (Max 100)\n");
    scanf("%d\n",&quantidadeArquivos);
    for (int i = 0; i < quantidadeArquivos; i++)
    {
        caminho="arquivos/";
        getline(cin, nomeArquivo);
        caminho.append(nomeArquivo);
        arquivo[i]=caminho;
    }
    for (int i = 0; i < quantidadeArquivos; i++)
    {
        cout << arquivo[i] <<endl;
        myFile.open(arquivo[i], ios::in);
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
                    insertLista(l,palavras);
                }
                printLista(l);
                printf("\n");
            }
        }
    }
    
}
// void removeListaItem(Lista *l, int item){
//     Bloco* aux, *freeBloco;
//     aux=l->cabeca;
//     while (aux->prox!=NULL)
//     {
//         if (aux->prox->dado.value[0]==item)
//         {
//             if (aux->prox==l->cauda)
//             {
//                 free(aux->prox);
//                 aux->prox=NULL;
//                 l->cauda=aux;
//             }
//             else{
//                 freeBloco=aux->prox;
//                 aux->prox=aux->prox->prox;
//                 free(freeBloco);
//             }
//         }
//         else{
//             aux=aux->prox;
//         }
//     }
// }
void printLista(Lista *l){
    Bloco* aux;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        cout<< aux->dado.palavra <<endl;
        aux=aux->prox;
    }
    printf("\n");
}
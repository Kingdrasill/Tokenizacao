#include "lista.h"
void FLVazia(Lista *l){
    l->cabeca=(Bloco*)malloc(sizeof(Bloco));
    l->cauda=l->cabeca;
    l->cauda->prox=NULL;
}
void insertLista(Lista *l,char palavra[]){
    l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
    l->cauda=l->cauda->prox;
    strcpy(l->cauda->dado.palavra,palavra);
    l->cauda->prox=NULL;
}
void preencheLista(Lista *l){
    int quantidadeArquivos;
	char caminho[13]={'.','.','/','a','r','q','u','i','v','o','s','/'},arquivo[100][80], string[93];
	printf("Quantos arquivos deseja inserir? (Max 100)\n");
    scanf("%d\n",&quantidadeArquivos);
    for (int i = 0; i < quantidadeArquivos; i++)
    {
        strcpy(string,caminho);
        fgets(arquivo[i],80,stdin);
        arquivo[i][strlen(arquivo[i])-1]='\0';
        strcpy(arquivo[i],strcat(string,arquivo[i]));
    }
    FILE *f;
    char letra, *palavra;
    for (int i = 0; i < quantidadeArquivos; i++)
    {
        if(!(f=fopen(arquivo[i],"r")))
            printf("Erro ao abrir arquivo.\n");
        else{
            strcpy(palavra,fgetc(f));
            while(!feof (f)){
                if ((letra = fgetc(f)) == ' '){
                    insertLista(l,palavra);
                }
                else{
                    strncat(palavra,letra,1);
                }
            }
            fclose(f);
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
// void printLista(Lista *l){
//     Bloco* aux;
//     aux=l->cabeca;
//     while (aux->prox!=NULL)
//     {
//         printf("%d ",aux->prox->dado.value[0]);
//         aux=aux->prox;
//     }
//     printf("\n");
// }
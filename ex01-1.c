# include <stdio.h>
# include <stdlib.h>


typedef struct no{
    int chave;
    struct no *esq, *dir;
}TNo;

TNo* busca(TNo* r, int v);
TNo* insere(TNo* a, int v);
void printABP(TNo raiz) ;


TNo *busca(TNo* r, int v)
{
    if(r == NULL)
        return NULL;
   else if (r->chave > v)
        return busca (r->esq, v);
    else if (r->chave < v) return busca (r->dir, v);
    else return r;
}


TNo* insere(TNo* a, int v)
{
    if(a==NULL){
        a = (TNo *)malloc(sizeof(TNo));
        a->chave = v;
        a->esq = a->dir = NULL;
    }
    else if(v < a->chave)
        a->esq = insere(a->esq,v);
    else if(v > a->chave)
        a->dir = insere(a->dir,v);
    return a;
}




void printABP(TNo raiz) 
{
    if (raiz == NULL) 
        return;
    printABP(raiz->esq);
    printf("%d\n", raiz->chave);
    printABP(raiz->dir);
}


int main()
{
    TNo* a = NULL;

    a = insere(a,6);
    a = insere(a,4);
    a = insere(a,3);
    a = insere(a,9);
    a = insere(a,0);
    a = insere(a,7);
    printf("\n");
    printABP(a);

    return 0;
}
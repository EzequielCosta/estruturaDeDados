#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct No {
    int dado;
    struct No *esq, * dir; /* * pai */
};


No* criar_arvore(int x) {
    No* r = new No(); 
    r->dado = x;
    r->esq = r->dir = NULL;
    return r;
}

No* inserir(No* arvore , int x){
    if (arvore == NULL){
        arvore = criar_arvore(x);
    }else if (x <= arvore->dado){
        arvore->esq = inserir(arvore->esq,x);
    }else {
        arvore->dir = inserir(arvore->dir,x);
    }

    return arvore;
}

void pre_ordem( No* raiz){
    if (raiz != NULL){
        printf("%d ",raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(No* raiz){
    if (raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ",raiz->dado);
        
    }
}

void inordem(No* raiz){
    if (raiz != NULL){
        inordem(raiz->esq);
        printf("%d ",raiz->dado);
        inordem(raiz->dir);
        
    }
}


main(){

    No* arvore = NULL;
    int folhas[] = {15,10,20,25,8,12};
    for (int i = 0; i < 6; i++ ){
        arvore = inserir(arvore,folhas[i]);
    }
    cout << "Pre-ordem: " << endl;
    pre_ordem(arvore);
    printf("\n");
    cout << "Pos-ordem: " << endl;
    pos_ordem(arvore);
	printf("\n");
	cout << "Inordem: " << endl;
    inordem(arvore);
    
}

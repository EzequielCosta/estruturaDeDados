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

No* procurar_no( No* raiz , int x) {
    No* esq;
    if ( raiz == NULL || raiz->dado == x)
        return raiz;
    esq = procurar_no(raiz->esq, x);
    if ( esq != NULL)
        return esq;
    return procurar_no(raiz->dir, x);
}

int numero_nos( No* raiz) {
    if ( raiz == NULL)
        return 0;
    return numero_nos(raiz -> esq) + numero_nos(raiz -> dir) + 1;
}

int altura( No* raiz) {
    int h_esq , h_dir;
    if ( raiz == NULL)
        return 0;
    h_esq = altura(raiz -> esq);
    h_dir = altura(raiz -> dir);
    return 1 + ( h_esq > h_dir ? h_esq : h_dir);
}




main(){

    No* arvore = NULL;
    int folhas[] = {15,10,20,25,8,12};
    for (int i = 0; i < 6; i++ ){
        arvore = inserir(arvore,folhas[i]);
    }
    cout << "Quantidade de nos: " << numero_nos(arvore) << endl;
    cout << "ALtura da arvore: " << altura(arvore) << endl;
    
    int numero;
	cout<<"Digite um numero para buscar: ";
	cin>>numero;
	No* foi_encontrado = procurar_no(arvore,numero);
	if (foi_encontrado){
		cout << "Encontrado: " << foi_encontrado->dado << endl;	
	}else{
		cout << "O Valor nao foi encontrado! ";	
	}
    



}

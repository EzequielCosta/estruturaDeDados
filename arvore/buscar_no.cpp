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

No* buscar(No* raiz, int dado){

    if (raiz == NULL || dado == raiz->dado){
        return raiz;
    }else if (dado < raiz->dado){
        buscar(raiz->esq,dado);
    }else{
        buscar(raiz->dir,dado);
    }
}

main(){

    No* arvore = NULL;
    int folhas[] = {15,10,20,25,8,12};
    int dado_procurado;
    int flag = 1;

    for (int i = 0; i < 6; i++ ){
        arvore = inserir(arvore,folhas[i]);
    }
    
    do {
    	cout << "Digite o dado que deseja procurar: ";
	    cin >> dado_procurado;
	    No* resultado_procura = buscar(arvore,dado_procurado);
	    if (resultado_procura != NULL){
	        cout << "Achou" << endl;
	    }else{
	        cout << "Nao achou" << endl;
	    }
	    cout << "Deseja continuar? (1 - SIM, 0 - NAO): ";
	    cin >> flag;
	    cout << ""<<endl;
	}while (flag == 1);
    
    
}

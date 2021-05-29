#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct No
{
    int dado;
    struct No *esq, *dir; /* * pai */
};

No *criar_arvore(int x)
{
    No *r = new No();
    r->dado = x;
    r->esq = r->dir = NULL;
    return r;
}

No *inserir(No *arvore, int x)
{
    if (arvore == NULL)
    {
        arvore = criar_arvore(x);
    }
    else if (x <= arvore->dado)
    {
        arvore->esq = inserir(arvore->esq, x);
    }
    else
    {
        arvore->dir = inserir(arvore->dir, x);
    }

    return arvore;
}

void pre_ordem(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(No *raiz)
{
    if (raiz != NULL)
    {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}

void inordem(No *raiz)
{
    if (raiz != NULL)
    {
        inordem(raiz->esq);
        printf("%d ", raiz->dado);
        inordem(raiz->dir);
    }
}

int busca_maior(No *raiz)
{
    while (raiz->dir != NULL)
        raiz = raiz->dir;
    return (raiz->dado);
}

No *remover(No *raiz, int x)
{
    No *aux;
    if (raiz == NULL)
    {
        return NULL;
    }
    else if (x < raiz->dado)
    {
        raiz->esq = remover(raiz->esq, x);
    }
    else if (x > raiz->dado)
    {
        raiz->dir = remover(raiz->dir, x);
    }
    else
    {
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            return NULL;
        }
        else if (raiz->esq == NULL)
        {
            aux = raiz->dir;
            free(raiz);
            return aux;
        }
        else if (raiz->dir == NULL)
        {
            aux = raiz->esq;
            free(raiz);
            return aux;
        }
        else
        {
            int aux = busca_maior(raiz->esq);
            raiz->dado = aux;
            raiz->esq = remover(raiz->esq, raiz->dado);
        }
    }
    return raiz;
}

main()
{
    No *arvore = NULL;
    int folhas[] = {8, 13, 12, 14, 3, 7, 4, 5, 1};
    for (int i = 0; i < 9; i++)
    {
        arvore = inserir(arvore, folhas[i]);
    }
    cout << "Pre-ordem: " << endl;
    pre_ordem(arvore);
    printf("\n");

    int item_remover = 0, flag = 0;
    do
    {
        cout << "Digite o item que deseja remover: ";
        cin >> item_remover;

        if (remover(arvore, item_remover))
        {
            cout << "Pre-ordem apos remocao: " << endl;
            pre_ordem(arvore);
            printf("\n");
        }
        else
        {
            cout << "Elemento não existe!";
        }
        cout << "Deseja parar ? (Continuar : 1 / Sair : 0): ";
        cin >> flag;
    } while (flag == 1);
}

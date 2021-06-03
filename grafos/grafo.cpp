#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


typedef struct {
    int **adjacencia;
    int n;
} Grafo;

typedef Grafo *p_grafo;

p_grafo criar_grafo(int n){
    int i, j;
    p_grafo g = new Grafo();
    //p_grafo g = malloc(sizeof(Grafo));
    g->n = n;
    g->adjacencia = new int*[n];
    //g->adjacencia = malloc(n * sizeof(int *));
    for (i = 0 ; i < n; i++){
        g->adjacencia[i] = new int[n];
    }
    for (j = 0; j < n; j++){
        g->adjacencia[i][j] = 0;
    }
    return g;
}

void destroi_grafo(p_grafo g){
    int i;
    for (i = 0; i < g->n; i++){
        free(g->adjacencia[i]);
    }
    free(g->adjacencia);
    free(g);
}

void insere_aresta(p_grafo g, int u, int v){
    g->adjacencia[u][v] = 1;
    g->adjacencia[v][u] = 1;
}

void remove_aresta(p_grafo g, int u, int v){
    g->adjacencia[u][v] = 0;
    g->adjacencia[v][u] = 0;
}

int tem_aresta(p_grafo g, int u, int v){
    return g->adjacencia[u][v];
}

void imprime_arestas(p_grafo g){
    int u,v;
    for (u = 0; u < g->n; u++){
        for (v = u+1; v < g->n; v++){
            if (g->adjacencia[u][v]){
                //cout << "Teste" << endl;
            }
        }

    }
}

int grau(p_grafo g, int u){
    int v, grau = 0;
    for (v = 0; v < g->n; v++){
        if (g->adjacencia[u][v]){
            grau++;
        }
    }
    return grau;
}

int mais_popular(p_grafo g){
    int u, max, grau_max, grau_atual;
    max = 0;
    grau_max = grau(g,0);
    for (u = 1; u < g->n; u++){
        grau_atual = grau(g,u);
        if (grau_atual > grau_max){
            grau_max = grau_atual;
            max = u;
        }    
    }   
    return max;
}
int main(){

    p_grafo grafo;
    grafo = criar_grafo(5);

    insere_aresta(grafo,0,1);
    insere_aresta(grafo,0,4);
    insere_aresta(grafo,0,2);
    insere_aresta(grafo,0,3);
    insere_aresta(grafo,1,4);
    insere_aresta(grafo,1,2);
    insere_aresta(grafo,2,3);
    insere_aresta(grafo,3,4);

    imprime_arestas(grafo);
    

    

}
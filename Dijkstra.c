#include <stdio.h>
#include <stdlib.h>

#define INFINITO 999999

typedef struct Vertice
{
    int id;
    int dist;
    struct Vertice *prox;
}Vertice;

typedef struct Lista
{
    Vertice *inicio, *fim;
}Lista;

typedef struct Grafo
{
    int arestas[10][10];
    Lista *vert;
    int nVerts;
}Grafo;

void Dijkstra(Grafo *g, int vInicial);

int main()
{

    return 0;
}

void Dijkstra(Grafo *g, int vInicial)
{
    int S[g->nVerts];
    int totalSol = 0;

    int i;
    for (i = 0; i < g->nVerts; i++)
    {
        S[i] = 0;
        g->vert[i].inicio->dist = INFINITO;
    }

    g->vert[vInicial].inicio->dist = 0;

    while (totalSol < g->nVerts)
    {
        int indexMin = 0, min = INFINITO;
        for (i = 0; i < g->nVerts; i++)
            if (S[i] == 0 && g->vert[i].inicio->dist < min)
            {
                min = g->vert[i].inicio->dist;
                indexMin = i;
            }

        S[indexMin] = 1;
        totalSol++;

        Vertice *aux = g->vert[indexMin].inicio;

        while (aux != NULL)
        {
            if (g->vert[indexMin].inicio->dist + g->arestas[g->vert[indexMin].inicio->id][aux->id] < aux->dist)
                aux->dist = g->vert[indexMin].inicio->dist + g->arestas[g->vert[indexMin].inicio->id][aux->id];
            aux = aux->prox;
        }
    }
}

#include <iostream>

#include "Grafo.hpp"
#include "ListaEncadeada.hpp"

Grafo::Grafo()
{
    vertices = new ListaEncadeada<ListaEncadeada<int>*>;
}

Grafo::~Grafo()
{
    for(int i = 0; i < vertices->Tamanho(); i++)
        delete vertices->Obter(i);

    delete vertices;
}

void Grafo::InsereVertice()
{
    vertices->Inserir(new ListaEncadeada<int>);
}

void Grafo::InsereAresta(int v, int w)
{
    if (v >= vertices->Tamanho() || w >= vertices->Tamanho())
        return;

    auto lista = vertices->Obter(v);

    for(int i = 0; i < lista->Tamanho(); i++)
        if(lista->Obter(i) == w )
            return;

    lista->Inserir(w);

    lista = vertices->Obter(w);
    for(int i = 0; i < lista->Tamanho(); i++)
        if(lista->Obter(i) == v )
            return;

    lista->Inserir(v);    
}

int Grafo::QuantidadeVertices()
{
    return vertices->Tamanho();
}

int Grafo::QuantidadeArestas()
{
    int count = 0;

    for(int i = 0; i < vertices->Tamanho(); i++)
        count += vertices->Obter(i)->Tamanho();

    return count / 2;
}
#ifndef METODOS_ORDENACAO_h
#define METODOS_ORDENACAO_h

#include "ListaEncadeada.hpp"
#include "Vertice.hpp"
#include "Grafo.hpp"

class MetodosOrdenacao {
    private:

       
       Grafo* grafo;
       ListaEncadeada<Vertice*>* vertices; 
       int quantidadeVertices;

    public:
        MetodosOrdenacao(Grafo* grafo) : grafo(grafo), vertices(grafo->ObterVertices()), quantidadeVertices(grafo->QuantidadeVertices()) {}

        void BubbleSort();
        void SelectionSort();

};

#endif
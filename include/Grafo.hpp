#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "ListaEncadeada.hpp"

class Grafo
{
    public:
        Grafo();
        ~Grafo();

        void InsereVertice();
        void InsereAresta(int v, int w);

        int QuantidadeVertices();
        int QuantidadeArestas();
        
    private:
        ListaAdjacencia vertices;
};

#endif
#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "ListaEncadeada.hpp"
#include "Vertice.hpp"

class Grafo
{
    public:
        Grafo();
        ~Grafo();

        void InsereVertice(int id);
        void InsereAresta(int idV, int idW);

        int QuantidadeVertices();
        int QuantidadeArestas();
        
        ListaEncadeada<Vertice*>* ObterVertices();

        void ImprimirGrafo();

    private:
        ListaEncadeada<Vertice*>* vertices;
};

#endif
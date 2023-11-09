#ifndef METODOS_ORDENACAO_h
#define METODOS_ORDENACAO_h

#include "ListaEncadeada.hpp"
#include "Vertice.hpp"
#include "Grafo.hpp"
#include "memlog.hpp"

class MetodosOrdenacao {
    private:

       
       Grafo* grafo;
       ListaEncadeada<Vertice*>* vertices; 
       int quantidadeVertices;
       int numComparacoes;
       

    public:
        MetodosOrdenacao(Grafo* grafo) : grafo(grafo), vertices(grafo->ObterVertices()), quantidadeVertices(grafo->QuantidadeVertices()), numComparacoes(0) {}

        void BubbleSort();
        void SelectionSort();
        void InserctionSort();
        void QuickSort();
        void MergeSort(ListaEncadeada<Vertice*>* vertices, int esq, int dir);
        
        void Merge(ListaEncadeada<Vertice*>* vertices, int esq, int meio, int dir); 
        void Particao(int esq, int dir, int *i, int *j, ListaEncadeada<Vertice*>* vertices);
        void Ordena(int esq, int dir, ListaEncadeada<Vertice*>* vertices);
        void Heapify(ListaEncadeada<Vertice*>* vertices, int n, int raiz, int* comparacoes);
        void HeapSort();
};

#endif
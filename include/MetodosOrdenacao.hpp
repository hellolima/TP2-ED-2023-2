#ifndef METODOS_ORDENACAO_h
#define METODOS_ORDENACAO_h

#include "ListaEncadeada.hpp"
#include "Vertice.hpp"
#include "Grafo.hpp"

/**
 * @brief Classe que implementa diferentes métodos de ordenação para uma lista encadeada de vértices.
 */
class MetodosOrdenacao {
private:
    Grafo* grafo; /**< Ponteiro para o grafo utilizado pelos métodos de ordenação. */
    ListaEncadeada<Vertice*>* vertices; /**< Ponteiro para a lista de vértices do grafo. */
    int quantidadeVertices; /**< Número total de vértices no grafo. */
    int numComparacoes; /**< Número de comparações realizadas durante a ordenação. */

public:
    /**
     * @brief Construtor da classe MetodosOrdenacao.
     * @param grafo Ponteiro para o grafo a ser utilizado pelos métodos de ordenação.
     */
     MetodosOrdenacao(Grafo* grafo) : grafo(grafo), vertices(grafo->ObterVertices()), quantidadeVertices(grafo->QuantidadeVertices()), numComparacoes(0) {}

    /**
     * @brief Implementa o algoritmo Bubble Sort para ordenar a lista de vértices.
     */
    void BubbleSort();

    /**
     * @brief Implementa o algoritmo Selection Sort para ordenar a lista de vértices.
     * @param esq Índice do primeiro elemento na lista.
     * @param dir Índice do último elemento na lista.
     */
    void SelectionSort(int esq, int dir);

    /**
     * @brief Implementa o algoritmo Insertion Sort para ordenar a lista de vértices.
     */
    void InserctionSort();

    /**
     * @brief Implementa o algoritmo Quick Sort para ordenar a lista de vértices.
     */
    void QuickSort();

    /**
     * @brief Implementa o algoritmo Merge Sort para ordenar a lista de vértices.
     * @param vertices Lista de vértices a ser ordenada.
     * @param esq Índice do primeiro elemento na lista.
     * @param dir Índice do último elemento na lista.
     */
    void MergeSort(ListaEncadeada<Vertice*>* vertices, int esq, int dir);

    /**
     * @brief Implementa o algoritmo de ordenação eficiente para a lista de vértices.
     */
    void OrdenacaoEficiente();

    /**
     * @brief Combina duas partes ordenadas de um array para o algoritmo Merge Sort.
     * @param vertices Lista de vértices a ser ordenada.
     * @param esq Índice do primeiro elemento na lista.
     * @param meio Índice do meio da lista.
     * @param dir Índice do último elemento na lista.
     */
    void Merge(ListaEncadeada<Vertice*>* vertices, int esq, int meio, int dir);

    /**
     * @brief Particiona a lista para o algoritmo Quick Sort.
     * @param esq Índice do primeiro elemento na lista.
     * @param dir Índice do último elemento na lista.
     * @param i Ponteiro para a variável que conterá o índice final do lado esquerdo.
     * @param j Ponteiro para a variável que conterá o índice inicial do lado direito.
     * @param vertices Lista de vértices a ser ordenada.
     */
    void Particao(int esq, int dir, int* i, int* j, ListaEncadeada<Vertice*>* vertices);

    /**
     * @brief Ordena a lista para o algoritmo Quick Sort.
     * @param esq Índice do primeiro elemento na lista.
     * @param dir Índice do último elemento na lista.
     * @param vertices Lista de vértices a ser ordenada.
     */
    void Ordena(int esq, int dir, ListaEncadeada<Vertice*>* vertices);

    /**
     * @param vertices Lista de vértices a ser ordenada.
     * @param n Número de elementos na lista.
     * @param raiz Índice do elemento raiz.
     * @param comparacoes Ponteiro para a variável que contará o número de comparações.
     */
    void Heapify(ListaEncadeada<Vertice*>* vertices, int n, int raiz, int* comparacoes);

    /**
     * @brief Implementa o algoritmo Heap Sort para ordenar a lista de vértices.
     * @param vertices Lista de vértices a ser ordenada.
     */
    void HeapSort(ListaEncadeada<Vertice*>* vertices);

    /**
     * @brief Permite escolher um método de ordenação eficiente para a lista de vértices.
     * @param esq Índice do primeiro elemento na lista.
     * @param dir Índice do último elemento na lista.
     */
    void EscolherOrdenacao(int esq, int dir);
};

#endif

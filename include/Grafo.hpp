#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "ListaEncadeada.hpp"
#include "Vertice.hpp"

/**
 * @brief Classe que representa um grafo.
 */
class Grafo
{
public:
    /**
     * @brief Construtor da classe Grafo.
     */
    Grafo();

    /**
     * @brief Destrutor da classe Grafo.
     */
    ~Grafo();

    /**
     * @brief Insere um vértice no grafo.
     * @param id Identificador único do vértice.
     */
    void InsereVertice(int id);

    /**
     * @brief Insere uma aresta entre dois vértices no grafo.
     * @param idV Identificador do vértice V.
     * @param idW Identificador do vértice W.
     */
    void InsereAresta(int idV, int idW);

    /**
     * @brief Obtém a quantidade de vértices no grafo.
     * @return Número total de vértices no grafo.
     */
    int QuantidadeVertices();

    /**
     * @brief Obtém a quantidade de arestas no grafo.
     * @return Número total de arestas no grafo.
     */
    int QuantidadeArestas();

    /**
     * @brief Obtém a lista de vértices do grafo.
     * @return Ponteiro para a lista de vértices do grafo.
     */
    ListaEncadeada<Vertice*>* ObterVertices();

    /**
     * @brief Imprime a representação do grafo.
     */
    void ImprimirGrafo();

private:
    ListaEncadeada<Vertice*>* vertices; /**< Ponteiro para a lista de vértices do grafo. */
};

#endif

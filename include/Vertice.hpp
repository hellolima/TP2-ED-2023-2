#ifndef VERTICE_HPP
#define VERTICE_HPP

#include "ListaEncadeada.hpp"

/**
 * @brief Classe que representa um vértice em um grafo.
 */
class Vertice
{
public:
    /**
     * @brief Construtor da classe Vertice.
     * @param id Identificador único do vértice.
     */
    Vertice(int id);

    /**
     * @brief Destrutor da classe Vertice.
     */
    ~Vertice();

    /**
     * @brief Obtém o identificador único do vértice.
     * @return Identificador único do vértice.
     */
    int GetId();

    /**
     * @brief Define a cor do vértice.
     * @param cor Nova cor a ser atribuída ao vértice.
     */
    void setCor(int cor);

    /**
     * @brief Obtém a cor do vértice.
     * @return Cor do vértice.
     */
    int GetCor();

    /**
     * @brief Obtém a lista de vértices vizinhos ao vértice atual.
     * @return Ponteiro para a lista de vértices vizinhos.
     */
    ListaEncadeada<Vertice*>* ObterVerticesVizinhos();

private:
    int id; /**< Identificador único do vértice. */
    int cor; /**< Cor atribuída ao vértice. */
    ListaEncadeada<Vertice*>* verticesVizinhos; /**< Ponteiro para a lista de vértices vizinhos. */
};

#endif

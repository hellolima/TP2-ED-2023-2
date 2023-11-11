#ifndef EH_GULOSO_HPP
#define EH_GULOSO_HPP

#include "ListaEncadeada.hpp"
#include "Vertice.hpp"
#include "Grafo.hpp"
#include <iostream>

/**
 * @brief Classe que implementa o algoritmo para verificar se uma coloração gulosa.
 */
class EhGuloso {
private:
    Grafo* grafo; /**< Ponteiro para o grafo utilizado pelo algoritmo. */
    ListaEncadeada<Vertice*>* vertices; /**< Ponteiro para a lista de vértices do grafo. */
    int quantidadeVertices; /**< Número total de vértices no grafo. */

public:
    /**
     * @brief Construtor da classe EhGuloso.
     * @param grafo Ponteiro para o grafo a ser utilizado pelo algoritmo.
     */
    EhGuloso(Grafo* grafo) : grafo(grafo), vertices(grafo->ObterVertices()), quantidadeVertices(grafo->QuantidadeVertices()) {}

    /**
     * @brief Verifica se a coloração dos vértices é válida.
     * @return True se a coloração for válida, False caso contrário.
     */
    bool VerticesGulosos() {
        for (int i = 0; i < quantidadeVertices; i++) {
            Vertice* vertice = vertices->Obter(i);
            ListaEncadeada<int> coresVizinhas;

            ListaEncadeada<Vertice*>* verticesVizinhos = vertice->ObterVerticesVizinhos();
            for (int j = 0; j < verticesVizinhos->Tamanho(); j++) {
                Vertice* verticeVizinho = verticesVizinhos->Obter(j);
                coresVizinhas.Inserir(verticeVizinho->GetCor());
            }

            for (int cor = 1; cor < vertice->GetCor(); cor++) {
                bool corEncontradaNaLista = false;
                No<int>* atual = coresVizinhas.Cabeca();
                while (atual != nullptr) {
                    if (atual->dado == cor) {
                        corEncontradaNaLista = true;
                        break;
                    }
                    atual = atual->proximo;
                }
                if (!corEncontradaNaLista) {
                    return false;
                }
            }
        }

        return true;
    }

    /**
     * @brief Gera uma representação em string da permutação dos vértices.
     * @return String representando a permutação dos vértices.
     */
    std::string VerificarColoracao() {
        std::string permutacao = "1";
        for (int i = 0; i < vertices->Tamanho(); i++) {
            Vertice* vertice = vertices->Obter(i);
            permutacao = permutacao + " " + std::to_string(vertice->GetId());
        }
        return permutacao;
    }
};

#endif

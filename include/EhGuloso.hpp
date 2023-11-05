#ifndef EH_GULOSO_HPP
#define EH_GULOSO_HPP

#include "ListaEncadeada.hpp"
#include "Vertice.hpp"
#include "Grafo.hpp"
#include <iostream>

class EhGuloso {
private:
    Grafo* grafo;
    ListaEncadeada<Vertice*>* vertices;
    int quantidadeVertices;

public:
    EhGuloso(Grafo* grafo) : grafo(grafo), vertices(grafo->ObterVertices()), quantidadeVertices(grafo->QuantidadeVertices()) {}

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




    std::string VerificarColoracao() {
        if (VerticesGulosos()) {
            std::string permutacao = "1";
            for (int i = 0; i < vertices->Tamanho(); i++) {
                Vertice* vertice = vertices->Obter(i);
                permutacao = permutacao + " " + std::to_string(vertice->GetId());
            }
            return permutacao;
        }
        return "0";
    }
};

#endif

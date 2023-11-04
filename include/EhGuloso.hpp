#ifndef EH_GULOSO_HPP
#define EH_GULOSO_HPP

#include "ListaEncadeada.hpp"
#include "Vertice.hpp"
#include "Grafo.hpp"
#include "MetodosOrdenacao.hpp"


class EhGuloso{

    private:

        Grafo* grafo;
        ListaEncadeada<Vertice*>* vertices; 
        int quantidadeVertices;

    public:
        
        EhGuloso(Grafo* grafo) : grafo(grafo), vertices(grafo->ObterVertices()), quantidadeVertices(grafo->QuantidadeVertices()) {}
        
        bool VerticesGulosos() {
            for (int i = 0; i < quantidadeVertices; i++) {
                Vertice* vertice = vertices->Obter(i);
                ListaEncadeada<Vertice*>* verticesVizinhos = vertice->ObterVerticesVizinhos();

                for (int j = 0; j < verticesVizinhos->Tamanho(); j++) {
                    if (verticesVizinhos->Obter(j)->GetCor() == vertice->GetCor()) {
                        return false;
                    } 
                }
            }
            return true;
        }

        std::string VerificarColoracao(){
            if (VerticesGulosos()){
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
#include "Grafo.hpp"
#include "Vertice.hpp"
#include "ListaEncadeada.hpp"

#include <iostream>

Grafo::Grafo(){
    vertices = new ListaEncadeada<Vertice*>;
}

Grafo::~Grafo(){
    for (int i = 0; i < vertices->Tamanho(); i++)
        delete vertices->Obter(i);

    delete vertices;
}

void Grafo::InsereVertice(int id){
    Vertice* novoVertice = new Vertice(id);
    vertices->Inserir(novoVertice);
}

void Grafo::InsereAresta(int idV, int idW){
    // Encontre os vértices com base nos IDs
    Vertice* verticeV = nullptr;
    Vertice* verticeW = nullptr;
    for (int i = 0; i < vertices->Tamanho(); i++)
    {
        Vertice* vertice = vertices->Obter(i);
        if (vertice->GetId() == idV)
        {
            verticeV = vertice;
        }
        else if (vertice->GetId() == idW)
        {
            verticeW = vertice;
        }

        // Se ambos os vértices foram encontrados, pare de procurar
        if (verticeV != nullptr && verticeW != nullptr)
        {
            break;
        }
    }

    // Se algum dos vértices não foi encontrado, saia
    if (verticeV == nullptr || verticeW == nullptr)
    {
        return;
    }

    // Adicione a aresta entre os vértices
    verticeV->ObterVerticesVizinhos()->Inserir(verticeW);
    verticeW->ObterVerticesVizinhos()->Inserir(verticeV);
}

int Grafo::QuantidadeVertices(){
    return vertices->Tamanho();
}

int Grafo::QuantidadeArestas(){
    int count = 0;

    for (int i = 0; i < vertices->Tamanho(); i++)
    {
        count += vertices->Obter(i)->ObterVerticesVizinhos()->Tamanho();
    }

    return count / 2;
}

ListaEncadeada<Vertice*>* Grafo::ObterVertices(){
        return vertices;
    }

void Grafo::ImprimirGrafo() {
    for (int i = 0; i < vertices->Tamanho(); i++) {
        Vertice* vertice = vertices->Obter(i);
        std::cout << "Vértice " << vertice->GetId() << " (Cor: " << vertice->GetCor() << ") - Vizinhos: ";
        ListaEncadeada<Vertice*>* vizinhos = vertice->ObterVerticesVizinhos();
        
        for (int j = 0; j < vizinhos->Tamanho(); j++) {
            std::cout << vizinhos->Obter(j)->GetId() << " ";
        }
        
        std::cout << std::endl;
    }
}

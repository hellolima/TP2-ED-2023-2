#include <iostream>
#include <vector>
#include <algorithm> // Para a função std::sort
#include "Grafo.hpp"

#define SUCCESSO (0)
#define FALHA (1)

int main(int argc, char const *argv[]) {

    char metodoOrdenacao;
    int numVertices;
    int numArestas;
    int corVertice;

    std::cin >> metodoOrdenacao;
    std::cin >> numVertices;


    Grafo grafo;

    for (int i = 0; i < numVertices; i++){
        grafo.InsereVertice(i);
    }
        
    
    for (int i = 0; i < numVertices; i++) {
        
        std::cin >> numArestas;

        for (int j = 0; j < numArestas; j++) {
            int v;
            std::cin >> v;
            grafo.InsereAresta(i, v);
        }
    }

    for (int i = 0; i < numVertices; i++){
        std::cin >> corVertice;
        ListaEncadeada<Vertice*>* vertices = grafo.ObterVertices();
        Vertice* verticeAtual = vertices->Obter(i);
        verticeAtual->setCor(corVertice);
    }


    // Lógica de ordenação
    if (metodoOrdenacao == 'b') {
        std::cout << "Entrou aqui" << std::endl;
    } else if (metodoOrdenacao == 's') {
        std::cout << "Entrou aqui" << std::endl;
    } else if (metodoOrdenacao == 'i') {
        std::cout << "Entrou aqui" << std::endl;
    } else if (metodoOrdenacao == 'q') {
        std::cout << "Entrou aqui" << std::endl;
    } else if (metodoOrdenacao == 'm') {
       std::cout << "Entrou aqui" << std::endl;
    } else if (metodoOrdenacao == 'p') {
        std::cout << "Entrou aqui" << std::endl;
    } else if (metodoOrdenacao == 'y') {
        grafo.ImprimirGrafo();
    } else {
        std::cerr << "Método de ordenação inválido." << std::endl;
        return FALHA;
    }



    return SUCCESSO;
}

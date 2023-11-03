#include <iostream>
#include "Grafo.hpp"
#include "MetodosOrdenacao.hpp"

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
    ListaEncadeada<Vertice*>* vertices;

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
        vertices = grafo.ObterVertices();
        Vertice* verticeAtual = vertices->Obter(i);
        verticeAtual->setCor(corVertice);
    }

    MetodosOrdenacao MetodosOrdenacao(&grafo);

    // Lógica de ordenação
    if (metodoOrdenacao == 'b') {
        std::cout << "_________" << std::endl;
        std::cout << "Bubble Sort" << std::endl;
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;
        
        MetodosOrdenacao.BubbleSort();
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;



    } else if (metodoOrdenacao == 's') {
        std::cout << "_________" << std::endl;
        std::cout << "Selection Sort" << std::endl;
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;
        
        MetodosOrdenacao.SelectionSort();
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;




    } else if (metodoOrdenacao == 'i') {
        std::cout << "Entrou aqui" << std::endl;
    } else if (metodoOrdenacao == 'q') {
        std::cout << "Entrou aqui" << std::endl;
    } else if (metodoOrdenacao == 'm') {
      grafo.ImprimirGrafo();
      vertices->inverterItens(0, 5);
      grafo.ImprimirGrafo();
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

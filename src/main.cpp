#include <iostream>
#include "Grafo.hpp"
#include "MetodosOrdenacao.hpp"
#include "EhGuloso.hpp"

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
    EhGuloso EhGuloso(&grafo);

    // Lógica de ordenação
    if (metodoOrdenacao == 'b') {
        MetodosOrdenacao.BubbleSort();
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;



    } else if (metodoOrdenacao == 's') {
        MetodosOrdenacao.SelectionSort();
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;




    } else if (metodoOrdenacao == 'i') { 
        MetodosOrdenacao.InserctionSort();
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;



    } else if (metodoOrdenacao == 'q') {
        MetodosOrdenacao.QuickSort();
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;



    } else if (metodoOrdenacao == 'm') {
        MetodosOrdenacao.MergeSort(vertices, 0, numVertices-1);
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;
        

    } else if (metodoOrdenacao == 'p') {
        MetodosOrdenacao.HeapSort(vertices);
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;

    } else if (metodoOrdenacao == 'y') {
        MetodosOrdenacao.HeapSort(vertices);
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;
    } else {
        std::cerr << "Método de ordenação inválido." << std::endl;
        return FALHA;
    }


    return SUCCESSO;
}

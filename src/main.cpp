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

    for (int i = 0; i < numVertices; i++) {
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

    for (int i = 0; i < numVertices; i++) {
        std::cin >> corVertice;
        vertices = grafo.ObterVertices();
        Vertice* verticeAtual = vertices->Obter(i);
        verticeAtual->setCor(corVertice);
    }

    MetodosOrdenacao MetodosOrdenacao(&grafo);
    EhGuloso EhGuloso(&grafo);

    std::string resultado;
    bool verticesGulosos = EhGuloso.VerticesGulosos();

    switch (metodoOrdenacao) {
        case 'b':
            if (verticesGulosos) {
                MetodosOrdenacao.BubbleSort();
                resultado = EhGuloso.VerificarColoracao();
            } else {
                resultado = "0";
            }
            break;

        case 's':
            if (verticesGulosos) {
                MetodosOrdenacao.SelectionSort();
                resultado = EhGuloso.VerificarColoracao();
            } else {
                resultado = "0";
            }
            break;

        case 'i':
            if (verticesGulosos) {
                MetodosOrdenacao.InserctionSort();
                resultado = EhGuloso.VerificarColoracao();
            } else {
                resultado = "0";
            }
            break;

        case 'q':
            if (verticesGulosos) {
                MetodosOrdenacao.QuickSort();
                resultado = EhGuloso.VerificarColoracao();
            } else {
                resultado = "0";
            }
            break;

        case 'm':
            if (verticesGulosos) {
                MetodosOrdenacao.MergeSort(vertices, 0, numVertices - 1);
                resultado = EhGuloso.VerificarColoracao();
            } else {
                resultado = "0";
            }
            break;

        case 'p':
        case 'y':
            if (verticesGulosos) {
                MetodosOrdenacao.HeapSort();
                resultado = EhGuloso.VerificarColoracao();
            } else {
                resultado = "0";
            }
            break;

        default:
            std::cerr << "Método de ordenação inválido." << std::endl;
            return FALHA;
    }

    std::cout << resultado << std::endl;
    return SUCCESSO;
}
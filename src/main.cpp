#include <chrono>
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

    // Medir o tempo de execução do método de ordenação
    auto start = std::chrono::high_resolution_clock::now();

    switch (metodoOrdenacao) {
        case 'b':
            MetodosOrdenacao.BubbleSort();
            break;
        case 's':
            MetodosOrdenacao.SelectionSort(0, numVertices-1);
            std::cout << EhGuloso.VerificarColoracao() << std::endl;
            break;
        case 'i':
            MetodosOrdenacao.InserctionSort();
            break;
        case 'q':
            MetodosOrdenacao.QuickSort();
           
            break;
        case 'm':
            MetodosOrdenacao.MergeSort(vertices, 0, numVertices - 1);
            break;
        case 'y':
            MetodosOrdenacao.OrdenacaoEficiente();
            std::cout << EhGuloso.VerificarColoracao() << std::endl;
            break;
        case 'p':
            MetodosOrdenacao.HeapSort(vertices);
            break;
        default:
            std::cerr << "Método de ordenação inválido." << std::endl;
            return FALHA;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    double tempoEmSegundos = duration / 1000000.0;

    std::cout << "fim" << std::endl;
    return SUCCESSO;
}

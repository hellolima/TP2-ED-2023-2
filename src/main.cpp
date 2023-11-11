#include <iostream>
#include "Grafo.hpp"
#include "MetodosOrdenacao.hpp"
#include "EhGuloso.hpp"

#define SUCCESSO (0)
#define FALHA (1)

int main(int argc, char const *argv[]) {
    try {
        char metodoOrdenacao;
        int numVertices;
        int numArestas;
        int corVertice;

        std::cin >> metodoOrdenacao;
        std::cin >> numVertices;

        Grafo grafo;
        ListaEncadeada<Vertice*>* vertices;

        for (int i = 0; i < numVertices; i++) {
            try {
                grafo.InsereVertice(i);
            } catch (const std::exception& e) {
                std::cerr << "Erro ao inserir vértice: " << e.what() << std::endl;
                return FALHA;
            }
        }

        for (int i = 0; i < numVertices; i++) {
            std::cin >> numArestas;

            for (int j = 0; j < numArestas; j++) {
                int v;
                std::cin >> v;
                try {
                    grafo.InsereAresta(i, v);
                } catch (const std::exception& e) {
                    std::cerr << "Erro ao inserir aresta: " << e.what() << std::endl;
                    return FALHA;
                }
            }
        }

        for (int i = 0; i < numVertices; i++) {
            std::cin >> corVertice;
            try {
                vertices = grafo.ObterVertices();
                Vertice* verticeAtual = vertices->Obter(i);
                verticeAtual->setCor(corVertice);
            } catch (const std::exception& e) {
                std::cerr << "Erro ao obter vértices: " << e.what() << std::endl;
                return FALHA;
            }
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
                MetodosOrdenacao.SelectionSort(0, numVertices-1);
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
            if (verticesGulosos) {
                MetodosOrdenacao.OrdenacaoEficiente();
                resultado = EhGuloso.VerificarColoracao();
            } else {
                resultado = "0";
            }
            break;

        case 'y':
            if (verticesGulosos) {
                MetodosOrdenacao.HeapSort(vertices);
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

    } catch (const std::exception& e) {
        std::cerr << "Erro geral: " << e.what() << std::endl;
        return FALHA;
    }
}

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
        std::cout << "meu vertice "<< verticeAtual << std::endl;
    }

    MetodosOrdenacao MetodosOrdenacao(&grafo);
    EhGuloso EhGuloso(&grafo);

    // Lógica de ordenação
    if (metodoOrdenacao == 'b') {
        std::cout << "_________" << std::endl;
        std::cout << "Bubble Sort" << std::endl;
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;
        
        MetodosOrdenacao.BubbleSort();
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;
        std::cout << "É guloso?" << std::endl;
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;



    } else if (metodoOrdenacao == 's') {
        std::cout << "_________" << std::endl;
        std::cout << "Selection Sort" << std::endl;
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;
        
        MetodosOrdenacao.SelectionSort();
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;

        std::cout << "É guloso?" << std::endl;
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;




    } else if (metodoOrdenacao == 'i') {
        std::cout << "_________" << std::endl;
        std::cout << "Inserction Sort" << std::endl;
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;
        
        MetodosOrdenacao.InserctionSort();
        grafo.ImprimirGrafo();
        std::cout << "_________" << std::endl;

        std::cout << "É guloso?" << std::endl;
        std::string resultado = EhGuloso.VerificarColoracao();
        std::cout << resultado << std::endl;



    } else if (metodoOrdenacao == 'q') {
        std::cout << "Entrou aqui" << std::endl;



    } else if (metodoOrdenacao == 'm') {
        std::cout << "Merge Sort" << std::endl;
        
        Vertice* verticeAtual = vertices->Obter(1);
        std::cout << "meu vertice "<< verticeAtual << std::endl;

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

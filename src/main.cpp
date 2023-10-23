#include <iostream>
#include "Grafo.hpp"

#define SUCCESSO (0)
#define FALHA (1)

int main(int argc, char const *argv[]){
    std::string funcao(argv[1]);
    std::string vertices(argv[1]);

    int numVertices = std::stoi(vertices); //error

    std::cout << funcao << std::endl;
    
    //criar um grafo
    int numArestas;

    Grafo grafo;

    for(int i = 0; i < numVertices; i++)
        grafo.InsereVertice();
        
    for(int i = 0; i < numVertices; i++)
    {
        std::cin >> numArestas;

        for(int j = 0; j < numArestas; j++)
        {
            int v;
            std::cin >> v;
            grafo.InsereAresta(i, v);
        }
    }


    return FALHA;
}
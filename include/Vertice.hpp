#ifndef VERTICE_HPP
#define VERTICE_HPP


#include "Vertice.hpp"
#include "ListaEncadeada.hpp"

class Vertice
{
    public:
        Vertice(int id);
        ~Vertice();

        int GetId();
        void setCor(int cor);
        int GetCor(); 
        ListaEncadeada<Vertice*>* ObterVerticesVizinhos();

        
    private:
        int id;
        int cor;
        ListaEncadeada<Vertice*>* verticesVizinhos;
};

#endif
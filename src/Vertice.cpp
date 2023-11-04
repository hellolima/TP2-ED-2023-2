#include "ListaEncadeada.hpp"
#include "Vertice.hpp"


Vertice::Vertice(int id){
    this->id = id;
    this->cor = -1;
    verticesVizinhos = new ListaEncadeada<Vertice*>;
}

Vertice::~Vertice(){
    delete verticesVizinhos;
}

int Vertice::GetId(){
    return id;
}

void Vertice::setCor(int cor){
    this->cor = cor;
}; 

int Vertice::GetCor() {
    return cor;
}


ListaEncadeada<Vertice*>* Vertice::ObterVerticesVizinhos(){
    return verticesVizinhos;
}
#include "MetodosOrdenacao.hpp"
#include <iostream>

void MetodosOrdenacao::BubbleSort(){
	int i, j; 
            
    for(i = 0; i < quantidadeVertices - 1; i++){
        for(j = 1; j <= quantidadeVertices - 1; j++){
            if ((vertices->Obter(j)->GetCor()) < (vertices->Obter(j-1)->GetCor())){
                vertices->inverterItens(j-1, j);
             }
        }
    }
};

void MetodosOrdenacao::SelectionSort(){
	int i, j, min;

	for (i = 0; i < quantidadeVertices - 1; i++){
		min = i;
		for(j = i + 1; j < quantidadeVertices; j++){
			if((vertices->Obter(j)->GetCor()) < (vertices->Obter(min)->GetCor())){
				min = j;
			}
		vertices->inverterItens(i, min);
		}
	}
};

void MetodosOrdenacao::InserctionSort(){
	int i, j;
	Vertice* chave;

	for (i = 1; i < quantidadeVertices; i++) {
		chave = vertices->Obter(i);
		j = i - 1;

		while ((j >= 0) && ((vertices->Obter(j)->GetCor()) > (chave->GetCor()))) {
			vertices->inverterItens(j, j + 1);
			j--;
		}
	}
};

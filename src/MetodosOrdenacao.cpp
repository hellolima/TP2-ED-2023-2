#include "MetodosOrdenacao.hpp"

void MetodosOrdenacao::BubbleSort(){
	int i, j; 
            
    for(i = 0; i < quantidadeVertices - 1; i++){
        for(j = 1; j <= quantidadeVertices - 1; j++){
            if ((vertices->Obter(j)->GetCor()) < (vertices->Obter(j-1)->GetCor())){
                vertices->inverterItens(j-1, j);
             }
        }
    }
}

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
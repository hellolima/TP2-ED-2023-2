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
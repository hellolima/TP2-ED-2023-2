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


 void MetodosOrdenacao::MergeSort(ListaEncadeada<Vertice*>* vertices, int esq, int dir) {
	 int meio;

     if (esq < dir) {
         meio = esq + (dir - esq) / 2;
         // Ordena as duas metades
         MergeSort(vertices, esq, meio);
         MergeSort(vertices, meio + 1, dir);
         // Junta as duas metades ordenadas
         Merge(vertices, esq, meio, dir);
     }
 }
 void MetodosOrdenacao::Merge(ListaEncadeada<Vertice*>* vertices, int esq, int meio, int dir) {
     int n1 = meio - esq + 1;
     int n2 = dir - meio;
     // Cria listas temporárias para armazenar as duas metades
     ListaEncadeada<Vertice*>* Esquerda = new ListaEncadeada<Vertice*>;
     ListaEncadeada<Vertice*>* Direita = new ListaEncadeada<Vertice*>;
     // Copia os elementos para as listas temporárias
     for (int i = 0; i < n1; i++) {
         Esquerda->Inserir(vertices->Obter(esq + i));
     }
     for (int j = 0; j < n2; j++) {
         Direita->Inserir(vertices->Obter(meio + 1 + j));
     }
     int i = 0;
     int j = 0;
     int k = esq;
     // Merge das listas temporárias de volta para vertices
     while (i < n1 && j < n2) {
         Vertice* a = Esquerda->Obter(i);
         Vertice* b = Direita->Obter(j);
         if (a->GetCor() <= b->GetCor()) {
             //vertices->Inserir(a);
			 vertices->setarItem(k, a);
             i++;
         } else {
             //vertices->Inserir(b);
			 vertices->setarItem(k, b);
             j++;
         }
         k++;
     }
     // Copia os elementos restantes de Esquerda, se houver algum
     while (i < n1) {
         Vertice* a = Esquerda->Obter(i);
         //vertices->Inserir(a);
		 vertices->setarItem(k, a);
         i++;
         k++;
     }
     // Copia os elementos restantes de Direita, se houver algum
     while (j < n2) {
         Vertice* b = Direita->Obter(j);
         //vertices->Inserir(b);
		 vertices->setarItem(k, b);
         j++;
         k++;
     }
     // Libera a memória das listas temporárias
     delete  Esquerda; //*  ***********FAZER O DESTRUTOR 
     delete  Direita; //*  ***********FAZER O DESTRUTOR 
 }

 void MetodosOrdenacao::Particao(int esq, int dir, int *i, int *j, ListaEncadeada<Vertice*>* vertices){ 
    *i = esq;
    *j = dir;
    Vertice* pivo = vertices->Obter((*i + *j) / 2);

    while (*i <= *j) {
        while (vertices->Obter(*i)->GetCor() < pivo->GetCor()) {
            (*i)++;
        }
        while (vertices->Obter(*j)->GetCor() > pivo->GetCor()) {
            (*j)--;
        }
        if (*i <= *j) {
            vertices->inverterItens(*i, *j);
            (*i)++;
            (*j)--;
        }
    }
}


void MetodosOrdenacao::Ordena(int esq, int dir, ListaEncadeada<Vertice*>* vertices){ 

	int i, j;

	
  	Particao(esq, dir, &i, &j, vertices);
  	
  	if (esq < j) Ordena(esq, j, vertices);
  	
  	if (i < dir) Ordena(i, dir, vertices);
}

void MetodosOrdenacao::QuickSort(){ 
  	Ordena(0, vertices->Tamanho()-1, vertices); 
}

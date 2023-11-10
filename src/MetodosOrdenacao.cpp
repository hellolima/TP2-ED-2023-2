#include "MetodosOrdenacao.hpp"
#include <iostream>

void MetodosOrdenacao::BubbleSort() {
    int i, j;
    for (i = 0; i < quantidadeVertices - 1; i++) {
        for (j = 1; j <= quantidadeVertices - 1; j++) {
            if (vertices->Obter(j)->GetCor() < vertices->Obter(j - 1)->GetCor() ||
                (vertices->Obter(j)->GetCor() == vertices->Obter(j - 1)->GetCor() &&
                 vertices->Obter(j)->GetId() < vertices->Obter(j - 1)->GetId())) {
                vertices->inverterItens(j - 1, j);
            }
        }
    }
};


void MetodosOrdenacao::SelectionSort(int esq, int dir) {
    int i, j, min;
    for (i = 0; i < quantidadeVertices - 1; i++) {
        min = i;
        for (j = i + 1; j < quantidadeVertices; j++) {
            if (vertices->Obter(j)->GetCor() < vertices->Obter(min)->GetCor() ||
                (vertices->Obter(j)->GetCor() == vertices->Obter(min)->GetCor() &&
                 vertices->Obter(j)->GetId() < vertices->Obter(min)->GetId())) {
                min = j;
            }
        }
        vertices->inverterItens(i, min);
    }
};


void MetodosOrdenacao::InserctionSort() {
    int i, j;
    Vertice* chave;
    for (i = 1; i < quantidadeVertices; i++) {
        chave = vertices->Obter(i);
        j = i - 1;
        while (j >= 0 && (vertices->Obter(j)->GetCor() > chave->GetCor() ||
                           (vertices->Obter(j)->GetCor() == chave->GetCor() &&
                            vertices->Obter(j)->GetId() > chave->GetId()))) {
            vertices->inverterItens(j, j + 1);
            j--;
        }
    }
};



 void MetodosOrdenacao::MergeSort(ListaEncadeada<Vertice*>* vertices, int esq, int dir) {
	 int meio;

     if (esq < dir) {
         meio = esq + (dir - esq) / 2;
         MergeSort(vertices, esq, meio);
         MergeSort(vertices, meio + 1, dir);
         Merge(vertices, esq, meio, dir);
     }
 }
 void MetodosOrdenacao::Merge(ListaEncadeada<Vertice*>* vertices, int esq, int meio, int dir) {
     int n1 = meio - esq + 1;
     int n2 = dir - meio;
     
     ListaEncadeada<Vertice*>* Esquerda = new ListaEncadeada<Vertice*>;
     ListaEncadeada<Vertice*>* Direita = new ListaEncadeada<Vertice*>;
     
     for (int i = 0; i < n1; i++) {
         Esquerda->Inserir(vertices->Obter(esq + i));
     }
     for (int j = 0; j < n2; j++) {
         Direita->Inserir(vertices->Obter(meio + 1 + j));
     }
     int i = 0;
     int j = 0;
     int k = esq;
    
      while (i < n1 && j < n2) {
        Vertice* a = Esquerda->Obter(i);
        Vertice* b = Direita->Obter(j);
        if (a->GetCor() < b->GetCor() ||
            (a->GetCor() == b->GetCor() && a->GetId() < b->GetId())) {
            vertices->setarItem(k, a);
            i++;
        } else {
            vertices->setarItem(k, b);
            j++;
        }
        k++;
    }
 
     while (i < n1) {
         Vertice* a = Esquerda->Obter(i);
		 vertices->setarItem(k, a);
         i++;
         k++;
     }
   
     while (j < n2) {
         Vertice* b = Direita->Obter(j);
		 vertices->setarItem(k, b);
         j++;
         k++;
     }
    
     delete  Esquerda; 
     delete  Direita; 
 }

 void MetodosOrdenacao::Particao(int esq, int dir, int *i, int *j, ListaEncadeada<Vertice*>* vertices){ 
    *i = esq;
    *j = dir;
    Vertice* pivo = vertices->Obter((*i + *j) / 2);

    while (*i <= *j) {
        while (vertices->Obter(*i)->GetCor() < pivo->GetCor() ||
               (vertices->Obter(*i)->GetCor() == pivo->GetCor() &&
                vertices->Obter(*i)->GetId() < pivo->GetId())) {
            (*i)++;
        }
        while (vertices->Obter(*j)->GetCor() > pivo->GetCor() ||
               (vertices->Obter(*j)->GetCor() == pivo->GetCor() &&
                vertices->Obter(*j)->GetId() > pivo->GetId())) {
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


void MetodosOrdenacao::Heapify(ListaEncadeada<Vertice*>* vertices, int n, int raiz, int* comparacoes) {
    int maior = raiz;
    int esq = 2 * raiz + 1;
    int dir = 2 * raiz + 2;

    (*comparacoes)++;
    if (esq < n && (vertices->Obter(esq)->GetCor() > vertices->Obter(maior)->GetCor() ||
                    (vertices->Obter(esq)->GetCor() == vertices->Obter(maior)->GetCor() &&
                     vertices->Obter(esq)->GetId() > vertices->Obter(maior)->GetId()))) {
        maior = esq;
    }

    (*comparacoes)++;
    if (dir < n && (vertices->Obter(dir)->GetCor() > vertices->Obter(maior)->GetCor() ||
                    (vertices->Obter(dir)->GetCor() == vertices->Obter(maior)->GetCor() &&
                     vertices->Obter(dir)->GetId() > vertices->Obter(maior)->GetId()))) {
        maior = dir;
    }

    if (maior != raiz) {
        vertices->inverterItens(raiz, maior);
        Heapify(vertices, n, maior, comparacoes);
    }
}

void MetodosOrdenacao::HeapSort(ListaEncadeada<Vertice*>* vertices) {
    int n = vertices->Tamanho();
    int numComparacoes = 0;

    for (int raiz = n / 2 - 1; raiz >= 0; raiz--) {
        Heapify(vertices, n, raiz, &numComparacoes);
    }

    for (int i = n - 1; i > 0; i--) {
        vertices->inverterItens(0, i);
        Heapify(vertices, i, 0, &numComparacoes);
    }
}


void MetodosOrdenacao::OrdenacaoEficiente() {
    EscolherOrdenacao(0, vertices->Tamanho() - 1);
}

void MetodosOrdenacao::EscolherOrdenacao(int esq, int dir) {
    int i, j;
    Particao(esq, dir, &i, &j, vertices);

    if (j - esq < 0) {
        SelectionSort(esq, j);
    } else {
        Ordena(esq, j, vertices);
    }

    if (dir - i > 10) {
        SelectionSort(i, dir);
    } else {
        Ordena(i, dir, vertices);
    }
}
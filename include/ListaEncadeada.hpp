#pragma once

#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP


template <class TipoDado> 
struct No
{
    TipoDado dado;
    No* proximo;
    No* anterior;

    
};

template <class TipoDado> 
class ListaEncadeada
{
    protected:
        No<TipoDado>* _cabeca;
        No<TipoDado>* _cauda;

        int _tamanho;

    public:
        ListaEncadeada()
        {
            _cabeca = nullptr;
            _cauda = nullptr;
            _tamanho = 0;
        };

        ~ListaEncadeada()
        {
            auto atual = _cabeca;

            while (atual != nullptr)
            {
                auto proximo = atual->proximo;
                delete atual;
                atual = proximo;
            }
        }

        int Tamanho()
        {
            return _tamanho;
        }

        void Inserir(TipoDado dado){
            auto novoNo = new No<TipoDado>;
            novoNo->dado = dado;
            novoNo->proximo = nullptr;
            novoNo->anterior = _cauda;

            if (_cabeca == nullptr)
            {
                _cabeca = novoNo;
                _cauda = novoNo;
            }
            else
            {
                _cauda->proximo = novoNo;
                novoNo->anterior = _cauda;
                _cauda = novoNo;
            }

            _tamanho++;
        }


        void Remover(TipoDado dado)
{
    auto atual = _cabeca;

    while (atual != nullptr)
    {
        if (atual->dado == dado)
        {
            if (atual->anterior != nullptr)
            {
                atual->anterior->proximo = atual->proximo;
            }
            if (atual->proximo != nullptr)
            {
                atual->proximo->anterior = atual->anterior;
            }

            if (atual == _cabeca)
            {
                _cabeca = atual->proximo;
            }
            if (atual == _cauda)
            {
                _cauda = atual->anterior;
            }

            delete atual;
            _tamanho--;
            return;
        }

        atual = atual->proximo;
    }
}


        TipoDado Obter(int indice){
            auto atual = _cabeca;

            for (int i = 0; i < indice; i++){
                atual = atual->proximo;
            }

            return atual->dado;
        }

        bool Vazia()
        {
            return _tamanho == 0;
        }

        void inverterItens(int indice1, int indice2) {
            // if (indice1 < 0 || indice2 < 0 || indice1 >= _tamanho || indice2 >= _tamanho) {
            //     std::cerr << "Índices inválidos." << std::endl;
            //     return;
            // }

            // if (indice1 == indice2) {
            //     // Não há necessidade de inverter se os índices forem iguais
            //     return;
            // }

            // Encontrar os nós correspondentes aos índices
            No<TipoDado>* no1 = _cabeca;
            No<TipoDado>* no2 = _cabeca;

            for (int i = 0; i < indice1; ++i) {
                no1 = no1->proximo;
            }

            for (int i = 0; i < indice2; ++i) {
                no2 = no2->proximo;
            }

            // Trocar os dados dos nós
            TipoDado aux = no1->dado;
            no1->dado = no2->dado;
            no2->dado = aux;
        }


        
};

#endif
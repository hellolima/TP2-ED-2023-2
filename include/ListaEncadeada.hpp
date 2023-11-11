#pragma once

#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

#include <iostream>

/**
 * @brief Estrutura de nó para a ListaEncadeada.
 */
template <class TipoDado>
struct No
{
    TipoDado dado;      /**< Dado armazenado no nó. */
    No* proximo;        /**< Ponteiro para o próximo nó na lista. */
    No* anterior;       /**< Ponteiro para o nó anterior na lista. */
};

/**
 * @brief Implementação de uma lista encadeada.
 */
template <class TipoDado>
class ListaEncadeada
{
protected:
    No<TipoDado>* _cabeca; /**< Ponteiro para o primeiro nó da lista. */
    No<TipoDado>* _cauda;  /**< Ponteiro para o último nó da lista. */
    int _tamanho;         /**< Número de elementos na lista. */

public:
    /**
     * @brief Construtor da classe ListaEncadeada.
     */
    ListaEncadeada()
    {
        _cabeca = nullptr;
        _cauda = nullptr;
        _tamanho = 0;
    };

    /**
     * @brief Destrutor da classe ListaEncadeada.
     */
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

    /**
     * @brief Obtém o tamanho da lista.
     * @return Número de elementos na lista.
     */
    int Tamanho()
    {
        return _tamanho;
    }

    /**
     * @brief Obtém o nó cabeça da lista.
     * @return Ponteiro para o nó cabeça.
     */
    No<TipoDado>* Cabeca()
    {
        return _cabeca;
    }

    /**
     * @brief Insere um dado no final da lista.
     * @param dado Dado a ser inserido.
     */
    void Inserir(TipoDado dado)
    {
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

    /**
     * @brief Remove o nó do início da lista.
     */
    void RemoverNoInicio()
    {
        if (_cabeca == nullptr)
        {
            throw std::out_of_range("Lista vazia. Nenhum nó para remover.");
        }

        auto noRemovido = _cabeca;
        _cabeca = _cabeca->proximo;

        if (_cabeca != nullptr)
        {
            _cabeca->anterior = nullptr;
        }
        else
        {
            _cauda = nullptr;
        }

        delete noRemovido;
        _tamanho--;
    }

    /**
     * @brief Remove um dado específico da lista.
     * @param dado Dado a ser removido.
     */
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

        throw std::out_of_range("Elemento não encontrado na lista.");
    }

    /**
     * @brief Obtém o dado de um nó específico na lista.
     * @param indice Índice do nó desejado.
     * @return Dado do nó no índice especificado.
     */
    TipoDado Obter(int indice)
    {
        if (indice < 0 || indice >= _tamanho)
        {
            throw std::out_of_range("Índice fora dos limites da lista.");
        }

        auto atual = _cabeca;

        for (int i = 0; i < indice; i++)
        {
            atual = atual->proximo;
        }

        return atual->dado;
    }

    /**
     * @brief Verifica se a lista está vazia.
     * @return True se a lista estiver vazia, False caso contrário.
     */
    bool Vazia()
    {
        return _tamanho == 0;
    }

    /**
     * @brief Inverte os itens nos índices especificados na lista.
     * @param indice1 Índice do primeiro item a ser invertido.
     * @param indice2 Índice do segundo item a ser invertido.
     */
    void inverterItens(int indice1, int indice2)
    {
        if (indice1 < 0 || indice2 < 0 || indice1 >= _tamanho || indice2 >= _tamanho)
        {
            throw std::out_of_range("Índices inválidos para inverter itens.");
        }

        if (indice1 == indice2)
        {
            // Não há necessidade de inverter se os índices forem iguais
            return;
        }

        // Encontrar os nós correspondentes aos índices
        No<TipoDado>* no1 = _cabeca;
        No<TipoDado>* no2 = _cabeca;

        for (int i = 0; i < indice1; ++i)
        {
            no1 = no1->proximo;
        }

        for (int i = 0; i < indice2; ++i)
        {
            no2 = no2->proximo;
        }

        // Trocar os dados dos nós
        TipoDado aux = no1->dado;
        no1->dado = no2->dado;
        no2->dado = aux;
    }

    /**
     * @brief Define o dado de um nó específico na lista.
     * @param indiceSetado Índice do nó a ter o dado definido.
     * @param item Dado a ser definido no nó.
     */
    void setarItem(int indiceSetado, TipoDado item)
    {
        if (indiceSetado < 0 || indiceSetado >= _tamanho)
        {
            throw std::out_of_range("Índice fora dos limites da lista para definir item.");
        }

        No<TipoDado>* no1 = _cabeca;

        if (indiceSetado == 0)
        {
            no1->dado = item;
        }
        else
        {
            // Encontrar o nó correspondente ao índice
            for (int i = 0; i < indiceSetado; ++i)
            {
                no1 = no1->proximo;
            }
            no1->dado = item;
        }
    }

    /**
     * @brief Imprime a lista na saída padrão.
     */
    void Imprimir()
    {
        No<TipoDado>* atual = _cabeca;

        while (atual != nullptr)
        {
            std::cout << atual->dado << " ";
            atual = atual->proximo;
        }

        std::cout << std::endl;
    }
};

#endif

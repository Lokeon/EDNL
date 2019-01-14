#include "../arbolBinario_Din.hpp"
#include <iostream>

template <typename T>
void nostalgicos(const Abin<T> &A)
{
    if (A.arbolVacioB())
        std::cout << "Arbol Vacio" << std::endl;
    else
        std::cout << "Ratio:"
                  << " " << nostalgicos_rec(A, A.raizB()) << "/" << nodosTotales(A, A.raizB()) << std::endl;
}

template <typename T>
int nodosTotales(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (nA == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + nodosTotales(A, A.hijoIzqdoB(nA)) + nodosTotales(A, A.hijoDrchoB(nA));
}

template <typename T>
int nostalgicos_rec(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (nA == Abin<T>::NODO_NULO)
        return 0;
    else
    {
        if (ancestros(A, nA) > descendientes(A, nA))
        {
            return 1 + nostalgicos_rec(A, A.hijoDrchoB(nA)) + nostalgicos_rec(A, A.hijoIzqdoB(nA));
        }
        else
        {
            return 0 + nostalgicos_rec(A, A.hijoDrchoB(nA)) + nostalgicos_rec(A, A.hijoIzqdoB(nA));
        }
    }
}

template <typename T>
int ancestros(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (A.padreB(nA) == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + ancestros(A, A.padreB(nA));
}

template <typename T>
int descendientes(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if ((A.hijoDrchoB(nA) == Abin<T>::NODO_NULO) && (A.hijoIzqdoB(nA) == Abin<T>::NODO_NULO))
        return 0; 
    else
        return 1 + descendientes(A, A.hijoDrchoB(nA)) + descendientes(A, A.hijoIzqdoB(nA));
}
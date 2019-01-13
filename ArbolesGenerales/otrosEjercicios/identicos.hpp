#include "../arbolGeneral_Din.hpp"
#include <iostream>

template <typename T>
void identicos(const Agen<T> &A, const Agen<T> &B)
{
    if (A.arbolVacio() || B.arbolVacio())
        std::cout << "Arbol Vacio" << std::endl;
    else if (identicos_rec(A, A.raiz(), B, B.raiz()))
        std::cout << "Son iguales" << std::endl;
    else
        std::cout << "No son iguales" << std::endl;
}

template <typename T>
bool identicos_rec(const Agen<T> &A, typename Agen<T>::nodo nA, const Agen<T> &B, typename Agen<T>::nodo nB)
{
    typename Agen<T>::nodo hijoA;
    typename Agen<T>::nodo hijoB;

    hijoA = A.hijoIzqdo(nA);
    hijoB = B.hijoIzqdo(nB);

    if ((nA == Agen<T>::NODO_NULO && nB != Agen<T>::NODO_NULO) || (nA != Agen<T>::NODO_NULO && nB == Agen<T>::NODO_NULO))
    {
        return false;
    }
    else
    {
        while ((hijoA != Agen<T>::NODO_NULO) && (hijoB != Agen<T>::NODO_NULO))
        {
            identicos_rec(A, hijoA, B, hijoB);
            hijoA = A.hermDrcho(hijoA);
            hijoB = B.hermDrcho(hijoB);
        }
        
        if (nA == Agen<T>::NODO_NULO && nB == Agen<T>::NODO_NULO)
        {
            return true;
        }
    }
}
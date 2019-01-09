#include "../arbolBinario_Din.hpp"

template <typename T>
int profundidad(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (nA == Abin<T>::NODO_NULO)
        return 0;
    else
        return profundidad_rec(A, nA);
}

template <typename T>
int profundidad_rec(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (A.padreB(nA) == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + profundidad_rec(A,A.padreB(nA));
}
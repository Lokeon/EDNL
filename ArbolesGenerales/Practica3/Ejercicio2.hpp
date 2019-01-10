#include "../arbolGeneral_Din.hpp"

template <typename T>
int profundidad(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    if (nA == Agen<T>::NODO_NULO)
        return 0;
    else
        return profundidad_rec(A, nA);
}

template <typename T>
int profundidad_rec(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    if (A.padre(nA) == Agen<T>::NODO_NULO)
        return 0;
    else
        return 1 + profundidad_rec(A,A.padre(nA));
}
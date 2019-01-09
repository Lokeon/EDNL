#include "../arbolBinario_Din.hpp"

template <typename T>
bool espejo(const Abin<T> &A, const Abin<T> &B)
{
    if ((A.arbolVacioB() && !B.arbolVacioB()) || (!A.arbolVacioB() && B.arbolVacioB()))
    {
        return false;
    }
    else
        return espejo_rec(A, A.raizB(), B, B.raizB());
}

template <typename T>
bool espejo_rec(const Abin<T> &A, typename Abin<T>::nodo nA, const Abin<T> &B, typename Abin<T>::nodo nB)
{
    if ((nA == Abin<T>::NODO_NULO && nB != Abin<T>::NODO_NULO) || (nA != Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO))
        return false;
    else if (nA == Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO)
        return true;
    else
        return espejo_rec(A, A.hijoDrchoB(nA), B, B.hijoDrchoB(nB)) && espejo_rec(A, A.hijoIzqdoB(nA), B, B.hijoIzqdoB(nB));
}
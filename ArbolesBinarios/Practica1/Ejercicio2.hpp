#include "../arbolBinario_Din.hpp"

template <typename T>
int altura(const Abin<T> &A)
{
    if (A.arbolVacioB())
        return 0;
    else
        return altura_rec(A, A.raizB());
}

template <typename T>
int altura_rec(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (nA == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + std::max(altura_rec(A, A.hijoDrchoB(nA)), altura_rec(A, A.hijoIzqdoB(nA)));
}
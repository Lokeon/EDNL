#include "../arbolBinario_Din.hpp"

template <typename T>
int contarNodos(const Abin<T> &A)
{
    if (A.arbolVacioB())
        return 0;
    else
        return contarNodos_rec(A, A.raizB());
}

template <typename T>
int contarNodos_rec(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (nA == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
        return 1 + contarNodos_rec(A, A.hijoDrchoB(nA)) + contarNodos_rec(A, A.hijoIzqdoB(nA));
}
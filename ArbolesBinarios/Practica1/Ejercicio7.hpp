#include "../arbolBinario_Din.hpp"

template <typename T>
bool pseudocompleto(const Abin<T> &A)
{
    if (A.arbolVacioB())
        return false;
    else if (A.hijoDrchoB(A.raizB()) == Abin<T>::NODO_NULO &&
             A.hijoIzqdoB(A.raizB()) == Abin<T>::NODO_NULO)
        return true;
    else
        return pseudocompleto_rec(A, A.raizB());
}

template <typename T>
bool pseudocompleto_rec(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (A.alturaB(A.raizB()) - 1  == A.profundidadB(nA))
        return comprobar(A, nA);
    else if (A.alturaB(A.hijoDrchoB(nA)) > A.alturaB(A.hijoIzqdoB(nA)))
        return pseudocompleto_rec(A, A.hijoDrchoB(nA));
    else if (A.alturaB(A.hijoDrchoB(nA)) < A.alturaB(A.hijoIzqdoB(nA)))
        return pseudocompleto_rec(A, A.hijoIzqdoB(nA));
    else
        return pseudocompleto_rec(A, A.hijoIzqdoB(nA)) &&
               pseudocompleto_rec(A, A.hijoDrchoB(nA));
}

template <typename T>
bool comprobar(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (A.hijoDrchoB(nA) == Abin<T>::NODO_NULO && A.hijoIzqdoB(nA) == Abin<T>::NODO_NULO)
        return true;
    else if (A.hijoDrchoB(nA) != Abin<T>::NODO_NULO && A.hijoIzqdoB(nA) != Abin<T>::NODO_NULO)
        return true;
    else
        return false;
}
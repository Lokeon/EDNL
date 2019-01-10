#include "../arbolBinario_Din.hpp"

template <typename T>
Abin<T> reflejo(Abin<T> &A)
{
    Abin<T> B;

    if (!A.arbolVacioB())
    {
        B.insertarRaizB(A.elemento(A.raizB()));
        reflejo_rec(A, A.raizB(), B, B.raizB());
        return B;
    }
    else
        return B;
}

template <typename T>
void reflejo_rec(Abin<T> &A, typename Abin<T>::nodo nA, Abin<T> &B, typename Abin<T>::nodo nB)
{
    if (A.hijoIzqdoB(nA) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoDrchoB(nB, A.elemento(A.hijoIzqdoB(nA)));
        reflejo_rec(A, A.hijoIzqdoB(nA), B, B.hijoDrchoB(nB));
    }
    if (A.hijoDrchoB(nA) != Abin<T>::NODO_NULO)
    {
        B.insertarHijoIzqdoB(nB, A.elemento(A.hijoDrchoB(nA)));
        reflejo_rec(A, A.hijoDrchoB(nA), B, B.hijoIzqdoB(nB));
    }
}
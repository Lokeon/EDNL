#include "../arbolBinario_Din.hpp"
#include <iostream>

template <typename T>
void tresnietos(const Abin<T> &A)
{
    if (A.arbolVacioB())
        std::cout << "Arbol Vacio" << std::endl;
    else
        std::cout << "3nietos: " << tresnietos_rec(A, A.raizB()) << std::endl;
}

template <typename T>
int tresnietos_rec(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if ((A.hijoDrchoB(nA) == Abin<T>::NODO_NULO) || (A.hijoIzqdoB(nA) == Abin<T>::NODO_NULO)) 
        return 0;
    else
    {
        if (nietos(A, nA))
        {
            return 1 + tresnietos_rec(A, A.hijoDrchoB(nA)) + tresnietos_rec(A, A.hijoIzqdoB(nA));
        }
        else
        {
            return 0 + tresnietos_rec(A, A.hijoDrchoB(nA)) + tresnietos_rec(A, A.hijoIzqdoB(nA));
        }
    }
}

template <typename T>
bool nietos(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if ((A.hijoIzqdoB(A.hijoDrchoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoIzqdoB(A.hijoIzqdoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoDrchoB(A.hijoDrchoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoDrchoB(A.hijoIzqdoB(nA)) == Abin<T>::NODO_NULO))
    {
        return true;
    }

    if ((A.hijoIzqdoB(A.hijoDrchoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoIzqdoB(A.hijoIzqdoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoDrchoB(A.hijoIzqdoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoDrchoB(A.hijoDrchoB(nA)) == Abin<T>::NODO_NULO))
    {
        return true;
    }

    if ((A.hijoIzqdoB(A.hijoDrchoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoDrchoB(A.hijoIzqdoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoDrchoB(A.hijoDrchoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoIzqdoB(A.hijoIzqdoB(nA)) == Abin<T>::NODO_NULO))
    {
        return true;
    }

    if ((A.hijoIzqdoB(A.hijoIzqdoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoDrchoB(A.hijoIzqdoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoDrchoB(A.hijoDrchoB(nA)) != Abin<T>::NODO_NULO) &&
        (A.hijoIzqdoB(A.hijoDrchoB(nA)) == Abin<T>::NODO_NULO))
    {
        return true;
    }

    return false;
}
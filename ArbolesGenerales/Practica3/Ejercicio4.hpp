#include "../arbolGeneral_Din.hpp"
#include <iostream>

template <typename T>
void podar(Agen<T> &A, const T elemento)
{
    if (A.arbolVacio())
        A.arbolVacio();
    else
        podar_rec(A, elemento, A.raiz());
}

template <typename T>
void podar_rec(Agen<T> &A, const T elemento, typename Agen<T>::nodo nA)
{
    typename Agen<T>::nodo hijo;
    hijo = A.hijoIzqdo(nA);

    if (nA != Agen<T>::NODO_NULO)
    {
        if (elemento == A.elemento(nA))
        {
            borrar(A, nA);
            std::cout << "Poda realizada" << std::endl;
        }
        else
        {
            while (hijo != Agen<T>::NODO_NULO)
            {
                podar_rec(A, elemento, hijo);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

template <typename T>
void borrar(Agen<T> &A, typename Agen<T>::nodo nA)
{
    typename Agen<T>::nodo hijo;
    hijo = A.hijoIzqdo(nA);

    if (nA != Agen<T>::NODO_NULO)
    {
        while (hijo != Agen<T>::NODO_NULO && A.hijoIzqdo(hijo) == Agen<T>::NODO_NULO)
        {
            A.eliminarHijoIzqdo(nA);
            hijo = A.hijoIzqdo(nA);
        }
        if (hijo != Agen<T>::NODO_NULO && A.hijoIzqdo(hijo) != Agen<T>::NODO_NULO)
        {
            borrar(A, hijo);
            borrar(A, nA);
        }
    }
}
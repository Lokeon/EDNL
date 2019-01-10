#include "../arbolGeneral_Din.hpp"

template <typename T>
int grado(const Agen<T> &A)
{
    if (A.arbolVacio())
        return 0;
    else
        return grado_rec(A, A.raiz());
}

template <typename T>
int grado_rec(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int maximo;
    typename Agen<T>::nodo nHijo;

    maximo = numHijos(A, nA);
    nHijo = A.hijoIzqdo(nA);

    if (nHijo != Agen<T>::NODO_NULO)
    {
        while (nHijo != Agen<T>::NODO_NULO)
        {
            maximo = std::max(maximo, grado_rec(A, nHijo));
            nHijo = A.hermDrcho(nHijo);
        }
    }

    return maximo;
}

template <typename T>
int numHijos(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int hijos;
    typename Agen<T>::nodo hijo;

    hijos = 0;
    hijo = A.hijoIzqdo(nA);

    if (hijo != Agen<T>::NODO_NULO)
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            hijos++;
            hijo = A.hermDrcho(hijo);
        }
    }

    return hijos;
}
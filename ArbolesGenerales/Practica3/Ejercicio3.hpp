#include "../arbolGeneral_Din.hpp"
#include <algorithm>

template <typename T>
int desequilibrio(const Agen<T> &A)
{
    if (A.arbolVacio())
        return 0;
    else
        return std::abs(altura(A, A.raiz()) - alturaMin(A, A.raiz()));
}

template <typename T>
int altura(const Agen<T> &A, typename Agen<T>::nodo nA)
{

    int alturaMax;
    typename Agen<T>::nodo hijo;

    alturaMax = -1;
    hijo = A.hijoIzqdo(nA);

    if (nA == Agen<T>::NODO_NULO)
        return -1;
    else
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            alturaMax = std::max(alturaMax, altura(A, hijo));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + alturaMax;
    }
}

template <typename T>
int alturaMin(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int alturaMini;
    typename Agen<T>::nodo hijo;

    alturaMini = altura(A, nA);
    hijo = A.hijoIzqdo(nA);

    if (nA == Agen<T>::NODO_NULO)
        return -1;
    else
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            alturaMini = std::min(alturaMini, altura(A, hijo));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + alturaMini;
    }
}
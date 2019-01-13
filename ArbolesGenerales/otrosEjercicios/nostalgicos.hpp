#include "../arbolGeneral_Din.hpp"
#include <iostream>

template <typename T>
void nostalgicos(const Agen<T> &A)
{
    if (A.arbolVacio())
        std::cout << "Arbol Vacio" << std::endl;
    else
        std::cout << "Ratio:" << nostalgicos_rec(A, A.raiz()) << "/" << contarNodos(A, A.raiz()) << std::endl;
}

template <typename T>
int contarNodos(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int nodos;
    typename Agen<T>::nodo hijo;

    nodos = 0;
    hijo = A.hijoIzqdo(nA);

    if (nA == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            nodos += contarNodos(A, hijo);
            hijo = A.hermDrcho(hijo);
        }
        return 1 + nodos;
    }
}

template <typename T>
int nostalgicos_rec(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int nostalgicos;
    typename Agen<T>::nodo hijo;

    nostalgicos = 0;
    hijo = A.hijoIzqdo(nA);

    if (nA == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            nostalgicos += nostalgicos_rec(A, hijo);
            hijo = A.hermDrcho(hijo);
        }
        if (ancestros(A, nA) > descendientes(A, nA))
        {
            return 1 + nostalgicos;
        }
        else
        {
            return 0 + nostalgicos;
        }
    }
}

template <typename T>
int ancestros(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    if (A.padre(nA) == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        return 1 + ancestros(A, A.padre(nA));
    }
}

template <typename T>
int descendientes(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int hijos;
    typename Agen<T>::nodo hijo;

    hijos = 0;
    hijo = A.hijoIzqdo(nA);

    if (hijo == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            hijos += descendientes(A, hijo);
            hijo = A.hermDrcho(hijo);
        }

        return 1 + hijos;
    }
}
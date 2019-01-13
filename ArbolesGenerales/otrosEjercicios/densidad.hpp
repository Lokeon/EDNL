#include "../arbolGeneral_Din.hpp"
#include <iostream>

template <typename T>
void densidad(const Agen<T> &A)
{
    if (A.arbolVacio())
        std::cout << "Arbol Vacio" << std::endl;
    else
        std::cout << "Densidad:"
                  << gradoMedio(A, A.raiz()) << "/" << grado(A, A.raiz()) << std::endl;
}

template <typename T>
int gradoMedio(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int gradoMT;
    typename Agen<T>::nodo hijo;

    gradoMT = 0;
    hijo = A.hijoIzqdo(nA);

    if (nA != Agen<T>::NODO_NULO)
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            gradoMT += gradoMedio(A, hijo);
            hijo = A.hermDrcho(hijo);
        }
        if(tieneHijo(A,nA))
        {
            return 1 + gradoMT;
        }
        else{
            return gradoMT;
        }
    }
}

template <typename T>
bool tieneHijo(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    if ((nA != Agen<T>::NODO_NULO) && (A.hijoIzqdo(nA) != Agen<T>::NODO_NULO))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
int grado(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int gradoT;
    typename Agen<T>::nodo hijo;

    gradoT = contarHijos(A, nA);
    hijo = A.hijoIzqdo(nA);

    if (nA != Agen<T>::NODO_NULO)
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            gradoT = std::max(gradoT, grado(A, hijo));
            hijo = A.hermDrcho(hijo);
        }
        return gradoT;
    }
    else
    {
        return 0;
    }
}

template <typename T>
int contarHijos(const Agen<T> &A, typename Agen<T>::nodo nA)
{
    int hijos;
    typename Agen<T>::nodo hijo;

    hijos = 0;
    hijo = A.hijoIzqdo(nA);

    if (nA != Agen<T>::NODO_NULO)
    {
        while (hijo != Agen<T>::NODO_NULO)
        {
            hijos++;
            hijo = A.hermDrcho(hijo);
        }
    }

    return hijos;
}


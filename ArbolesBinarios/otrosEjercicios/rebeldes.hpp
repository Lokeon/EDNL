#include "../arbolBinario_Din.hpp"
#include <iostream>

// He usado A = 1 y B = 0 , porque no me dejaba rellenar con 
// enteros los arboles aun cambiandolo a int el tipo, idky

template <typename T>
void rebeldes(const Abin<T> &A)
{
    if (A.arbolVacioB())
        std::cout << "Arbol Vacio" << std::endl;
    else
        std::cout << "Nodos Rebeldes: " << rebeldes_rec(A, A.raizB()) << std::endl;
}

template <typename T>
int rebeldes_rec(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (nA == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        if (rebel(A, nA))
        {
            return 1 + rebeldes_rec(A, A.hijoIzqdoB(nA)) + rebeldes_rec(A, A.hijoDrchoB(nA));
        }
        else
        {
            return 0 + rebeldes_rec(A, A.hijoIzqdoB(nA)) + rebeldes_rec(A, A.hijoDrchoB(nA));
        }
    }
}

template <typename T>
bool rebel(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (A.elemento(nA) == 'A' && contarB(A, nA) >  contarA(A, nA))
        return true;
    else
    {
        if(A.elemento(nA) == 'B' && contarB(A,nA) < contarA(A,nA))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

template <typename T>
int contarB(const Abin<T>& A, typename Abin<T>::nodo nA){
    if(A.padreB(nA) == Abin<T>::NODO_NULO)
        return 0;
    else
        if(A.elemento(A.padreB(nA)) == 'B')
        {
            return 1 + contarB(A,A.padreB(nA));
        }
        else
        {
            return 0 + contarB(A,A.padreB(nA));
        }
}

template <typename T>
int contarA(const Abin<T>& A, typename Abin<T>::nodo nA){
    if(A.padreB(nA) == Abin<T>::NODO_NULO)
        return 0;
    else
        if(A.elemento(A.padreB(nA)) == 'A')
        {
            return 1 + contarA(A,A.padreB(nA));
        }
        else
        {
            return 0 + contarA(A,A.padreB(nA));
        }
}
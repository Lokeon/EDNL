#include "../arbolBinario_Din.hpp"
#include <iostream>

template <typename T>
void esAVL(const Abin<T> &A)
{
    if (A.arbolVacioB())
        std::cout << "Arbol Vacio" << std::endl;
    else
    {
        if ((equilibrio(A, A.raizB()) == 0) || (equilibrio(A, A.raizB()) == 1) || (equilibrio(A, A.raizB()) == -1))
        {
            std::cout << "Arbol Equilibrado" << std::endl;
        }
        else
        {
            std::cout << "Arbol no Equilibrado" << std::endl;
        }
    }
}

template <typename T>
int equilibrio(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    return (alturaA(A, A.hijoIzqdoB(nA)) - alturaA(A, A.hijoDrchoB(nA)));
}

template <typename T>
int alturaA(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (nA == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + std::max(alturaA(A, A.hijoDrchoB(nA)), alturaA(A, A.hijoIzqdoB(nA)));
}
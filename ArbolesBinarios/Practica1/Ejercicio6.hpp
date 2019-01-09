#include "../arbolBinario_Din.hpp"

template <typename T>
int desequilibrio(const Abin<T> &A)
{
    if (A.arbolVacioB())
        return 0;
    else
        return desequilibrio_rec(A, A.raizB());
}

template <typename T>
int desequilibrio_rec(const Abin<T> &A, typename Abin<T>::nodo nA)
{
    if (nA == Abin<T>::NODO_NULO)
        return 0;
    else
        return std::max(std::abs(A.alturaB(A.hijoDrchoB(nA)) - A.alturaB(A.hijoIzqdoB(nA))), 
                        std::max(desequilibrio_rec(A, A.hijoDrchoB(nA)),desequilibrio_rec(A,A.hijoIzqdoB(nA))));
}
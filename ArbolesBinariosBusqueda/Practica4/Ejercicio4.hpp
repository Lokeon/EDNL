
#include "../ABB_DIN.hpp"
#include "Ejercicio3.hpp"

template <typename T>
void unions(const Abb<T> &A, const Abb<T> &B, Abb<T> &AVL)
{
    Abb<T> AUB;

    union_rec(A, AUB);
    union1_rec(B, AUB);
    equilibrar(AUB, AVL);
}

template <typename T>
void union_rec(const Abb<T> &A, Abb<T> &AUB)
{
    if (!A.vacio())
    {
        AUB.insertar(A.elemento());
        union_rec(A.izqdo(), AUB);
        union_rec(A.drcho(), AUB);
    }
}

template <typename T>
void union1_rec(const Abb<T> &A, Abb<T> &AUB)
{
    if (!A.vacio())
    {
        if (AUB.buscar(A.elemento()).vacio())
        {
            AUB.insertar(A.elemento());
            union1_rec(A.izqdo(), AUB);
            union1_rec(A.drcho(), AUB);
        }
        else
        {
            union1_rec(A.izqdo(), AUB);
            union1_rec(A.drcho(), AUB);
        }
    }
}

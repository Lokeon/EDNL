#include "../ABB_DIN.hpp"
#include "Ejercicio3.hpp"

template <typename T>
void inter(const Abb<T> &A, const Abb<T> &B, Abb<T> &AVL)
{
    Abb<T> A0B;
    inter_rec(A, B, A0B);
    equilibrar(A0B, AVL);
}

template <typename T>
void inter_rec(const Abb<T> &A, const Abb<T> &B, Abb<T> &A0B)
{
    if (!A.vacio() && !B.vacio())
    {
        if (!A.buscar(B.elemento()).vacio())
        {
            A0B.insertar(B.elemento());
            inter_rec(A, B.izqdo(), A0B);
            inter_rec(A, B.drcho(), A0B);
        }
        else
        {
            inter_rec(A, B.izqdo(), A0B);
            inter_rec(A, B.drcho(), A0B);
        }
    }
}

#include "../ABB_DIN.hpp"
#include "Ejercicio3.hpp"
#include <vector>

template <typename T>
void diferencia(const Abb<T> &A, const Abb<T> &B, Abb<T> &AVL)
{
    Abb<T> uni, ints, pp;

    unions(A, B, uni);
    inters(A, B, ints);

    diferencia_rec(uni, ints, pp);
    equilibrar(pp, AVL);
}

template <typename T>
void unions(const Abb<T> &A, const Abb<T> &B, Abb<T> &uni)
{
    unions_rec(A, uni);
    unions1_rec(B, uni);
}

template <typename T>
void unions_rec(const Abb<T> &A, Abb<T> &uni)
{
    if (!A.vacio())
    {
        uni.insertar(A.elemento());
        unions_rec(A.izqdo(), uni);
        unions_rec(A.drcho(), uni);
    }
}

template <typename T>
void unions1_rec(const Abb<T> &A, Abb<T> &uni)
{
    if (!A.vacio())
    {
        if (uni.buscar(A.elemento()).vacio())
        {
            uni.insertar(A.elemento());
            unions1_rec(A.izqdo(), uni);
            unions1_rec(A.drcho(), uni);
        }
        else
        {
            unions1_rec(A.izqdo(), uni);
            unions1_rec(A.drcho(), uni);
        }
    }
}

template <typename T>
void inters(const Abb<T> &A, const Abb<T> &B, Abb<T> &ints)
{
    if (!A.vacio() && !B.vacio())
    {
        if (!A.buscar(B.elemento()).vacio())
        {
            ints.insertar(B.elemento());
            inters(A, B.izqdo(), ints);
            inters(A, B.drcho(), ints);
        }
        else
        {
            inters(A, B.izqdo(), ints);
            inters(A, B.drcho(), ints);
        }
    }
}

template <typename T>
void diferencia_rec(const Abb<T> &A, const Abb<T> &B, Abb<T> &pp)
{
    if (!A.vacio())
    {
        if (B.buscar(A.elemento()).vacio())
        {
            pp.insertar(A.elemento());
            diferencia_rec(A.izqdo(), B, pp);
            diferencia_rec(A.drcho(), B, pp);
        }
        else
        {
            diferencia_rec(A.izqdo(), B, pp);
            diferencia_rec(A.drcho(), B, pp);
        }
    }
}
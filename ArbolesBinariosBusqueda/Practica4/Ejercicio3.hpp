#ifndef Ejercicio3_HPP
#define Ejercicio3_HPP

#include "../ABB_DIN.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void equilibrar(const Abb<T> &A, Abb<T> &SA)
{
    int n;
    std::vector<T> vec;

    rellenar(A, vec);
    sort(vec.begin(), vec.end()); // con el sort ordenamos los numeros en forma inorden
                                  // sin el los numeros estarian ordenados en preorden
    n = vec.size();
    equilibrar_rec(SA, vec, n, 0);
}

template <typename T>
void rellenar(const Abb<T> &A, std::vector<T> &vec)
{
    if (!A.vacio())
    {
        vec.push_back(A.elemento());
        rellenar(A.izqdo(), vec);
        rellenar(A.drcho(), vec);
    }
}

template <typename T>
void equilibrar_rec(Abb<T> &SA, std::vector<T> &vec, int n, int ini)
{
    if (ini != n)
    {
        int pos = ini + ((n - ini) / 2);
        SA.insertar(vec[pos]);
        equilibrar_rec(SA, vec, pos, ini);
        equilibrar_rec(SA, vec, n, pos + 1);
    }
}

#endif
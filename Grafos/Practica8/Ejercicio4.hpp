#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

template <typename tCoste>
GrafoP<tCoste> emasejer(const GrafoP<tCoste> &G)
{
    GrafoP<tCoste> ema(G.numVert());

    ema = KruskallMaximo(G);

    return ema;
}
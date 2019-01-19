#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
GrafoP<tCoste> emasejer(const GrafoP<tCoste>& G)
{
    GrafoP<tCoste> ema(G.numVert());

    ema = KruskallMaximo(G);

    return ema;
}
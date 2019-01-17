#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
matriz<tCoste> agencia(const GrafoP<tCoste> &Tren, const GrafoP<tCoste> &Aut, vertice ciudad)
{
    matriz<vertice> mV(Tren.numVert());
    matriz<tCoste> Tr(Tren.numVert());
    matriz<tCoste> Au(Aut.numVert());
    matriz<tCoste> tarifas(Tren.numVert());
    tCoste min1, min2;

    Tr = Floyd(Tren, mV);
    Au = Floyd(Aut, mV);

    // std::cout << Tr << std::endl;
    // std::cout << Au << std::endl;

    for (vertice i = 0; i < Aut.numVert(); ++i)
    {
        for (vertice j = 0; j < Aut.numVert(); ++j)
        {
            min1 = std::min(Tr[i][j], Au[i][j]);
            min2 = std::min((Tr[i][ciudad] + Au[ciudad][j]), (Au[i][ciudad] + Tr[ciudad][j]));
            tarifas[i][j] = std::min(min1, min2);
        }
    }
    return tarifas;
}
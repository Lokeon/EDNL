#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
void emasejer2(const GrafoP<tCoste> &dist, const GrafoP<tCoste> &caudal, int subvencion, int coste)
{
    GrafoP<tCoste> costes(dist.numVert());
    matriz<vertice> mV(caudal.numVert());
    matriz<tCoste> distancia;

    distancia = Floyd(dist, mV);

    for (vertice i = 0; i < dist.numVert(); ++i)
    {
        for (vertice j = 0; j < dist.numVert(); ++j)
        {
            costes[i][j] = (distancia[i][j] * coste) - (caudal[i][j] * subvencion);
        }
    }

    std::cout << Kruskall(costes) << std::endl;
}
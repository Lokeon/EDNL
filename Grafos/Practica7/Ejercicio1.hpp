#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste costeViaje(const GrafoP<tCoste> &G, vertice &origen, vertice &destino)
{
    matriz<vertice> mV(G.numVert());         // matrizVertice
    matriz<tCoste> mC(G.numVert());          // matrizCoste Floyd con costes Maximos
    vector<vertice> ciVisitada(G.numVert()); // vector donde guardo el "origen" de mayor coste
    vertice verticeVisitado;                 // vertice con el mayor coste en la comparacion
    tCoste max = 0;                          // comparador
    tCoste costeTotal = 0;                   // coste total a devolver

    mC = FloydCostesMaximos(G, mV);
    std::cout << mC << std::endl;

    for (vertice i = 0; i < G.numVert(); ++i)
    {
        if ((std::find(ciVisitada.begin(), ciVisitada.end(), i) != ciVisitada.end()) == false)
        {
            for (vertice j = 0; j < G.numVert(); ++j)
            {
                if ((mC[i][j] > max))
                {
                    max = mC[i][j];
                    verticeVisitado = i;
                }
            }
        }
        costeTotal += max;
        max = 0;
        ciVisitada.push_back(verticeVisitado);
    }

    origen = ciVisitada.front();
    destino = ciVisitada.back();
    return costeTotal;
}
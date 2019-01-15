#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>

template <typename tCoste>
bool aciclico(const GrafoP<tCoste> &G)
{
    typedef typename GrafoP<tCoste>::vertice vertice; //vertice
    matriz<vertice> mV(G.numVert());                  // matrizVertices
    matriz<tCoste> mC = Floyd(G, mV);                 // matrizCoste con el resultado de Floyd

    std::cout << mC << std::endl;

    // Comprobacion de si el grafo es aciclico
    for (vertice i = 0; i < G.numVert(); ++i)
    {
        for (vertice j = 0; j < G.numVert(); ++j)
        {
            if (mC[i][j] == GrafoP<tCoste>::INFINITO)
                return true;
        }
    }

    return false;
}
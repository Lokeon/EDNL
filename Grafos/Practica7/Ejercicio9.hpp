#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste viaje(const GrafoP<tCoste> &Aut, const GrafoP<tCoste> &Tren, vertice origen, vertice destino, int costeTaxi, vector<vertice> &ruta)
{
    GrafoP<tCoste> TrenAut(Aut.numVert() + Tren.numVert());
    vector<vertice> vV1(Aut.numVert() + Tren.numVert());
    vector<vertice> vV2(Aut.numVert() + Tren.numVert());
    vector<tCoste> trenInicio, busInicio;

    for (vertice i = 0; i < Tren.numVert(); ++i)
    {
        for (vertice j = 0; j < Tren.numVert(); ++j)
        {
            TrenAut[i][j] = Tren[i][j];
        }
    }

    for (vertice i = Tren.numVert(); i < (Tren.numVert() + Aut.numVert()); ++i)
    {
        for (vertice j = Tren.numVert(); j < (Tren.numVert() + Aut.numVert()); ++j)
        {
            TrenAut[i][j] = Aut[i - Aut.numVert()][j - Aut.numVert()];
        }
    }

    // Costes Taxi
    int i = 0;
    for (vertice j = Tren.numVert(); j < (Tren.numVert() + Aut.numVert()); ++j)
    {
        TrenAut[i][j] = costeTaxi;
        ++i;
    }

    i = Tren.numVert();
    for (vertice j = 0; j < Tren.numVert(); ++j)
    {
        TrenAut[i][j] = costeTaxi;
        ++i;
    }

    //Poner a 0 la diagonal
    for (vertice i = 0; i < Tren.numVert() + Aut.numVert(); ++i)
    {
        TrenAut[i][i] = 0;
    }

    // Mirar grafo para entender lo de arriba
    std::cout << TrenAut << std::endl;

    trenInicio = Dijkstra(TrenAut, origen, vV1);
    busInicio = Dijkstra(TrenAut, origen + Aut.numVert(), vV2);

    if (trenInicio[destino] < busInicio[destino])
    {
        ruta = vV1;
        std::cout << "Ruta Tren coste :" << std::endl;
        return trenInicio[destino];
    }
    else
    {
        ruta = vV2;
        std::cout << "Ruta Autobus coste:" << std::endl;
        return busInicio[destino + Aut.numVert()];
    }
}
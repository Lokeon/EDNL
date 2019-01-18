#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste viaje3(const GrafoP<tCoste> &Aut, const GrafoP<tCoste> &Tren, const GrafoP<tCoste> &Avi, vertice origen, vertice destino, int taxi1, int taxi2, vector<vertice> &ruta)
{
    GrafoP<tCoste> TrenAutAvi(Aut.numVert() + Tren.numVert() + Avi.numVert());
    vector<vertice> vV1(Aut.numVert() + Tren.numVert() + Avi.numVert());
    vector<vertice> vV2(Aut.numVert() + Tren.numVert() + Avi.numVert());
    vector<vertice> vV3(Aut.numVert() + Tren.numVert() + Avi.numVert());
    vector<tCoste> trenInicio, busInicio, aviInicio;

    for (vertice i = 0; i < Tren.numVert(); ++i)
    {
        for (vertice j = 0; j < Tren.numVert(); ++j)
        {
            TrenAutAvi[i][j] = Tren[i][j];
        }
    }

    for (vertice i = Tren.numVert(); i < Aut.numVert() + Tren.numVert(); ++i)
    {
        for (vertice j = Tren.numVert(); j < Aut.numVert() + Tren.numVert(); ++j)
        {
            TrenAutAvi[i][j] = Aut[i - Aut.numVert()][j - Aut.numVert()];
        }
    }

    for (vertice i = (Aut.numVert() + Avi.numVert()); i < Tren.numVert() + Aut.numVert() + Avi.numVert(); ++i)
    {
        for (vertice j = (Aut.numVert() + Avi.numVert()); j < Tren.numVert() + Aut.numVert() + Avi.numVert(); ++j)
        {
            TrenAutAvi[i][j] = Avi[i - (Aut.numVert() + Avi.numVert())][j - (Aut.numVert() + Avi.numVert())];
        }
    }

    // Diagonal a 0

    for (vertice i = 0; i < Tren.numVert() + Aut.numVert() + Avi.numVert(); ++i)
    {
        TrenAutAvi[i][i] = 0;
    }

    // Costes taxi1 - Como el Ejercicio9, modificar las conexiones de los taxis para ver como
    // cambia los valores del coste minimo
    for (vertice i = 0; i < Tren.numVert(); ++i)
    {
        for (vertice j = Tren.numVert(); j < Tren.numVert() + Aut.numVert(); ++j)
        {
            TrenAutAvi[i][j] = taxi1;
        }
    }

    for (vertice i = Tren.numVert(); i < Tren.numVert() + Aut.numVert(); ++i)
    {
        for (vertice j = 0; j < Aut.numVert(); ++j)
        {
            TrenAutAvi[i][j] = taxi1;
        }
    }

    // Costes taxi2
    for (vertice i = 0; i < Tren.numVert() + Aut.numVert(); ++i)
    {
        for (vertice j = Tren.numVert() + Aut.numVert(); j < Tren.numVert() + Aut.numVert() + Avi.numVert(); ++j)
        {
            TrenAutAvi[i][j] = taxi2;
        }
    }

    for (vertice i = Tren.numVert() + Aut.numVert(); i < Tren.numVert() + Aut.numVert() + Avi.numVert(); ++i)
    {
        for (vertice j = 0; j < Aut.numVert() + Avi.numVert(); ++j)
        {
            TrenAutAvi[i][j] = taxi2;
        }
    }

    //std::cout << TrenAutAvi << std::endl;

    trenInicio = Dijkstra(TrenAutAvi, origen, vV1);
    busInicio = Dijkstra(TrenAutAvi, origen + Aut.numVert(), vV2);
    aviInicio = Dijkstra(TrenAutAvi, origen + Aut.numVert() * 2, vV3);

    if (aviInicio[destino] > busInicio[destino] && busInicio[destino] > trenInicio[destino])
    {
        ruta = vV1;
        return trenInicio[destino];
    }
    else
    {
        if (aviInicio[destino] < busInicio[destino] && busInicio[destino] < trenInicio[destino])
        {
            ruta = vV3;
            return aviInicio[destino];
        }
        else
        {
            ruta = vV2;
            return busInicio[destino];
        }
    }
}
#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste viaje(const GrafoP<tCoste> &Aut, const GrafoP<tCoste> &Tren, vertice origen, vertice destino, int costeTaxi)
{
    tCoste costeTotal;
    GrafoP<tCoste> TrenAut(Aut.numVert() + Tren.numVert());
    vector<vertice> vV(Aut.numVert() + Tren.numVert());
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

    // Coste del Taxi, modificar ambos bucles anidados porque si no siempre saldra como valor min
    // el del taxi ya que creo lineas "directas" a los nodos del otro Grafo que uno
    for (vertice i = 0; i < (Tren.numVert()); ++i)
    {
        for (vertice j = Tren.numVert(); j < (Tren.numVert() + Aut.numVert()); ++j)
        {
            TrenAut[i][j] = costeTaxi;
        }
    }

    for (vertice i = Tren.numVert(); i < (Tren.numVert() + Aut.numVert()); ++i)
    {
        for (vertice j = 0; j < Tren.numVert(); ++j)
        {
            TrenAut[i][j] = costeTaxi;
        }
    }

    //Poner a 0 la diagonal
    for (vertice i = 0; i < Tren.numVert() + Aut.numVert(); ++i)
    {
        TrenAut[i][i] = 0;
    }

    // Mirar grafo para entender lo de arriba
    //std::cout << TrenAut << std::endl;

    trenInicio = Dijkstra(TrenAut, origen, vV);
    busInicio = Dijkstra(TrenAut, origen + Aut.numVert(), vV);

    if (trenInicio[destino] < busInicio[destino])
        return trenInicio[destino];
    else
        return busInicio[destino];
}
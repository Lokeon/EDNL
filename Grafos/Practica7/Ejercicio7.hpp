#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste Cambios2(const GrafoP<tCoste> &Tren, const GrafoP<tCoste> &Aut, vertice cambio1, vertice cambio2, vertice origen, vertice destino, vector<vertice> &vertices)
{
    vector<vertice> vV;

    vector<tCoste> desdetren(Tren.numVert());
    vector<tCoste> desdebus(Aut.numVert());

    tCoste camino;

    desdetren = Dijkstra(Tren, origen, vV);
    desdebus = DijkstraInv(Aut, destino, vV);

    vertices.push_back(origen);

    if (suma(desdetren[cambio1], desdebus[cambio1]) > suma(desdetren[cambio2], desdebus[cambio2]))
    {
        vertices.push_back(cambio2);
        camino = suma(desdetren[cambio2], desdebus[cambio2]);
    }
    else
    {
        vertices.push_back(cambio1);
        camino = suma(desdetren[cambio1], desdebus[cambio1]);
    }

    vertices.push_back(destino);
    return camino;
}

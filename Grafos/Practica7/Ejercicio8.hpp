#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
int trasbordo(const GrafoP<tCoste> &Aut, const GrafoP<tCoste> &Tren, vertice origen, vertice destino)
{
    vector<vertice> vV(Aut.numVert());
    vector<tCoste> origenBus, origenTren, destinoBus, destinoTren;
    tCoste costeTotalCombinado, costeTotalsinCombinado, minCombinado, minSinCombinado;

    int i, j;
    origenBus = Dijkstra(Aut, origen, vV);
    origenTren = Dijkstra(Tren, origen, vV);
    destinoBus = DijkstraInv(Aut, destino, vV);
    destinoTren = DijkstraInv(Tren, destino, vV);
    minCombinado = GrafoP<tCoste>::INFINITO;
    minSinCombinado = GrafoP<tCoste>::INFINITO;
    i = 0;
    j = 0;

    // El enunciado es un poco confuso, te dice que el transbordo es un cambio de transporte
    // pero luego te dice que puede ser combinado o no, aunque bueno que cambie no indica
    // que tenga que ser distintos...
    while (i < Aut.numVert() && j < Aut.numVert())
    {
        if (i != origen || destino != j)
        {
            costeTotalCombinado = std::min((suma(origenBus[j], destinoTren[i])), (suma(origenTren[j], destinoBus[i])));
            costeTotalsinCombinado = std::min((suma(origenBus[j], destinoBus[i])), (suma(origenTren[j], destinoTren[i])));
            if (costeTotalCombinado < minCombinado)
                minCombinado = costeTotalCombinado;
            if (costeTotalsinCombinado < minSinCombinado)
                minSinCombinado = costeTotalCombinado;
        }
        ++i;
        ++j;
    }

    return ((minCombinado < minSinCombinado) ? minCombinado : minSinCombinado);
}
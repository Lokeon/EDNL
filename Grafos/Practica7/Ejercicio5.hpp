#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
vector<bool> alergia(const GrafoP<tCoste> &Aut, const GrafoP<tCoste> &Avi, const GrafoP<tCoste> &Tre, int presupuesto, vertice ciudad)
{
    int alergia = 0;
    GrafoP<tCoste> unionMinimo(Aut.numVert());
    vector<vertice> vV(Aut.numVert());
    vertice posicionj = 0;
    vector<tCoste> costesFinales(Aut.numVert());
    vector<bool> ciudades(Aut.numVert(), false);
    tCoste min;

    std::cout << "Alergia:" << std::endl;
    std::cin >> alergia;

    // Me dio pereza hacer un enum... , asi que case 1 es que tiene alergia al avion,
    // case 2 alergia al tren y case 3 que tiene alergia al autobus
    switch (alergia)
    {
    case 1:
        for (vertice i = 0; i < Aut.numVert(); ++i)
        {
            for (vertice j = 0; j < Aut.numVert(); ++j)
            {
                unionMinimo[i][j] = (std::min(Aut[i][j], Tre[i][j]));
            }
        }

        std::cout << unionMinimo << std::endl;
        break;
    case 2:
        for (vertice i = 0; i < Aut.numVert(); ++i)
        {
            for (vertice j = 0; j < Aut.numVert(); ++j)
            {
                unionMinimo[i][j] = (std::min(Aut[i][j], Avi[i][j]));
            }
        }
        break;
    case 3:
        for (vertice i = 0; i < Aut.numVert(); ++i)
        {
            for (vertice j = 0; j < Aut.numVert(); ++j)
            {
                unionMinimo[i][j] = (std::min(Avi[i][j], Tre[i][j]));
            }
        }
        break;
    }

    for (vertice i = 0; i < costesFinales.size(); ++i)
    {
        costesFinales = Dijkstra(unionMinimo, ciudad, vV);
        min = GrafoP<tCoste>::INFINITO;

        for (vertice j = 0; j < costesFinales.size(); ++j)
        {

            if (min > costesFinales[j] && presupuesto >= 0 && ciudades[j] == false && costesFinales[j] != 0)
            {
                min = costesFinales[j];
                posicionj = j;
            }
        }

        if ((presupuesto - min) >= 0)
        {
            presupuesto -= min;
            ciudades[posicionj] = true;
        }
        else
        {
            std::cout << presupuesto << std::endl;
            return ciudades;
        }
        ciudad = posicionj;
    }
    std::cout << presupuesto << std::endl;
    return ciudades;
}
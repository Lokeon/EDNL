#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste sumaCostes(const vector<tCoste> &costes)
{
    tCoste coste = 0;

    for (vertice i = 0; i < costes.size(); ++i)
    {
        coste += costes[i];
    }

    return coste;
}

template <typename tCoste>
vertice mejorCiudadCostera(const GrafoP<tCoste> &ciudad, const vector<int> &costas)
{
    vector<vertice> vCiudad(ciudad.numVert());
    tCoste min = GrafoP<tCoste>::INFINITO;
    tCoste costeTotal;
    int nodo;

    for (int i = 0; i < costas.size(); ++i)
    {
        costeTotal = sumaCostes(DijkstraInv(ciudad, costas.at(i), vCiudad));

        if (min > costeTotal)
        {
            min = costeTotal;
            nodo = i;
        }
    }

    return costas.at(nodo);
}

template <typename tCoste>
void ciudadCosteraUnida(const GrafoP<tCoste> &Deimos, const GrafoP<tCoste> &Fobos, const vector<int> &fobs, const vector<int> &deims)
{
    vertice cD = mejorCiudadCostera(Deimos, deims);
    vertice cF = mejorCiudadCostera(Fobos, fobs);
    

    std::cout << "Mejor ciudad costera Deimos:" << cD << std::endl;
    std::cout << "Mejor ciudad costera Fobos:" << cF << std::endl;
}

#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste distribucionAlmacen(const GrafoP<tCoste> &G, vertice origen, int stock, vector<tCoste> &cantCiu, vector<tCoste> &capaCiu, vector<tCoste> &pCiu)
{
    vector<vertice> vV(G.numVert());
    vector<tCoste> vC = Dijkstra(G, origen, vV);
    tCoste coste = 0;
    int posicionj; // Posicion de menor coste para repartir;
    int posicioni;
    int i = 1; // Iterator
    int j = 0; // Iterator
    int N = G.numVert();

    while (i < N && j < pCiu.size())
    {
        vC[i] -= (pCiu[j] * vC[i]) / 100;
        ++i;
        ++j;
    }

    //std::cout << vC << std::endl;
    // Cambiar condiciones, ya que esta hecho para que el origen sea 0
    while (stock != 0)
    {
        j = 0;
        i = 1;
        tCoste max = GrafoP<tCoste>::INFINITO; // Para mirar el menor coste
        while (i < N)
        {
            if (max > vC[i] && capaCiu[j] != 0)
            {
                max = vC[i];
                posicionj = j;
                posicioni = i;
            }
            ++j;
            ++i;
        }

        while (capaCiu[posicionj] != 0 && stock != 0)
        {
            capaCiu[posicionj] -= 1;
            cantCiu[posicionj] += 1;
            stock -= 1;

            coste += vC[posicioni];
        }
    }

    return coste;
}
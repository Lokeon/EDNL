#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
int cementosZuelandia(const GrafoP<tCoste> &G, vertice capital, const vector<tCoste> &parteDiario)
{
    matriz<vertice> mV(G.numVert());
    matriz<tCoste> mC = Floyd(G, mV);
    tCoste kiloTotales = 0;

    int j = 0; // Para el parteDiario

    for (vertice i = 1; i < G.numVert(); ++i) // Lo comienzo en 1 ya que mi capital esta en 0,
                                              // cambiar condiciones si cambias la capital
    {
        kiloTotales += (mC[i][capital] + mC[capital][i]) * parteDiario[j];
        ++j;
    }

    return kiloTotales;
}
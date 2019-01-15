#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>

template <typename tCoste>
tCoste pseudocentro(const GrafoP<tCoste> &G)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> mV(G.numVert());
    matriz<tCoste> mC = Floyd(G, mV);
    vector<tCoste> diam = {0, 0};
    tCoste diametro = GrafoP<tCoste>::INFINITO;
    vertice pseo;

    for (vertice i = 0; i < G.numVert(); ++i)
    {
        for (vertice j = 0; j < G.numVert(); ++j)
        {
            if (mC[i][j] >= diam[0])
            {
                diam[1] = diam[0]; // actualiza el valor
                diam[0] = mC[i][j];
            }
            else
            {
                if (mC[i][j] >= diam[1])
                {
                    diam[1] = mC[i][j];
                }
            }
        }

        if (diametro > (diam[0] + diam[1]))
        {
            diametro = diam[0] + diam[1];
            pseo = i;
        }

        diam[0] = 0;
        diam[1] = 0;
    }

    std::cout << mC << std::endl;
    std::cout << "Pseudocentro"
              << " " << pseo << std::endl;

    return diametro;
}

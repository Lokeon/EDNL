#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste reteUni3(const GrafoP<tCoste> &G)
{
    GrafoP<tCoste> A(G.numVert());
    tCoste fibra;

    A = Kruskall(G);
    fibra = 0;

    //std::cout << A << std::endl;

    for (vertice i = 0; i < G.numVert(); ++i)
    {
        for (vertice j = 0; j < G.numVert(); ++j) // Esto es importante, si no te va a salir el
                                                  // doble del coste real
        {
            if (A[i][j] != GrafoP<tCoste>::INFINITO)
            {
                fibra += A[i][j];
            }
        }
    }

    return fibra;
}

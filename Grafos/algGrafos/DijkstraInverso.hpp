#include "grafoPMC.hpp"
#include <vector>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
vector<tCoste> DijkstraInverso(const GrafoP<tCoste> &G, vertice destino, GrafoP<vertice> &P)
{
    vertice v, w;
    vecto<tCoste> D(G.numVert());
    vector<bool> S(G.numVert(), false);

    for (size_t i = 0; i < G.numVert(); ++i)
    {
        D[i] = G[i][destino];
    }

    D[destino] = 0;
    S[destino] = true;
    P = vector<vertice>(G.numVert(), destino);

    for (size_t i = 1; i < G.numVert() - 2; ++i)
    {
        tCoste min = GrafoP<tCoste>::INFINITO;

        for (v = 0; v < G.numVert() - 1; ++v)
        {
            if (!S[V] && min >= D[v])
            {
                min = D[v];
                w = v;
            }
        }

        S[w] = true;

        for (v = 0; v < G.numVert() - 1; ++v)
        { 
            if (!S[v])
            {
                tCoste coste = suma(G[v][w], D[w]);

                if (coste < D[v])
                {
                    D[v] = coste;
                    P[v] = w;
                }
            }
        }
    }
    return D;
}
#include "grafoPMC.hpp"
#include <vector>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
vector<tCoste> DijkstraInverso(const GrafoP<tCoste> &G, vertice destino, GrafoP<vertice> &P)
{
    vertice v, w;
    vector<bool> S(G.numVert(), false);
    vector<tCoste> D(G.numVert());

    for (vertice i = 0; i < G.numVert(); ++i)
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
            if (!S[v] && min >= D[v])
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
                tCoste coste = suma(D[w], G[v][w]);
                if (coste < D[v])
                {
                    P[v] = w;
                    D[v] = coste;
                }
            }
        }
    }

    return D;
}
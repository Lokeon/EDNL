#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
void carreteraRebelde(GrafoP<tCoste> &G)
{
    int x, y;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Carretera:" << std::endl;
        std::cin >> x >> y;

        G[x][y] = GrafoP<tCoste>::INFINITO;
    }
}

template <typename tCoste>
void ciudadRebelde(GrafoP<tCoste> &G)
{
    int x;

    std::cout << "Ciudad:" << std::endl;
    std::cin >> x;

    for (vertice i = 0; i < G.numVert(); ++i)
    {
        G[x][i] = GrafoP<tCoste>::INFINITO;
        G[i][x] = GrafoP<tCoste>::INFINITO;
    }
}

template <typename tCoste>
void Zuelandia(GrafoP<tCoste> &G, const typename GrafoP<tCoste>::vertice capital)
{
    vector<vertice> vertices(G.numVert());
    vector<tCoste> vD;
    vector<tCoste> vDInv;

    std::cout << "Zuelandia" << G << std::endl;

    carreteraRebelde(G);
    ciudadRebelde(G);

    vD = Dijkstra(G, capital, vertices);
    vDInv = DijkstraInv(G, capital, vertices);

    for (vertice i = 0; i < G.numVert(); ++i)
    {
        for (vertice j = 0; j < G.numVert(); ++j)
        {
            G[i][j] = suma(vD[j], vDInv[i]);
        }
    }

    std::cout << "Zuelandia Rebelde" << G << std::endl;
}

#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>

typedef typename GrafoP<unsigned int>::vertice vertice;

//INCOMPLETO

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
void Zuelandia2(GrafoP<tCoste> &G, const typename GrafoP<tCoste>::vertice capital)
{
    matriz<tCoste> res;
    matriz<vertice> re(G.numVert());

    std::cout << "Zuelandia" << G << std::endl;

     carreteraRebelde(G);
     ciudadRebelde(G);

    matriz<tCoste> res1 = Floyd(G,re);
    
    for (vertice i = 0; i < G.numVert(); ++i)
    {
        for (vertice j = 0; j < G.numVert(); ++j)
        {
            res[i][j] = 0;
        }
    }

    // std::cout << "Dijkstra:" << vD << std::endl;
    // std::cout << "DijkstraInv:" << vDInv << std::endl;

    // for (vertice i = 0; i < G.numVert(); ++i)
    // {
    //     for (vertice j = 0; j < G.numVert(); ++j)
    //     {
    //         if (i != j)
    //             res[i][j] = (res1[i][capital] + res1[capital][j]);
    //     }
    // }

    std::cout << "Zuelandia Rebelde" << G << std::endl;
}

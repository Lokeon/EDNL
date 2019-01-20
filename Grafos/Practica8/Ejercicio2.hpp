#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/listaenla.hpp"
#include "../algGrafos/grafoMA.hpp"
#include "../algGrafos/particion.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

struct coordenada
{
    coordenada(int id) : id_(id) {}
    void insertarCoordenada(double x, double y)
    {
        x_ = x;
        y_ = y;
    }
    bool operator==(const coordenada &A)
    {
        return (A.id_ == id_);
    }

    int id_;
    double x_, y_;
};

double distanciaEuclidea(const Lista<coordenada> &lineasAerea, int i, int j)
{
    double x = (lineasAerea.elemento(lineasAerea.buscar(j)).x_ - lineasAerea.elemento(lineasAerea.buscar(i)).x_);
    double y = (lineasAerea.elemento(lineasAerea.buscar(j)).y_ - lineasAerea.elemento(lineasAerea.buscar(i)).y_);

    return sqrt((pow(x, 2) + pow(y, 2)));
}

GrafoP<double> crearGrafo(const Grafo &G, const Lista<coordenada> &lineasAereas, GrafoP<double> &Gr)
{
    int posi, posj;
    double coste, min;

    for (vertice i = 0; i < G.numVert(); ++i)
    {
        min = GrafoP<double>::INFINITO;

        for (vertice j = 0; j < G.numVert(); j++)
        {
            if (G[i][j])
            {
                coste = distanciaEuclidea(lineasAereas, i, j);
                if (min > coste)
                {
                    min = coste;
                    posi = i;
                    posj = j;
                }
            }
            else
                Gr[i][j] = GrafoP<double>::INFINITO;
        }
        Gr[posi][posj] = min;

    }

    std::cout << Gr << std::endl;
    return Gr;
}

// Se puede cambiar la distribucion del ejercicio, haciendo que esta llame a todas las demas funciones
// pero, pereza cambiarlo...
Particion disitribucion(const GrafoP<double> &G)
{
    Particion dist(G.numVert());
    matriz<vertice> mV(G.numVert());
    matriz<double> costes;
    vertice x, y;

    costes = Floyd(G, mV);

    for (vertice i = 0; i < G.numVert(); ++i)
    {
        for (vertice j = 0; j < G.numVert(); ++j)
        {
            x = dist.encontrar(i);
            y = dist.encontrar(j);

            if (x != y)
                dist.unir(x, y);
        }
    }

    return dist;
}
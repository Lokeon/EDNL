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
    coordenada(int id):id_(id){}
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

double distanciaEuclidea(const Lista<coordenada> &carretera, int i, int j)
{
    double x = (carretera.elemento(carretera.buscar(j)).x_ - carretera.elemento(carretera.buscar(i)).x_);
    double y = (carretera.elemento(carretera.buscar(j)).y_ - carretera.elemento(carretera.buscar(i)).y_);

    return sqrt((pow(x, 2) + pow(y, 2)));
}

GrafoP<double> crearGrafo(const Grafo &G, const Lista<coordenada> &carreteras, GrafoP<double> &Gr)
{
    for (vertice i = 0; i < G.numVert(); ++i)
    {
        for (vertice j = 0; j < G.numVert(); j++)
        {
            if (G[i][j])
                Gr[i][j] = distanciaEuclidea(carreteras, i, j);
            else
                Gr[i][j] = GrafoP<double>::INFINITO;
        }
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
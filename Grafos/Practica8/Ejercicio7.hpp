#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/listaenla.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

typedef typename GrafoP<double>::vertice vertice;

struct coordenada
{
    coordenada(int id) : id_(id) {}
    bool operator==(const coordenada &A) { return A.id_ == id_; }
    int x() const { return x_; }
    int y() const { return y_; }
    int id() const { return id_; }
    void insertarCoordenada(double x, double y)
    {
        x_ = x;
        y_ = y;
    }
    int id_; // id unico de cada isla
    double x_, y_;
};

int tamanoLista(const Lista<coordenada> &lis)
{
    typedef typename Lista<coordenada>::posicion pos;
    int n = 0;

    for (pos p = lis.primera(); p != lis.fin(); p = lis.siguiente(p))
    {
        ++n;
    }

    return n;
}

void MejorPuente(const Lista<coordenada> &Fobos, const Lista<coordenada> &Deimos, double coste, int idFobos, int idDeimos)
{
    int min = GrafoP<double>::INFINITO;
    typedef typename Lista<coordenada>::posicion pos;

    for (pos priF = Fobos.primera(); priF != Fobos.fin(); priF = Fobos.siguiente(priF))
    {
        for (pos priD = Deimos.primera(); priD != Fobos.fin(); priD = Deimos.siguiente(priD))
        {
            coste = distanciaEuclidea(Fobos.elemento(priF), Deimos.elemento(priD));

            if (min > coste)
            {
                min = coste;
                idDeimos = Deimos.elemento(priD).id();
                idFobos = Fobos.elemento(priF).id();
            }
        }
    }
}

double distanciaEuclidea(coordenada c1, coordenada c2)
{
    double x = c2.x() - c1.x();
    double y = c2.y() - c2.y();

    return sqrt(pow(x, 2) + pow(y, 2));
}

GrafoP<double> grafo(const Lista<coordenada> &lis)
{
    typedef typename Lista<coordenada>::posicion pos;
    int i, j, n;

    pos primera1 = lis.primera();
    pos primera2 = lis.primera();
    i = 0;
    n = tamanoLista(lis);
    GrafoP<double> costes(n);

    while (i < n && primera1 != lis.fin())
    {
        j = 0;
        while (j < n && primera2 != lis.fin())
        {
            if (i != j)
            {
                costes[i][j] = distanciaEuclidea(lis.elemento(primera1), lis.elemento(primera2));
                ++j;
                primera2 = lis.siguiente(primera2);
            }
            else
            {
                costes[i][j] = 0;
                ++j;
                primera2 = lis.siguiente(primera2);
            }
        }
        ++i;
        primera1 = lis.siguiente(primera1);
    }
}

GrafoP<double> unirGrafos(const GrafoP<double> &Fobos, const GrafoP<double> &Deimos)
{
    GrafoP<double> greco(Fobos.numVert() + Deimos.numVert());

    for (vertice i = 0; i < Fobos.numVert(); ++i)
    {
        for (vertice j = 0; j < Fobos.numVert(); ++j)
        {
            greco[i][j] = Fobos[i][j];
        }
    }

    for (vertice i = Fobos.numVert(); i < Fobos.numVert() + Deimos.numVert(); ++i)
    {
        for (vertice j = Fobos.numVert(); j < Fobos.numVert() + Deimos.numVert(); ++j)
        {
            greco[i][j] = Deimos[i - Fobos.numVert()][j - Fobos.numVert()];
        }
    }

    return greco;
}

// cFobos = ciudadesCosteras de Fobos y cDeimos = ...
void Grecoland(const Lista<coordenada> &Fobos, const Lista<coordenada> &Deimos, const Lista<coordenada> &cFobos, const Lista<coordenada> &cDeimos, vertice origen, vertice destino)
{
    double costePuente;
    int idCosteraFobos, idCosteraDeimos;

    GrafoP<double> gFobos = grafo(Fobos);
    GrafoP<double> gDeimos = grafo(Deimos);

    // Los id de cada uno los quiero, para cuando luego una los dos grafos en uno solo
    // poner el coste del puente, y como mi struct de coordenadas es con un id unico
    // por isla, con tener los id puedo saber la posicion de cada uno.
    MejorPuente(cDeimos, cFobos, costePuente, idCosteraFobos, idCosteraDeimos);
    GrafoP<double> realFobos = Kruskall(gFobos);
    GrafoP<double> realDeimos = Kruskall(gDeimos);

    GrafoP<double> greco = unirGrafos(realFobos, realDeimos);
    greco[idCosteraFobos][idCosteraDeimos + gFobos.numVert()] = costePuente; // coste del puente
    greco[idCosteraDeimos + gFobos.numVert()][idCosteraFobos] = costePuente; // coste del puente

    vector<vertice> vV(greco.numVert());
    vector<double> costeTotal;

    costeTotal = Dijkstra(greco, origen, vV);

    std::cout << "El coste hacia el destino es:"
              << " " << costeTotal[destino] << std::endl;
}
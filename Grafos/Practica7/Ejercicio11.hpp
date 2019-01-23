#include "../algGrafos/alg_grafoPMC.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;
// la coordenada ha sido por propia interpretacion, se podria hacer sin esta,
// suponiendo que te dan 3 listas
struct coordenada
{
    int x_, y_;
    coordenada(int x, int y) : x_(x), y_(y) {}
};

std::ostream &operator<<(std::ostream &os, const vector<coordenada> &puente)
{
    for (int i = 0; i < puente.size(); ++i)
    {
        os << puente[i].x_ << "," << puente[i].y_ << std::endl;
    }

    return os;
}

template <typename tCoste>
void huries(const GrafoP<tCoste> &Isla1, const GrafoP<tCoste> &Isla2, const GrafoP<tCoste> &Isla3, vector<coordenada> &puente, matriz<tCoste> &costesIsla)
{
    GrafoP<tCoste> Isla(Isla1.numVert() + Isla2.numVert() + Isla3.numVert());
    matriz<vertice> mV(Isla1.numVert() + Isla2.numVert() + Isla3.numVert());

    for (vertice i = 0; i < Isla2.numVert(); ++i)
    {
        for (vertice j = 0; j < Isla2.numVert(); ++j)
        {
            Isla[i][j] = Isla2[i][j];
        }
    }

    for (vertice i = Isla2.numVert(); i < Isla1.numVert() + Isla2.numVert(); ++i)
    {
        for (vertice j = Isla2.numVert(); j < Isla1.numVert() + Isla2.numVert(); ++j)
        {
            Isla[i][j] = Isla1[i - Isla1.numVert()][j - Isla1.numVert()];
        }
    }

    for (vertice i = (Isla1.numVert() + Isla3.numVert()); i < Isla2.numVert() + Isla1.numVert() + Isla3.numVert(); ++i)
    {
        for (vertice j = (Isla1.numVert() + Isla3.numVert()); j < Isla2.numVert() + Isla1.numVert() + Isla3.numVert(); ++j)
        {
            Isla[i][j] = Isla3[i - (Isla1.numVert() + Isla3.numVert())][j - (Isla1.numVert() + Isla3.numVert())];
        }
    }

    // Puentes gratis ... = 0
    for (vertice i = 0; i < puente.size(); ++i)
    {
        Isla[puente[i].x_][puente[i].y_] = 0;
    }

    costesIsla = Floyd(Isla, mV);

    // Los 0 que no son la diagonal son por los puentes gratis
    std::cout << "Costes Minimos" << std::endl;
    std::cout << costesIsla << std::endl;
}
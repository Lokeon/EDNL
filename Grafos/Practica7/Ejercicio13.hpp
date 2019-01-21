#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/listaenla.hpp"
#include <iostream>
#include <algorithm>

typedef typename GrafoP<unsigned int>::vertice vertice;

template <typename tCoste>
tCoste sumaVector(const vector<tCoste> &coste)
{
    tCoste coste = 0;

    for (vertice i = 0; i < coste.size(); ++i)
    {
        coste += coste.at(i);
    }
}

template <typename tCoste>
vertice mejorCiudadCostera1(const GrafoP<tCoste> &G, const Lista<vertice> &isla)
{
    typedef typename Lista<vertice>::posicion posicion;

    vector<vertice> vV(G.numVert());
    vertice min = GrafoP<tCoste>::INFINITO;
    tcoste coste;

    for (posicion pos = isla.primera(); pos != isla.fin(); pos = isla.siguiente(pos))
    {
        coste = sumaVector(DijkstraInv(G, isla.elemento(pos), vV));
        if (min > coste)
        {
            min = coste;
        }
    }

    return min;
}

// bastante feo visualmente, mejor quedaria todo en 3 variables
template <typename tCoste>
GrafoP<tCoste> archipielagoUnido(const GrafoP<tCoste> &Isla1, const GrafoP<tCoste> &Isla2, const GrafoP<tCoste> &Isla3)
{
    GrafoP<tCoste> archi(Isla1.numVert() + Isla2.numVert() + Isla3.numVert());

    for (vertice i = 0; i < Isla1.numVert(); ++i)
    {
        for (vertice j = 0; j < Isla1.numVert(); ++j)
        {
            archi[i][j] = Isla1[i][j];
        }
    }

    for (vertice i = Isla1.numVert(); i < Isla1.numVert() + Isla2.numVert(); ++i)
    {
        for (vertice j = Isla1.numVert(); j < Isla1.numVert() + Isla2.numVert(); ++j)
        {
            archi[i][j] = Isla2[i - Isla1.numVert()][j - Isla1.numVert()];
        }
    }

    for (vertice i = Isla1.numVert() + Isla2.numVert(); i < Isla1.numVert() + Isla2.numVert() + Isla3.numVert(); ++i)
    {
        for (vertice j = Isla1.numVert() + Isla2.numVert(); j < Isla1.numVert() + Isla2.numVert() + Isla3.numVert(); ++j)
        {
            archi[i][j] = Isla3[i - Isla1.numVert() + Isla2.numVert()][j - Isla1.numVert() + Isla2.numVert()];
        }
    }

    return archi;
}

template <typename tCoste>
tCoste sumaMatriz(const matriz<tCoste> &mC, size_t N)
{
    tcoste coste = 0;

    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; ++j)
        {
            coste += mC[i][j];
        }
    }

    return coste;
}

// ponemos a 0 los costes de las ciudades que se pondrían el puente, para mirar su coste total
template <typename tCoste>
tCoste mejorCamino1(GrafoP<tCoste> &archip, vertice costa1, vertice costa2, vertice costa3, size_t isla1, size_t isla2, size_t isla3)
{
    tCoste coste;
    matriz<vertice> mV(isla1 + isla2 + isla3);

    archip[costa1][costa2 + isla1] = 0;
    archip[costa2 + isla1][costa1] = 0;
    archip[costa2 + isla1][costa3 + isla2 + isla1] = 0;
    archip[costa3 + isla2 + isla1][costa2 + isla1] = 0;

    return coste = sumaMatriz(Floyd(archip, mV), (isla1 + isla2 + isla3));
}

template <typename tCoste>
tCoste mejorCamino2(GrafoP<tCoste> &archip, vertice costa1, vertice costa2, vertice costa3, size_t isla1, size_t isla2, size_t isla3)
{
    tCoste coste;
    matriz<vertice> mV(isla1 + isla2 + isla3);

    archip[costa1][costa2 + isla1 + isla2] = 0;
    archip[costa2 + isla1 + isla2][costa1] = 0;
    archip[costa2 + isla1][costa3 + isla2 + isla1] = 0;
    archip[costa3 + isla2 + isla1][costa2 + isla1] = 0;

    return coste = sumaMatriz(Floyd(archip, mV), (isla1 + isla2 + isla3));
}

template <typename tCoste>
tCoste mejorCamino3(GrafoP<tCoste> &archip, vertice costa1, vertice costa2, vertice costa3, size_t isla1, size_t isla2, size_t isla3)
{
    tCoste coste;
    matriz<vertice> mV(isla1 + isla2 + isla3);

    archip[costa1][costa2 + isla1 + isla2] = 0;
    archip[costa2 + isla1 + isla2][costa1] = 0;
    archip[costa1][costa2 + isla1] = 0;
    archip[costa2 + isla1][costa1] = 0;

    return coste = sumaMatriz(Floyd(archip, mV), (isla1 + isla2 + isla3));
}

template <typename tCoste>
void archipielagoHuries(const GrafoP<tCoste> &Isla1, const GrafoP<tCoste> &Isla2, const GrafoP<tCoste> &Isla3, const Lista<vertice> &CIsla1, const Lista<vertice> &CIsla2, const Lista<vertice> &CIsla3)
{
    vertice costera1, costera2, costera3;
    tcoste coste1, coste2, coste3;
    // podría poner facílmente x3 pero no sabemos si son iguales
    GrafoP<tCoste> archip(Isla1.numVert() + Isla2.numVert() + Isla3.numVert());
    // mejores ciudades Costeras para colocar su puente;
    costera1 = mejorCiudadCostera1(Isla1, CIsla1);
    costera2 = mejorCiudadCostera1(Isla2, CIsla2);
    costera3 = mejorCiudadCostera1(Isla3, CIsla3);

    archip = archipielagoUnido(Isla1, Isla2, Isla3);

    // ahora toca mirar que combinación es mejor poner los puentes tipo:
    // Isla1 - Isla2 - Isla3
    // Isla2 - Isla3 - Isla1
    // Isla3 - Isla1 - Isla2
    // Duda de si realmente son 9 combinaciones o 3 solo, lo hare solo para 3 al menos

    coste1 = mejorCamino1(archip, costera1, costera2, costera3, Isla1.numVert(), Isla2.numVert(), Isla3.numVert());
    coste2 = mejorCamino2(archip, costera1, costera2, costera3, Isla1.numVert(), Isla2.numVert(), Isla3.numVert());
    coste3 = mejorCamino3(archip, costera1, costera2, costera3, Isla1.numVert(), Isla2.numVert(), Isla3.numVert());

    if (coste1 > coste2 && coste2 > coste3)
    {
        std::cout << "El menor coste es:" << coste3 << "Isla3 - Isla1 - Isla2" << std::endl;
    }
    else
    {
        if (coste2 > coste3 && coste3 > coste1)
        {
            std::cout << "El menor coste es:" << coste1 << "Isla1 - Isla2 - Isla3" << std::endl;
        }
        else
        {
            std::cout << "El menor coste es:" << coste2 << "Isla2 - Isla3 - Isla1" << std::endl;
        }
    }
}
#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/alg_grafo_E-S.hpp"
#include "Ejercicio2.hpp"
#include "Ejercicio3.hpp"
#include "Ejercicio4.hpp"
#include <vector>
#include <iostream>

int main()
{

    std::string s = "Dijkstra.dat";

    GrafoP<unsigned int> Gr(s);

    typename GrafoP<unsigned int>::vertice origen = 0;
    typename GrafoP<unsigned int>::vertice destino = 4;

    vector<GrafoP<unsigned int>::vertice> vertices(Gr.numVert());

    // std::cout << "Dijkstra(origen 0): " << Dijkstra(Gr, origen, vertices) << std::endl;
    // std::cout << "DijkstraInverso(destino 4)" << DijkstraInv(Gr, destino, vertices) << std::endl;
}

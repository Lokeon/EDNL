#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/alg_grafo_E-S.hpp"
#include <vector>
#include <iostream>

int main()
{

std::string s = "Dijkstra.dat" ;

GrafoP<unsigned int> Gr(s) ;

typename GrafoP<unsigned int>::vertice origen = 0;

vector <GrafoP<unsigned int>::vertice> vertices (Gr.numVert()) ;



std::cout << "Dijkstra: " << Dijkstra(Gr,origen,vertices) << std::endl ;



}

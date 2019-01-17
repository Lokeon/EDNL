#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/alg_grafo_E-S.hpp"
#include "Ejercicio1.hpp"
#include <iostream>

int main()
{
  GrafoP<unsigned int> G1("Ejercicio1.dat");

  typename GrafoP<unsigned int>::vertice origen;
  typename GrafoP<unsigned int>::vertice destino;

  std::cout << "CosteTotal:"
            << " " << costeViaje(G1, origen, destino) << "Origen:" << origen << "Destino" << destino << std::endl;
}

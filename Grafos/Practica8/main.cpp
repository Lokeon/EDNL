#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/alg_grafo_E-S.hpp"
#include "../algGrafos/grafoMA.hpp"
#include "../algGrafos/listaenla.hpp"
#include "Ejercicio1.hpp"
#include "Ejercicio4.hpp"
#include "Ejercicio5.hpp"
#include "Ejercicio6.hpp"
#include <iostream>

int main()
{
  // Recordar meter una matriz de costes no dirigida
  GrafoP<unsigned int> G4("Ejercicio4.dat");
  GrafoP<unsigned int> G6("Ejercicio6.dat");

  //EJERCICIO1
  // Me da pereza probarlo. . .
  //
  // Lista<coordenada> carreteras;
  // GrafoP<unsigned int> costes(G1.numVert());

  // crearGrafo(G1, carreteras, costes);

  //EJERCICIO4
  // Los 1 que aparecen deberian de ser Infinitos, pero igualmente funciona
  //std::cout << emasejer(G4) << std::endl;

  //EJERCICIO5
  // std::cout << "Coste fibra:"
  //           << " " << reteUni3(G4) << std::endl;

  //EJERCICIO6
  emasejer2(G4,G6,16,12);
}
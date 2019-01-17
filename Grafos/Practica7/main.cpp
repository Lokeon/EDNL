#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/alg_grafo_E-S.hpp"
#include "Ejercicio1.hpp"
#include "Ejercicio3.hpp"
#include "Ejercicio4.hpp"
#include <iostream>

int main()
{
  GrafoP<unsigned int> G1("Ejercicio1.dat");
  GrafoP<unsigned int> G3("Ejercicio3.dat");
  GrafoP<unsigned int> G4("Ejercicio4.dat");

  // EJERCICIO 1
  // typename GrafoP<unsigned int>::vertice origen;
  // typename GrafoP<unsigned int>::vertice destino;
  //           << " " << costeViaje(G1, origen, destino) << " "
  // std::cout << "CosteTotal:"
  //           << "Origen: "
  //           << origen << " "
  //           << "Destino: "
  //           << " " << destino << std::endl;

  //EJERCICIO 3
  // typename GrafoP<unsigned int>::vertice origen3 = 0;
  // std::vector<unsigned int> cantidadCiudad; // Para Comprobar
  // cantidadCiudad.push_back(0);
  // cantidadCiudad.push_back(0);
  // cantidadCiudad.push_back(0);
  // cantidadCiudad.push_back(0);
  // std::vector<unsigned int> capacidadCiudad;
  // capacidadCiudad.push_back(15);
  // capacidadCiudad.push_back(10);
  // capacidadCiudad.push_back(5);
  // capacidadCiudad.push_back(3);
  // std::vector<unsigned int> porcentajeCiudad;
  // porcentajeCiudad.push_back(15);
  // porcentajeCiudad.push_back(30);
  // porcentajeCiudad.push_back(20);
  // porcentajeCiudad.push_back(23);

  // std::cout << "Coste: " << distribucionAlmacen(G3, origen3, 20, cantidadCiudad, capacidadCiudad, porcentajeCiudad) << std::endl;
  // for (int i = 0; i < cantidadCiudad.size(); ++i)
  // {
  //   std::cout << "Ciudad" << i << " "
  //             << "Cantidad Distribuida:" << cantidadCiudad[i] << std::endl;
  // }

  //EJERCICIO4
  typename GrafoP<unsigned int>::vertice capital = 0;
  std::vector<unsigned int> parteDiario; // Para Comprobar
  parteDiario.push_back(2);
  parteDiario.push_back(5);
  parteDiario.push_back(4);
  parteDiario.push_back(5);

  std::cout << "Kilometros totales:"
            << " " << cementosZuelandia(G4, capital, parteDiario) << std::endl;
}
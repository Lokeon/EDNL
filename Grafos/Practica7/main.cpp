#include "../algGrafos/alg_grafoPMC.hpp"
#include "../algGrafos/alg_grafo_E-S.hpp"
#include "Ejercicio1.hpp"
#include "Ejercicio3.hpp"
#include "Ejercicio4.hpp"
#include "Ejercicio5.hpp"
#include "Ejercicio6.hpp"
#include "Ejercicio7.hpp"
#include "Ejercicio8.hpp"
#include "Ejercicio9.hpp"
#include "Ejercicio10.hpp"
#include <iostream>

int main()
{
  GrafoP<unsigned int> G1("Ejercicio1.dat");
  GrafoP<unsigned int> G3("Ejercicio3.dat");
  GrafoP<unsigned int> G4("Ejercicio4.dat");
  GrafoP<unsigned int> avionG5("AvionEj5.dat");
  GrafoP<unsigned int> trenG5("TrenEj5.dat");
  GrafoP<unsigned int> autobusG5("AutobusEj5.dat");
  GrafoP<unsigned int> trenG9("TrenEj9.dat");
  GrafoP<unsigned int> autobusG9("AutobusEj9.dat");
  GrafoP<unsigned int> avionG10("AvionEj10.dat");

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
  // typename GrafoP<unsigned int>::vertice capital = 0;
  // std::vector<unsigned int> parteDiario; // Para Comprobar
  // parteDiario.push_back(2);
  // parteDiario.push_back(5);
  // parteDiario.push_back(4);
  // parteDiario.push_back(5);

  // std::cout << "Kilometros totales:"
  //           << " " << cementosZuelandia(G4, capital, parteDiario) << std::endl;

  //EJERCICIO5
  // unsigned int presupuesto = 55;
  // typename GrafoP<unsigned int>::vertice ciudad = 0;
  // vector<bool> fin = alergia(autobusG5, avionG5, trenG5, presupuesto, ciudad);

  // for (int i = 0; i < autobusG5.numVert(); ++i)
  // {
  //   std::cout << "Ciudad" << i << " " <<  fin[i] << std::endl;
  // }

  //EJERCICIO6
  // typename GrafoP<unsigned int>::vertice ciudad = 2;
  // matriz<unsigned int> fin = agencia(trenG5, autobusG5, ciudad);

  // for (int i = 0; i < autobusG5.numVert(); ++i)
  // {
  //   for (int j = 0; j < autobusG5.numVert(); ++j)
  //   {
  //     std::cout << " " << fin[i][j];
  //   }
  //   std::cout << std::endl;
  // }

  //EJERCICIO7
  // typename GrafoP<unsigned int>::vertice cambio1 = 1;
  // typename GrafoP<unsigned int>::vertice cambio2 = 2;
  // typename GrafoP<unsigned int>::vertice origen = 0;
  // typename GrafoP<unsigned int>::vertice destino = 3;

  // vector<vertice> vertices;

  // std::cout << Cambios2(trenG5, autobusG5, cambio1, cambio2, origen, destino, vertices) << std::endl;
  // for (int i = 0; i < vertices.size(); ++i)
  // {
  //   std::cout <<" "<<  vertices[i];
  // }

  //EJERCICIO8
  // typename GrafoP<unsigned int>::vertice origen = 0;
  // typename GrafoP<unsigned int>::vertice destino = 3;

  // std::cout << trasbordo(autobusG5,trenG5,origen,destino) << std::endl;

  //EJERCICIO9
  // typename GrafoP<unsigned int>::vertice origen = 0;
  // typename GrafoP<unsigned int>::vertice destino = 5;

  // std::cout << viaje(autobusG9,trenG9,origen,destino,45) << std::endl;
}
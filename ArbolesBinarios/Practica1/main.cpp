
#include "../arbolBinario_Din.hpp"
#include "../abin_E-S.hpp"
#include "Ejercicio1.hpp"
#include "Ejercicio2.hpp"


int main()
{
      char op;
      Abin<char> A{}, B{};
      //-----------------Entradas y salidas
      std::cout << "¿Desea rellenar? S/N" ;
      std::cin >> op;
      if(op == 'S')
      {
          cout << "****Lectura del arbol binario A ****\n";
          rellenarAbin<char>(A, '#');

          std::ofstream fs("abin.dat");
          imprimirAbin(fs, A, '#');
          fs.close();
          cout << "\n *****arbol guardado en abin.dat\n";
      }

      //cout << "*****Lectura del arbol binario A desde abin.dat****\n";
      std::ifstream fe("abin.dat");
      rellenarAbin<char>(fe, B);
      fe.close();

      //cout << "\n ****Mostrar �rbol binario B*****\n";
      //imprimirAbin(B);

      //std::cout << "Numero de Nodos:" << contarNodos(B) << std::endl;
      std::cout << "Numero de Nodos:" << contarNodos(B) << std::endl;

      

}

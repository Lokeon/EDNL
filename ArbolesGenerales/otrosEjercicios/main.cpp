#include "../arbolGeneral_Din.hpp"
#include "../agen_E-S.hpp"
#include "densidad.hpp"
#include <iostream>

int main()
{
    Agen<char> A{}, B{}, C{};
    char op;
    //-----------------Entradas y salidas
    cout << "desea rellenar? S/N";
    cin >> op;
    if (op == 'S')
    {
        cout << "****Lectura del arbol general A ****\n";
        rellenarAgen<char>(A, '#');

        std::ofstream fs("abin.dat");
        imprimirAgen<char>(fs, A, '#');
        fs.close();
        cout << "\n *****arbol guardado en abin.dat\n";
    }

    //std::cout << "*****Lectura del arbol binario A desde abin.dat****\n";
    std::ifstream fe("abin.dat");
    rellenarAgen<char>(fe, B);
    fe.close();

    //cout << "el arbol leido de abin.dat es: " << std::endl;
    //imprimirAgen(B);
    densidad(B);
   
}
#include "../arbolGeneral_Din.hpp"
#include "../agen_E-S.hpp"
#include "Ejercicio1.hpp"
#include "Ejercicio2.hpp"
#include "Ejercicio3.hpp"
#include "Ejercicio4.hpp"
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

    // std::cout << "Grado:" << grado(B) << std::endl;
    // std::cout << "Profundidad:" << profundidad(B,B.hermDrcho(B.hijoIzqdo(B.hijoIzqdo(B.raiz())))) << std::endl;
    // std::cout << "Desequilibrio:" << desequilibrio(B) << std::endl;
    // podar(B,'B');
    // imprimirAgen(B);
}

#include "../arbolBinario_Din.hpp"
#include "../abin_E-S.hpp"
#include "Ejercicio1.hpp"
#include "Ejercicio2.hpp"
#include "Ejercicio3.hpp"

int main()
{
    char op;
    Abin<char> A{}, B{}, C{};
    //-----------------Entradas y salidas
    std::cout << "¿Desea rellenar? S/N";
    std::cin >> op;
    if (op == 'S')
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
    std::ifstream fx("abin.dat");
    rellenarAbin<char>(fe, B);
    rellenarAbin<char>(fx, C);
    fe.close();
    fx.close();

    //cout << "\n ****Mostrar �rbol binario B*****\n";
    //imprimirAbin(B);

    // std::cout << "Iguales:" << espejo(B, C) << std::endl;
    // imprimirAbin(B);
    // imprimirAbin(reflejo(B));
    //std::cout << "Profundidad:" << profundidad(B,B.hijoIzqdoB(B.hijoDrchoB(B.raizB()))) << std::endl;
}

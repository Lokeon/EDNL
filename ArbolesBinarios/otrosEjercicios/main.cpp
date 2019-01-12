
#include "../arbolBinario_Din.hpp"
#include "../abin_E-S.hpp"
#include "nostalgicos.hpp"
#include "3nietos.hpp"
#include "esAVL.hpp"
#include "rebeldes.hpp"

int main()
{
    char op;
    Abin<char> A{}, B{};
    Abin<double> C;
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
    rellenarAbin(fe, B);
    fe.close();

    

    //cout << "\n ****Mostrar �rbol binario B*****\n";
    //imprimirAbin(B);

    // nostalgicos(B);
    // tresnietos(B);
    // esAVL(B);
    // rebeldes(B);

}

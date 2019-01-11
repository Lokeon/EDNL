
#include "../ABB_DIN.hpp"
#include "../abb_E-S.hpp"
#include <iostream>
#include "Ejercicio3.hpp"
//#include "Ejercicio4.hpp"
#include "Ejercicio5.hpp"
#include "Ejercicio6.hpp"

int main()
{

	Abb<int> a, b, c;

	a.insertar(30);
	a.insertar(45);
	a.insertar(39);
	a.insertar(18);
	a.insertar(9);
	a.insertar(25);
	a.insertar(3);

	b.insertar(30);
	b.insertar(45);
	b.insertar(39);
	b.insertar(18);
	b.insertar(25);
	b.insertar(3);

	// imprimirAbb(a);

	// a.podar(18);

	// imprimirAbb(a);

	//equilibrar(a,b);

	diferencia(a, b, c);
	imprimirAbb(c);
}

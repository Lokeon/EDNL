#ifndef ABIN_VEC0_H
#define ABIN_VEC0_H
#include <cassert>

template <typename T> class Abin
{
public:
	
	typedef int nodo;	// Índice de la matriz entre 0 y maxNodos - 1
	static const nodo NODO_NULO;
	explicit Abin(int maxNodos);
	void insertarRaizB (const T& e);
	void insertarHijoIzqdoB (nodo n, const T& e);
	void insertarHijoDrchoB (nodo n, const T& e);
	void eliminarHijoIzqdoB (nodo n);
	void eliminarHijoDrchoB (nodo n);
	void eliminarRaizB ();
	~Abin();	// Destructor
	bool arbolVacioB () const;
	const T&  elemento(nodo n) const;
	T&  elemento(nodo n);
	nodo raizB () const;
	nodo padreB (nodo n) const;
	nodo hijoIzqdoB (nodo n) const;
	nodo hijoDrchoB (nodo n) const;
	int profundidadNodo(nodo n) const;
	int alturaNodo(nodo n) const;

	Abin(const Abin<T>& a);	// ctor. de copia
	Abin<T>& operator =(const Abin<T>& a);	// asignación
	
private:
	struct celda
	{
		T elto;
		nodo padre, hizq, hder;
	};
	celda *nodos;	// Vector de celdas
	int maxNodos;	// Tamaño del vector
	int numNodos;	// Número de nodos del árbol en un momento dado
};

// Definición del nodo nulo
template <typename T> 
const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);	// ¿Por qué lo ponemos aquí y no lo inicializamos en la propia clase?¿Qué indica lo de la izquierda?

template <typename T>
inline Abin<T>::Abin(int maxNodos):
	nodos(new celda[maxNodos]), 
	maxNodos(maxNodos), 
	numNodos(0)
{}

template <typename T>
void Abin<T>::insertarRaizB (const T& e)
{
	assert(numNodos == 0);	// Comprobamos que el árbol no esté vacío

	numNodos = 1;
	nodos[0].elto = e;
	nodos[0].padre = NODO_NULO;
	nodos[0].hizq = NODO_NULO;
	nodos[0].hder = NODO_NULO;

}

template <typename T>
void Abin<T>::insertarHijoIzqdoB (Abin<T>::nodo n, const T& e)
{
	assert(n >= 0 && n < numNodos);		// Comprobamos que "n" esté en el árbol
	assert(nodos[n].hizq == NODO_NULO);	// Comprobamos que "hizq" de "n" es un NODO_NULO
	assert(numNodos < maxNodos);		// Comprobamos que el árbol no esté lleno

	// Añadimos el nuevo nodo al final
	nodos[n].hizq = numNodos;
	nodos[numNodos].elto = e;
	nodos[numNodos].padre = n;
	nodos[numNodos].hizq = NODO_NULO;
	nodos[numNodos].hder = NODO_NULO;	

	numNodos++;
}

template <typename T>
void Abin<T>::insertarHijoDrchoB (Abin<T>::nodo n, const T& e)
{
	assert(n >= 0 && n < numNodos);		// Comprobamos que "n" esté en el árbol
	assert(nodos[n].hder == NODO_NULO);	// Comprobamos que "hder" de "n" es un NODO_NULO
	assert(numNodos < maxNodos);		// Comprobamos que el árbol no esté lleno

	// Añadimos el nuevo nodo al final
	nodos[n].hder = numNodos;
	nodos[numNodos].elto = e;
	nodos[numNodos].padre = n;
	nodos[numNodos].hizq = NODO_NULO;
	nodos[numNodos].hder = NODO_NULO;	

	numNodos++;
}

template <typename T>
void Abin<T>::eliminarHijoIzqdoB (Abin<T>::nodo n)
{
	Abin<T>::nodo hijoizq;

	assert(n >= 0 && n < numNodos);		// Comprobamos que "n" esté en el árbol
	hijoizq = nodos[n].hizq; 
	assert(hijoizq != NODO_NULO);	// Comprobamos que "hizq" de "n" NO es un NODO_NULO
	assert(nodos[hijoizq].hizq == NODO_NULO && nodos[hijoizq].hder == NODO_NULO);	// Comprobamos que hijo izq es hoja

	if(hijoizq != numNodos - 1)	// Comprobamos que "hijoizq" no sea el último
	{
		nodos[hijoizq] = nodos[numNodos - 1];	// Movemos el último nodo a la posición del "hijoizq"
		// Actualizar la posición del hijo (izquierdo o derecho) en el padre del nodo movido
		if(nodos[nodos[hijoizq].padre].hizq == numNodos - 1)
			nodos[nodos[hijoizq].padre].hizq = hijoizq;
		else
			nodos[nodos[hijoizq].padre].hder = hijoizq;
		// Si el nodo movido tiene hijos, actualizar la posición del padre
		if (nodos[hijoizq].hizq != NODO_NULO)
			nodos[nodos[hijoizq].hizq].padre = hijoizq;
		if (nodos[hijoizq].hder != NODO_NULO)
			nodos[nodos[hijoizq].hder].padre = hijoizq;	
	}
	nodos[n].hizq = NODO_NULO;
	numNodos--;
}

template <typename T>
void Abin<T>::eliminarHijoDrchoB (Abin<T>::nodo n)
{
	Abin<T>::nodo hijodrcho;

	assert(n >= 0 && n < numNodos);		// Comprobamos que "n" esté en el árbol
	hijodrcho = nodos[n].hder; 
	assert(hijodrcho != NODO_NULO);	// Comprobamos que "hder" de "n" NO es un NODO_NULO
	assert(nodos[hijodrcho].hder == NODO_NULO && nodos[hijodrcho].hder == NODO_NULO);	// Comprobamos que hijo izq es hoja

	if(hijodrcho != numNodos - 1)	// Comprobamos que "hijodrcho" no sea el último
	{
		nodos[hijodrcho] = nodos[numNodos - 1];	// Movemos el último nodo a la posición del "hijodrcho"
		// Actualizar la posición del hijo (izquierdo o derecho) en el padre del nodo movido
		if(nodos[nodos[hijodrcho].padre].hder == numNodos - 1)
			nodos[nodos[hijodrcho].padre].hder = hijodrcho;
		else
			nodos[nodos[hijodrcho].padre].hizq = hijodrcho;
		// Si el nodo movido tiene hijos, actualizar la posición del padre
		if (nodos[hijodrcho].hizq != NODO_NULO)
			nodos[nodos[hijodrcho].hizq].padre = hijodrcho;
		if (nodos[hijodrcho].hder != NODO_NULO)
			nodos[nodos[hijodrcho].hder].padre = hijodrcho;	
	}
	nodos[n].hder = NODO_NULO;
	numNodos--;
}

template <typename T>
inline void Abin<T>::eliminarRaizB()
{
	assert(numNodos == 1);
	numNodos = 0;
}

template <typename T>
inline Abin<T>::~Abin()
{
	delete[] nodos;
}

template <typename T>
inline bool Abin<T>::arbolVacioB() const
{
	return (numNodos == 0);
}

template <typename T>
inline const T& Abin<T>::elemento(Abin <T>::nodo n) const
{
	assert(n >= 0 && n < numNodos);
	return nodos[n].elto;
}

// ¿Por qué hacemos una versión const y otra que no lo es?
template <typename T>
inline T& Abin<T>::elemento(Abin<T>::nodo n)
{
	assert(n >= 0 && n < numNodos);
	return nodos[n].elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raizB() const // ¿Por qué ponemos typename delante de Abin<T>?
{
	Abin<T>::nodo aux;
	aux = NODO_NULO;

	if(numNodos > 0)
		aux = 0;

	return aux;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::padreB(Abin<T>::nodo n) const
{
	assert(n >= 0 && n < numNodos);
	return nodos[n].padre;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoIzqdoB(Abin<T>::nodo n) const
{
	assert(n >= 0 && n < numNodos);
	return nodos[n].hizq;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoDrchoB(Abin<T>::nodo n) const
{
	assert(n >= 0 && n < numNodos);
	return nodos[n].hder;
}

template <typename T>
int Abin<T>::profundidadNodo(Abin<T>::nodo n) const
{
	int prof = 0;
	while(padreB(n) != NODO_NULO)
	{
		prof++;
		n = padreB(n);
	}

	return prof;
}

template <typename T>
int Abin<T>::alturaNodo(Abin<T>::nodo n) const
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		int a = alturaNodo(hijoIzqdoB(n));
		int b = alturaNodo(hijoDrchoB(n));
		if(a > b)
		{
			return 1 + a;
		}
		else
		{
			return 1 + b;
		}
	}
}

template <typename T>
inline Abin<T>::Abin(const Abin<T>& a):
	nodos(new celda[a.maxNodos]), 
	maxNodos(a.maxNodos), 
	numNodos(a.numNodos)
{
	// Copia del vector de los nodos
	for(Abin<T>::nodo n = 0; n <= numNodos - 1; n++)
	{
		nodos[n] = a.nodos[n];
	}
}

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& a)
{
	if (this != &a)
	{  
	// Evitar autoasignación.
	// Destruir el vector y crear uno nuevo si es necesario
		if (maxNodos != a.maxNodos)
		{
			delete[] nodos;
			maxNodos = a.maxNodos;
			nodos = new celda[maxNodos];
		}
	// Copiar el vector
	numNodos = a.numNodos;
	for (Abin<T>::nodo n = 0; n <= numNodos-1; n++)
		nodos[n] = a.nodos[n];
	}
	return *this;
}

#endif // ABIN_VEC0_H
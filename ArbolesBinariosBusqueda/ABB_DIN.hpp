#ifndef ABB_H
#define ABB_H

#include <cassert>


template <typename T>
class Abb {
public:
    Abb(); // constructor
    const Abb& buscar(const T& e) const;
    void insertar(const T& e);
    void eliminar(const T& e);
    bool vacio() const;
    const T& elemento() const;
    const Abb& izqdo() const;
    const Abb& drcho() const;
    Abb(const Abb& A); // ctor. de copia
    Abb& operator =(const Abb& A); // asig. �rboles
    ~Abb(); // destructor

    void podar(const T& elto) ;
    int tamano() const ;

private:
    struct arbol {
    T elto;
    Abb izq, der;
    arbol(const T& e): elto(e) {}
    };
    arbol* r; // ra�z del �rbol
    T borrarMin();
    void copiar(const Abb& A);
    void crearArbolB(Abin<T>& A,typename Abin<T>::nodo n,arbol* p) const;
    int rec_tamano(arbol* r) const ;

};

template <typename T>
inline Abb<T>::Abb() : r(0) {}

template <typename T>
inline bool Abb<T>::vacio() const
{
    return r == 0;
}

template <typename T>
const Abb<T>& Abb<T>::buscar(const T& e) const
{
    if (r == 0) // �rbol vac�o, e no encontrado
        return *this;
    else
        if (e < r->elto) // buscar en sub�rbol izqdo.
            return r->izq.buscar(e);
        else
            if (r->elto < e) // buscar en sub�rbol drcho.
                return r->der.buscar(e);
            else // encontrado e en la ra�z
                return *this;
}

template <typename T>
void Abb<T>::insertar(const T& e)
{
    if (r == 0) // �rbol vac�o
        r = new arbol(e);
    else
        if (e < r->elto) // insertar en el sub�rbol izqdo.
            r->izq.insertar(e);
        else
            if (r->elto < e) // insertar en el sub�rbol drcho.
                r->der.insertar(e);
}

template <typename T>
void Abb<T>::eliminar(const T& e)
{
    if (r != 0)
    { // �rbol no vac�o
        if (e < r->elto) // quitar e del sub�rbol izqdo.
            r->izq.eliminar(e);
        else
            if (r->elto < e) // quitar e del sub�rbol drcho.
                r->der.eliminar(e);
            else // quitar e de la ra�z
                if (r->izq.r == 0 && r->der.r == 0)
                { // 1. Ra�z es hoja
                    delete(r);
                    r = 0; // el �rbol queda vac�o
                }
                else
                    if (r->der.r == 0)
                    { // 2. Ra�z s�lo tiene hijo izqdo.
                        arbol* a = r->izq.r;
                        r->izq.r = 0; // impide destruir el sub�rbol izqdo.
                        delete(r);
                        r = a;
                    }
                    else
                        if (r->izq.r == 0) { // 3. Ra�z s�lo tiene hijo drcho.
                            arbol* a = r->der.r;
                            r->der.r = 0; // impide destruir el sub�rbol drcho.
                            delete(r);
                            r = a;
                        }
                        else // 4. Ra�z tiene dos hijos
                            // Eliminar el m�nimo del sub�rbol derecho y sustituir
                            // el elemento de la ra�z por �ste.
                            r->elto = r->der.borrarMin();
    }
}

// M�todo privado
template <typename T>
T Abb<T>::borrarMin()
// Elimina el nodo que almacena el menor elemento
// del �rbol. Devuelve el elemento del nodo eliminado.
{
    if (r->izq.r == 0)
    { // sub�rbol izquierdo vac�o
        T e = r->elto;
        arbol* hd = r->der.r;
        r->der.r = 0; // impide destruir el sub�rbol drcho
        delete(r);
        r = hd; // sustituir r por el sub�rbol derecho
        return e;
    }
    else
        return r->izq.borrarMin();
}

template <typename T>
inline const T& Abb<T>::elemento() const
{
    assert(r != 0);
    return r->elto;
}

template <typename T>
inline const Abb<T>& Abb<T>::izqdo() const
{
    assert(r != 0);
    return r->izq;
}

template <typename T>
inline const Abb<T>& Abb<T>::drcho() const
{
    assert(r != 0);
    return r->der;
}

template <typename T>
inline Abb<T>::Abb(const Abb<T>& A): r(0)
{
    copiar(A);
}

template <typename T>
Abb<T>& Abb<T>::operator =(const Abb<T>& A)
{
    if (this != &A)
    { // evitar autoasignaci�n
        this->~Abb(); // vaciar el �rbol
        copiar(A);
    }
    return *this;
}

//Copia y destrucci�n de un ABB
template <typename T>
Abb<T>::~Abb()
{
if (r != 0) { // �rbol no vac�o
delete r; // llama a r->hizq.~Abb() y a r->hder.~Abb()
r = 0; // el �rbol queda vac�o
}
}

// M�todo privado
template <typename T>
void Abb<T>::copiar(const Abb<T>& A)
// Copia el �rbol a en *this
{
    if (A.r != 0)
    { // �rbol no vac�o
        r = new arbol(A.r->elto); // copiar ra�z
        r->izq.copiar(A.r->izq); // copiar sub�rbol izqdo.
        r->der.copiar(A.r->der); // copiar sub�rbol drcho.
    }
}


// EJERCICIIO 1
/*
template <typename T>
void Abb<T>::poda(const T& elto)
{
     buscar(elto).~Abb() ;


}*/

template <typename T>
void Abb<T>::podar(const T& elto)
{
     if(!vacio())
     {
         if(elto < r->elto)
         {
            r->izq.podar(elto);
         }
         else
         {
           if(elto > r->elto)
           {
              r->der.podar(elto);
           }
           else
           {
             this->~Abb() ;
           }
         }
     }
}

template <typename T>
int Abb<T>::tamano() const
{
     if(!vacio())
     {
       return rec_tamano(r) ;
     }
     else
     {
       return 0 ;
     }
}

template <typename T>
int Abb<T>::rec_tamano(arbol* b) const
{
    if(b == nullptr)
    {
      return 0 ;
    }
    else
    {
      return 1 + rec_tamano(b->izq.r) + rec_tamano(b->der.r) ;
    }

}



#endif // ABB_H

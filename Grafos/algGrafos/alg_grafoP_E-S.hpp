/*--------------------------------------------------------*/
/* alg_grafoP_E-S.h                                       */
/*                                                        */
/* Operadores y funciones para visualizar los resultados  */
/* de los algoritmos para grafos ponderados implementados */
/* en alg_grafoPMC.h                                      */
/*                                                        */
/* Estructuras de Datos no Lineales                       */
/* ©2016 José Fidel Argudo                                */
/*--------------------------------------------------------*/
/*
Funciones:

   template <typename T>
   ostream& operator <<(ostream& os, const vector<T>& v);
      Inserción de vector<T> en un ostream (para probar Dijkstra).

   template <typename T>
   void insCamino(ostream& os, const typename GrafoP<T>::tCamino& c);
      Inserción de un GrafoP<T>::tCamino en un ostream (para probar
      caminos de Dijkstra y Floyd).

   template <typename T>
   ostream& operator << (ostream& os, const matriz<T>& m);
      Inserción de matriz<T> en un ostream (para probar Floyd).

----------------------------------------------------------*/

#ifndef ALG_GRAFO_P_E_S_H
#define ALG_GRAFO_P_E_S_H

#include "grafoPMC.h"  // grafo ponderado
#include <ostream>
#include <iomanip>           // std::setw

using std::ostream;

// Inserción de vector<T> en un ostream (para probar Dijkstra)
template <typename T>
ostream& operator <<(ostream& os, const vector<T>& v)
{
   for (size_t i = 0; i < v.size(); i++) {
      os << std::setw(4);
      if (v[i] != GrafoP<T>::INFINITO)
         os << v[i];
      else
         os << "-";
   }
   return os;
}

// Inserción de un GrafoP<T>::tCamino en un ostream (para probar
// caminos de Dijkstra y Floyd)
template <typename T>
void insCamino(ostream& os, const typename GrafoP<T>::tCamino& c)
{
   typedef typename GrafoP<T>::tCamino::posicion posicion;
   for (posicion i = c.primera(); i != c.fin(); i = c.siguiente(i))
      os << c.elemento(i) << ' ';
}

// Inserta una matriz<T> en un flujo de salida (para probar Floyd)
template <typename T>
ostream& operator << (ostream& os, const matriz<T>& m)
{
   const size_t n = m.dimension();
   os << "    ";
   for (size_t j = 0; j < n; ++j)
      os << std::setw(4) << j;
   os << std::endl;
   for (size_t i = 0; i < n; ++i) {
      os << std::setw(4) << i;
      for (size_t j = 0; j < n; ++j) {
         os << std::setw(4);
         if (m[i][j] == GrafoP<T>::INFINITO)
            os << "-";
         else
            os << m[i][j];
      }
      os << std::endl;
   }
   return os;
}

#endif   // ALG_GRAFO_P_E_S_H

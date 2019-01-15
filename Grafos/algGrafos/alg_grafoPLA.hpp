#ifndef ALG_GRAFO_PLA_HPP
#define ALG_GRAFO_PLA_HPP

#include "grafoPLA.hpp"
#include <vector>

/*----------------------------------------------------------------------------*/
/* Caminos de coste mínimo                                                    */
/*----------------------------------------------------------------------------*/
// Suma de costes (Dijkstra y Floyd)
template <typename tCoste> 
tCoste suma(tCoste x, tCoste y)
{
   const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
   if (x == INFINITO || y == INFINITO)
      return INFINITO;
   else
      return x + y;
}

template <typename tCoste> 
vector<tCoste> DijkstraLA(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice origen,
                        vector<typename GrafoP<tCoste>::vertice>& P)
{
 
 const size_t tam = G.numVert() ; 
 typedef typename GrafoP<tCoste>::vertice vertice;
 typedef typename GrafoP<tCoste>::vertice_coste vertice_coste;
 vertice_coste v,w ;
 vertice_coste primero{origen, 0 } ; 
  

 vector<bool> S(tam,false);
 vector<tCoste> D(tam);

 typename Lista<vertice_coste>::posicion pos ; 
 const Lista<vertice_coste>& adyace = G.adyacentes(origen);

 for(pos = G.adyacentes(origen).primera(); pos != adyace.fin() ; pos = adyace.siguiente(pos))
 {
     D[adyace.elemento(pos).v] = adyace.elemento(pos).c ; 
 }

 D[origen] = 0 ; 

 P = vector<vertice>(tam,origen) ; 

 S[origen] = true ; 
  
 for (size_t i = 1; i <= tam-2; i++) {
      // Seleccionar vértice w no incluido en S
      // con menor coste desde origen.
      tCoste costeMin = GrafoP<tCoste>::INFINITO;
      for (v.v = 0; v.v < tam; v.v++)
         if (!S[v.v] && D[v.v] <= costeMin) {
            costeMin = D[v.v];
            w.v = v.v;
         }
      S[w.v] = true;                          // Incluir vértice w en S.
      // Recalcular coste hasta cada v no incluido en S a través de w.
      for (v.v = 0; v.v < tam; v.v++)
         if (!S[v.v]) {
            tCoste Owv = suma(D[w.v],G.adyacentes(w.v).elemento(G.adyacentes(w.v).buscar(v)).c);
            if (Owv < D[v.v]) {
               D[v.v] = Owv;
               P[v.v] = w.v;
            }
         }
   }
   return D;

}

#endif //ALG_GRAFO_PLA_HPP
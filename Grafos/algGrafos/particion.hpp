/*--------------------------------------------------------*/
/* particion.h                                            */
/*                                                        */
/* clase Particion: Representa particiones del rango de   */
/*     enteros [0, n-1].                                  */
/*--------------------------------------------------------*/

#ifndef PARTICION_H
#define PARTICION_H

#include <vector>

class Particion
{
public:
  Particion(int n) : padre(n, -1) {}
  void unir(int a, int b);
  int encontrar(int x) const;

private:
  mutable std::vector<int> padre;
};

inline void Particion::unir(int a, int b)
{
  if (padre[b] < padre[a])
    padre[a] = b;
  else
  {
    if (padre[a] == padre[b])
      padre[a]--;
    padre[b] = a;
  }
}

inline int Particion::encontrar(int x) const
{
  int y, raiz = x;

  while (padre[raiz] > -1)
    raiz = padre[raiz];
  while (padre[x] > -1)
  {
    y = padre[x];
    padre[x] = raiz;
    x = y;
  }
  return raiz;
}

#endif

#include "vector.h"

int
main ()
{
  int n = 0;
  struct Vector vector;
  iniciar (&vector);
  printf ("Ingresa un valor para 'n': ");
  scanf ("%d", &n);
  for (int i = 0; i <= n; i++)
    {
      agregar (&vector, i);
      mostrar (&vector);
    }
  return 0;
}

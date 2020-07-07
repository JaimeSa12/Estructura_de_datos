#include "cola.h"

int
main ()
{
  struct nodoCola *atras = NULL;
  //Inserta elementos.
  atras = enqueue (atras, 1);
  atras = enqueue (atras, 2);
  atras = enqueue (atras, 3);
  atras = enqueue (atras, 23);
  atras = enqueue (atras, 120);

  //Muestra cola ingresada.
  mostrar ();
  printf ("\nEl valor de atras (ultimo) es [ %d ]\n\n", atras->dato);

  //Imprime la cola por cada elemento eliminado.
  printf ("Eliminando:\n");
  eliminaImprime (atras);
  return 0;
}

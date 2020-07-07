#include "listaCS.h"

int
main ()
{
  insertar (1);
  insertar (2);
  insertar (3);
  insertar (4);
  insertar (5);
  mostrar ();

  //Elimina por posición.
  eliminarPos (5);
  //Elimina por dato.
  eliminarDato (2);
  eliminarDato (20);

  printf ("\nLista final:\n");
  mostrar ();
  printf ("\n");
  return 0;
}

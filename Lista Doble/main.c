#include "listaD.h"

int
main ()
{
  insertar (1);
  insertar (2);
  insertar (3);
  insertar (4);
  insertar (5);
  printf ("Lista insertada:\n");
  mostrar ();
  //Elimina por posici�n.
  eliminarPos (1);
  //Elimina por dato.
  eliminarDato (5);
  eliminarDato (2);
  eliminarDato (3);

  printf ("\n\nLista final sin elementos eliminados:\n");
  mostrar ();
  printf ("\n");
  return 0;
}

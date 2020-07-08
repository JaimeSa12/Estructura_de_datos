#include "lista.h"

int
main (void)
{
  int n;
  int data;
  int pos;

  struct Lista *miLista = NULL;
  //Ingresa datos a la lista.
  miLista = insertar (miLista, 10);
  miLista = insertar (miLista, 29);
  miLista = insertar (miLista, 11);
  miLista = insertar (miLista, 28);
  miLista = insertar (miLista, 36);

  //Muestra lista original.
  mostrar (miLista);

  //Eliminar
  printf ("\n\nIngresa la posicion a eliminar: ");
  scanf ("%d", &pos);
  eliminar (miLista, pos);

  //Muestra lista con elemento eliminado.
  mostrar (miLista);
  return 0;
}

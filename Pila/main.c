#include "pila.h"

int
main ()
{
  struct nodoPila *cima = NULL;
  struct nodoPila *cimaSec = NULL;
  int pos;
  cima = push (cima, 1);
  cima = push (cima, 2);
  cima = push (cima, 3);
  cima = push (cima, 4);
  cima = push (cima, 5);
  cima = push (cima, 6);
  mostrar (cima);
  cima = pop (cima);
  cima = pop (cima);
  cima = pop (cima);
  printf ("\nPila despues de tres 'POP':\n");
  mostrar (cima);
  return 0;
}

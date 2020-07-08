#include "pila.h"

struct nodoPila *
crear (int dato)
{
  struct nodoPila *nuevo = NULL;
  nuevo = (struct nodoPila *) malloc (sizeof (struct nodoPila));
  if (nuevo == NULL)
    {
      return NULL;
    }
  nuevo->dato = dato;
  nuevo->siguiente = NULL;
  return nuevo;
}

struct nodoPila *
push (struct nodoPila *cima, int dato)
{
  struct nodoPila *nuevo = crear (dato);
  nuevo->siguiente = cima;
  return nuevo;
}

//Elimina elemento 'cima'.
struct nodoPila *
pop (struct nodoPila *cima)
{
  struct nodoPila *aux = cima;
  aux = cima->siguiente;
  free (cima);
  cima = aux;

  return cima;
}

//Imprime la pila en forma LIFO.
struct nodoPila *
mostrar (struct nodoPila *cima)
{
  while (cima != NULL)
    {
      printf ("[ %d ]\n", cima->dato);
      cima = cima->siguiente;
    }
}

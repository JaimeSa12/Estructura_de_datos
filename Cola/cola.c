#include "cola.h"

//Pendiente implenetar 'frente' localmente.
struct nodoCola *frente = NULL;

//Función crear nodo.
struct nodoCola *
crear (int dato)
{
  struct nodoCola *nuevo = NULL;
  nuevo = (struct nodoCola *) malloc (sizeof (struct nodoCola));
  if (nuevo == NULL)
    {
      printf ("No se ha podido crear.\n\n");
    }
  nuevo->dato = dato;
  nuevo->siguiente = NULL;
  return nuevo;
}

//Función insertar elementos a la cola.
struct nodoCola *
enqueue (struct nodoCola *atras, int dato)
{
  struct nodoCola *nuevo = crear (dato);
  if (frente == NULL)
    {
      frente = nuevo;
    }
  else
    {
      atras->siguiente = nuevo;
    }
  return nuevo;
}

//Función imprimir/mostrar.
void
mostrar ()
{
  struct nodoCola *aux = frente;
  if (aux == NULL)
    {
      printf ("Cola vacia.\n");
    }
  while (aux != NULL)
    {
      printf ("[ %d ] ", aux->dato);
      aux = aux->siguiente;
    }
}

//Función eliminar elementos de la cola.
void
dequeue (struct nodoCola *atras)
{
  struct nodoCola *aux = frente;
  if (frente == atras)
    {
      frente = NULL;
      atras = NULL;
    }
  else
    {
      aux = frente->siguiente;
      free (frente);
      frente = aux;
    }
}

//Función eliminar e imprimir los elementos de la cola.
void
eliminaImprime (struct nodoCola *atras)
{
  while (frente != NULL)
    {
      dequeue (atras);
      mostrar ();
      printf ("\n");
    }
}

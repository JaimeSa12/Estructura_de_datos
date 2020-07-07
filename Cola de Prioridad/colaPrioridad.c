#include "colaP.h"

//Pendiente implementar 'frente' localmente.
struct nodoColaP *frente = NULL;

struct nodoColaP *
crear (int dato, int prioridad)
{
  struct nodoColaP *nuevo = NULL;
  nuevo = (struct nodoColaP *) malloc (sizeof (struct nodoColaP));
  if (nuevo == NULL)
    {
      printf ("No se ha podido crear.\n\n");
    }
  nuevo->dato = dato;
  nuevo->prioridad = prioridad;
  nuevo->siguiente = NULL;
  return nuevo;
}

//Función insertar elementos a la cola.
void
enqueue (int dato, int prioridad)
{
  struct nodoColaP *nuevo = crear (dato, prioridad);
  struct nodoColaP *aux = frente;
  if (frente == NULL)
    {
      frente = nuevo;
    }
  else
    {
      if (frente->prioridad < nuevo->prioridad)
	{
	  nuevo->siguiente = frente;
	  frente = nuevo;
	}
      else
	{
	  while (aux->siguiente != NULL
		 && aux->siguiente->prioridad > nuevo->prioridad)
	    {
	      aux = aux->siguiente;
	    }
	  if (aux->siguiente->prioridad == nuevo->prioridad)
	    {
	      while (aux->siguiente != NULL
		     && aux->siguiente->prioridad == nuevo->prioridad)
		{
		  aux = aux->siguiente;
		}
	      nuevo->siguiente = aux->siguiente;
	      aux->siguiente = nuevo;
	    }
	  else
	    {
	      nuevo->siguiente = aux->siguiente;
	      aux->siguiente = nuevo;
	    }
	}
    }
}

//Elimina elementos en forma FIFO.
void
dequeue ()
{
  struct nodoColaP *aux = frente;
  if (frente == NULL)
    {
      printf ("No se puede eliminar: cola vacia.");
    }
  else
    {
      aux = frente->siguiente;
      free (frente);
      frente = aux;
    }
}

//Imprime el dato y prioridad.
void
mostrar ()
{
  struct nodoColaP *aux = frente;
  if (aux == NULL)
    {
      printf ("Cola vacia.\n");
    }
  while (aux != NULL)
    {
      printf ("[%d|%d] ", aux->dato, aux->prioridad);
      aux = aux->siguiente;
    }
}

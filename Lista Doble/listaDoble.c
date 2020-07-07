#include "listaD.h"

//Pendiente implementar 'primero' y 'ultimo' localmente.
struct nodoLista *primero = NULL;
struct nodoLista *ultimo = NULL;

struct nodoLista *
crear (int dato)
{
  struct nodoLista *nuevo = NULL;
  nuevo = (struct nodoLista *) malloc (sizeof (struct nodoLista));
  if (nuevo == NULL)
    {
      printf ("No se ha podido reservar el espacio.\n");
    }
  nuevo->dato = dato;
  nuevo->siguiente = NULL;;
  return nuevo;
}

struct nodoLista *
insertar (int dato)
{
  struct nodoLista *nuevo = crear (dato);
  if (primero == NULL)
    {
      primero = nuevo;
      primero->anterior = NULL;
      ultimo = primero;
    }
  else
    {
      ultimo->siguiente = nuevo;
      nuevo->anterior = ultimo;
      ultimo = nuevo;
    }
}

//Validar si la posición ingresada existe en la lista.
int
validarPos (int pos)
{
  struct nodoLista *auxP = primero;
  while (auxP != NULL)
    {
      auxP = auxP->siguiente;
      pos--;
    }
  if (pos > 0)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

//Eliminar por posición.
void
eliminarPos (int pos)
{
  struct nodoLista *x = primero;
  struct nodoLista *aux = NULL;
  if (validarPos (pos) == 1)
    {
      printf ("No existe la posici%cn.\n", 162);
    }
  else
    {
      if (pos == 1)
	{
	  primero = primero->siguiente;
	  primero->anterior = NULL;
	}
      else
	{
	  for (int i = 1; i < pos; i++)
	    {
	      aux = x;
	      x = x->siguiente;
	    }
	  aux->siguiente = x->siguiente;
	  if (aux->siguiente == NULL)
	    {
	      ultimo = aux;
	    }
	  else
	    {
	      x->siguiente->anterior = aux;
	    }
	}
      free (x);
    }
}

//Validar si el dato ingresado existe en la lista.
int
validarDato (int dato)
{
  struct nodoLista *auxD = primero;
  struct nodoLista *auxA = NULL;
  while (auxD != NULL)
    {
      if (auxD->dato == dato)
	{
	  return 1;
	}
      else
	{
	  auxA = auxD;
	  auxD = auxD->siguiente;
	}
    }
}

//Eliminar por dato. En caso de haber datos repetidos, elimina sólo el primero.
void
eliminarDato (int dato)
{
  struct nodoLista *x = primero;
  struct nodoLista *aux = x;
  int flag = 0;
  if (validarDato (dato) != 1)
    {
      printf ("\nEl dato [ %d ] no existe en la lista.\n", dato);
    }
  else
    {
      while (x != NULL && flag != 1)
	{
	  if (x->dato == dato)
	    {
	      if (x == primero)
		{
		  primero = primero->siguiente;
		  primero->anterior = NULL;
		}
	      else if (x == ultimo)
		{
		  aux->siguiente = NULL;
		  ultimo = aux;
		}
	      else
		{
		  aux->siguiente = x->siguiente;
		  x->siguiente->anterior = aux;
		}
	      flag = 1;
	    }
	  aux = x;
	  x = x->siguiente;
	}
      free (aux);
    }
}

void
mostrar ()
{
  struct nodoLista *aux = primero;
  if (primero != NULL)
    {
      while (aux != NULL)
	{
	  printf ("[ %d ]", aux->dato);
	  aux = aux->siguiente;
	}
    }
  else
    {
      printf ("Lista vacia.");
    }
}

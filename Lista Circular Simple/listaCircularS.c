#include "listaCS.h"

//Pendiente implementar 'primero' y 'último' localmente.
struct nodoCir *primero;
struct nodoCir *ultimo;

struct nodoCir *
crear (int dato)
{
  struct nodoCir *nuevo = NULL;
  nuevo = (struct nodoCir *) malloc (sizeof (struct nodoCir));
  if (nuevo == NULL)
    {
      printf ("No se ha podido reservar el espacio.\n");
    }
  nuevo->dato = dato;
  nuevo->siguiente = NULL;
  return nuevo;
}

void
insertar (int dato)
{
  struct nodoCir *nuevo = crear (dato);
  if (primero == NULL)
    {
      primero = nuevo;
      primero->siguiente = primero;
      ultimo = primero;
    }
  else
    {
      ultimo->siguiente = nuevo;
      nuevo->siguiente = primero;
      ultimo = nuevo;
    }
}

//Valida si la posición ingresada existe en la lista.
int
validarPos (int pos)
{
  struct nodoCir *auxP = primero;
  do
    {
      auxP = auxP->siguiente;
      pos--;
    }
  while (auxP != primero);
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
  struct nodoCir *x = primero;
  struct nodoCir *aux = NULL;
  if (validarPos (pos) == 1)
    {
      printf ("\nLa posici%cn [%d] no existe.\n", 162, pos);
    }
  else
    {
      if (pos == 1)
	{
	  primero = primero->siguiente;
	  ultimo->siguiente = primero;
	}
      else
	{
	  for (int i = 1; i < pos; i++)
	    {
	      aux = x;
	      x = x->siguiente;
	    }
	  aux->siguiente = x->siguiente;
	  if (aux->siguiente == primero)
	    {
	      ultimo = aux;
	    }
	}
      free (x);
    }
}

//Validar si el dato ingresado existe en la lista.
int
validarDato (int dato)
{
  struct nodoCir *auxD = primero;
  struct nodoCir *auxA = NULL;
  do
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
  while (auxD != primero);
}

//Eliminar por dato. En caso de haber datos repetidos, elimina sólo el primero.
void
eliminarDato (int dato)
{
  struct nodoCir *x = primero;
  struct nodoCir *aux = x;
  int flag = 0;
  if (validarDato (dato) != 1)
    {
      printf ("\nEl dato [ %d ] no existe en la lista.\n", dato);
    }
  else
    {
      do
	{
	  if (x->dato == dato)
	    {
	      if (x == primero)
		{
		  primero = primero->siguiente;
		  ultimo->siguiente = primero;
		}
	      if (x == ultimo)
		{
		  aux->siguiente = primero;
		  ultimo = aux;
		}
	      else
		{
		  aux->siguiente = x->siguiente;
		}
	      flag = 1;
	    }
	  aux = x;
	  x = x->siguiente;
	}
      while (x != primero && flag != 1);
      free (aux);
    }
}

void
mostrar ()
{
  struct nodoCir *aux = NULL;
  aux = primero;
  if (primero == NULL)
    {
      printf ("La lista está vacía.");
    }
  else
    {
      do
	{
	  printf ("[ %d ]", aux->dato);
	  aux = aux->siguiente;
	}
      while (aux != primero);
    }
}

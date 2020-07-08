#include "BST.h"

struct nodoArbol *
crear (int dato)
{
  struct nodoArbol *nuevo = NULL;
  nuevo = (struct nodoArbol *) malloc (sizeof (struct nodoArbol));
  if (nuevo == NULL)
    {
      printf ("No se ha podido crear.");
    }
  nuevo->dato = dato;
  nuevo->izquierda = NULL;
  nuevo->derecha = NULL;

  return nuevo;
}

struct nodoArbol *
insertar (struct nodoArbol *raiz, int dato)
{
  if (raiz == NULL)
    {
      return crear (dato);
    }
  if (dato < raiz->dato)
    {
      raiz->izquierda = insertar (raiz->izquierda, dato);
    }
  else if (dato > raiz->dato)
    {
      raiz->derecha = insertar (raiz->derecha, dato);
    }
  return raiz;
}

void
inorden (struct nodoArbol *raiz)
{
  if (raiz == NULL)
    {
      return;
    }
  inorden (raiz->izquierda);
  printf ("[%d] ", raiz->dato);
  inorden (raiz->derecha);
}

void
preorden (struct nodoArbol *raiz)
{
  if (raiz == NULL)
    {
      return;
    }
  printf ("[%d] ", raiz->dato);
  preorden (raiz->izquierda);
  preorden (raiz->derecha);
}

void
postorden (struct nodoArbol *raiz)
{
  if (raiz == NULL)
    {
      return;
    }
  postorden (raiz->izquierda);
  postorden (raiz->derecha);
  printf ("[%d] ", raiz->dato);
}

void
buscar (struct nodoArbol *raiz, int dato)
{
  int flag = 0;
  while (raiz != NULL)
    {
      if (dato == raiz->dato)
	{
	  flag = 1;
	}
      if (dato < raiz->dato)
	{
	  raiz = raiz->izquierda;
	}
      else
	{
	  raiz = raiz->derecha;
	}
    }
  if (flag == 1)
    {
      printf ("Dato [%d] encontronado.\n", dato);
    }
  else
    {
      printf ("Dato [%d] no encontrado.\n", dato);
    }
}

struct nodoArbol *
eliminar (struct nodoArbol *raiz, int dato)
{
  struct nodoArbol *nodoValorBajo = NULL;
  struct nodoArbol *padreValorBajo = NULL;
  struct nodoArbol *nodoEliminar = NULL;
  struct nodoArbol *padreNodoEliminar = NULL;
  nodoEliminar = raiz;

  while (nodoEliminar->dato != dato)
    {
      padreNodoEliminar = nodoEliminar;
      if (nodoEliminar->dato > dato)
	{
	  nodoEliminar = nodoEliminar->izquierda;
	}
      else
	{
	  nodoEliminar = nodoEliminar->derecha;
	}
      if (nodoEliminar == NULL)
	{
	  break;
	}
    }

  if (nodoEliminar == NULL)
    {
      return raiz;
    }

  //Proceso en caso de que el nodo a eliminar sea una hoja.
  if (nodoEliminar->derecha == NULL && nodoEliminar->izquierda == NULL)
    {
      if (padreNodoEliminar->dato > nodoEliminar->dato)
	{
	  padreNodoEliminar->izquierda = NULL;
	}
      else
	{
	  padreNodoEliminar->derecha = NULL;
	}
      free (nodoEliminar);
      printf ("El dato [%d] fue eliminado.\n", dato);
      return raiz;
    }

  //Proceso en caso de que el nodo a eliminar tenga un hijo.
  if (nodoEliminar->izquierda == NULL)
    {
      if (padreNodoEliminar->izquierda == nodoEliminar)
	{
	  padreNodoEliminar->izquierda = nodoEliminar->derecha;
	}
      else
	{
	  padreNodoEliminar->derecha = nodoEliminar->derecha;
	}
    }

  if (nodoEliminar->derecha == NULL)
    {
      if (padreNodoEliminar->izquierda == nodoEliminar)
	{
	  padreNodoEliminar->izquierda = nodoEliminar->izquierda;
	}
      else
	{
	  padreNodoEliminar->derecha = nodoEliminar->izquierda;
	}
      free (nodoEliminar);
      printf ("El dato [%d] fue eliminado.\n", dato);
      return raiz;
    }

  //Proceso en caso de que el nodo a eliminar tenga ambos hijos.
  nodoValorBajo = nodoEliminar->derecha;
  padreValorBajo = nodoEliminar;
  while (nodoValorBajo->izquierda != NULL)
    {
      padreValorBajo = nodoValorBajo;
      nodoValorBajo = nodoValorBajo->izquierda;
    }
  nodoEliminar->dato = nodoValorBajo->dato;
  if (padreValorBajo->derecha == nodoValorBajo)
    {
      padreValorBajo->derecha = nodoValorBajo->derecha;
    }
  else
    {
      padreValorBajo->izquierda = nodoValorBajo->derecha;
    }
  free (nodoValorBajo);
  printf ("El dato [%d] fue eliminado.\n", dato);
  return raiz;
}

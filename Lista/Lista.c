#include "lista.h"

struct Lista *
crear (int dato)
{
  struct Lista *nueva = NULL;

  nueva = (struct Lista *) malloc (sizeof (struct Lista));
  if (nueva == NULL)
    {
      return NULL;
    }
  nueva->dato = dato;
  nueva->siguiente = NULL;
  return nueva;
}

struct Lista *
insertar (struct Lista *lista, int dato)
{
  struct Lista *nueva = crear (dato);
  nueva->siguiente = lista;
  return nueva;
}

void
mostrar (struct Lista *lista)
{
  while (lista != NULL)
    {
      printf ("[ %d ]", lista->dato);
      lista = lista->siguiente;
    }
  printf ("\n");
}

struct Lista *
eliminar (struct Lista *lista, int pos)
{
  struct Lista *x = lista;
  struct Lista *aux;
  for (int i = 1; i < pos; i++)
    {
      aux = x;
      x = x->siguiente;
    }
  aux->siguiente = x->siguiente;
  free (x);
  return x;
}

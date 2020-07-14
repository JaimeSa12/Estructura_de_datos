#include "AVL.h"

struct nodoAVL *
crear (int dato)
{
  struct nodoAVL *nuevo = NULL;
  nuevo = (struct nodoAVL *) malloc (sizeof (struct nodoAVL));
  if (nuevo == NULL)
    {
      return NULL;
    }
  nuevo->dato = dato;
  nuevo->izquierdo = NULL;
  nuevo->derecho = NULL;
  nuevo->balance = 0;
  return nuevo;
}

struct nodoAVL *
rotacion_derecha (struct nodoAVL *raiz)
{
  struct nodoAVL *aux = raiz;
  struct nodoAVL *aux2 = NULL;
  raiz = raiz->izquierdo;
  if (raiz->derecho != NULL)
    {
      aux2 = raiz->derecho;
    }
  raiz->derecho = aux;
  raiz->derecho->izquierdo = aux2;
  return raiz;
}

struct nodoAVL *
rotacion_izquierda (struct nodoAVL *raiz)
{
  struct nodoAVL *aux = raiz;
  struct nodoAVL *aux2 = NULL;
  raiz = raiz->derecho;
  if (raiz->izquierdo != NULL)
    {
      aux2 = raiz->izquierdo;
    }
  raiz->izquierdo = aux;
  raiz->izquierdo->derecho = aux2;
  return raiz;
}

int
calcularAltura (struct nodoAVL *raiz)
{
  int alturaIzq = 0;
  int alturaDer = 0;
  int maximo = 0;
  if (raiz == NULL)
    {
      return 0;
    }
  alturaIzq = calcularAltura (raiz->izquierdo);
  alturaDer = calcularAltura (raiz->derecho);
  if (alturaIzq > alturaDer)
    {
      maximo = alturaIzq;
    }
  else
    {
      maximo = alturaDer;
    }
  return maximo + 1;
}

struct nodoAVL *
insertar (struct nodoAVL *raiz, int dato)
{
  int altura_izq = 0;
  int altura_der = 0;
  if (raiz == NULL)
    {
      return crear (dato);
    }
  if (dato < raiz->dato)
    {
      raiz->izquierdo = insertar (raiz->izquierdo, dato);
    }
  else
    {
      raiz->derecho = insertar (raiz->derecho, dato);
    }
  altura_izq = calcularAltura (raiz->izquierdo);
  altura_der = calcularAltura (raiz->derecho);
  raiz->balance = altura_izq - altura_der;
  if (raiz->balance > 1 && raiz->izquierdo->dato > dato)
    {
      return rotacion_derecha (raiz);
    }
  if (raiz->balance < -1 && raiz->derecho->dato < dato)
    {
      return rotacion_izquierda (raiz);
    }
  if (raiz->balance > 1 && raiz->izquierdo->dato < dato)
    {
      raiz->izquierdo = rotacion_izquierda (raiz->izquierdo);
      return rotacion_derecha (raiz);
    }
  if (raiz->balance < -1 && raiz->derecho->dato > dato)
    {
      raiz->derecho = rotacion_derecha (raiz->derecho);
      return rotacion_derecha (raiz);
    }
  return raiz;
}

void
inorden (struct nodoAVL *raiz)
{
  if (raiz == NULL)
    {
      return;
    }
  inorden (raiz->izquierdo);
  printf ("[%d] ", raiz->dato);
  inorden (raiz->derecho);
}

void
preorden (struct nodoAVL *raiz)
{
  if (raiz == NULL)
    {
      return;
    }
  printf ("[%d] ", raiz->dato);
  preorden (raiz->izquierdo);
  preorden (raiz->derecho);
}

void
postorden (struct nodoAVL *raiz)
{
  if (raiz == NULL)
    {
      return;
    }
  postorden (raiz->izquierdo);
  postorden (raiz->derecho);
  printf ("[%d] ", raiz->dato);
}

void
buscar (struct nodoAVL *raiz, int dato)
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
	raiz = raiz->izquierdo;
	}
      else
	{
	  raiz = raiz->derecho;
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

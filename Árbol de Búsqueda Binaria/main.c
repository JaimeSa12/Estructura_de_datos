#include "BST.h"

int
main (void)
{
  struct nodoArbol *raiz = NULL;
  raiz = insertar (raiz, 45);
  raiz = insertar (raiz, 23);
  raiz = insertar (raiz, 65);
  raiz = insertar (raiz, 2);
  raiz = insertar (raiz, 38);
  raiz = insertar (raiz, 52);
  raiz = insertar (raiz, 96);
  raiz = insertar (raiz, 7);
  raiz = insertar (raiz, 48);

  printf ("Preorden:	");
  preorden (raiz);
  printf ("\nInorden:	");
  inorden (raiz);
  printf ("\nPostorden:	");
  postorden (raiz);
  printf ("\n");

  buscar (raiz, 38);

  raiz = eliminar (raiz, 38);
  buscar (raiz, 38);
  return 0;
}

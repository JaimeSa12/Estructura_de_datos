#include "AVL.h"
	
int
main ()
{
  struct nodoAVL *raiz = NULL;
  raiz = insertar (raiz, 1);
  raiz = insertar (raiz, 2);
  raiz = insertar (raiz, 3);
  raiz = insertar (raiz, 4);
  raiz = insertar (raiz, 5);
  raiz = insertar (raiz, 6);
  raiz = insertar (raiz, 7);
  
  printf ("Preorden:	");
  preorden (raiz);
  printf ("\nInorden:	");
  inorden (raiz);
  printf ("\nPostorden:	");
  postorden (raiz);
  printf ("\n");
  
  buscar (raiz, 7);
  buscar (raiz, 20);

  return 0;
}

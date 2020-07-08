#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

struct nodoArbol
{
  int dato;
  struct nodoArbol *izquierda;
  struct nodoArbol *derecha;
};

struct nodoArbol *crear (int);
struct nodoArbol *insertar (struct nodoArbol *, int);
struct nodoArbol *eliminar (struct nodoArbol *, int);
void inorden (struct nodoArbol *);
void preorden (struct nodoArbol *);
void postorden (struct nodoArbol *);
void buscar (struct nodoArbol *, int);

#endif

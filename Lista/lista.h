#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct Lista
{
  int dato;
  struct Lista *siguiente;
};

struct Lista *crear (int);
struct Lista *insertar (struct Lista *, int);
void mostrar (struct Lista *);
struct Lista *eliminar (struct Lista *, int);

#endif

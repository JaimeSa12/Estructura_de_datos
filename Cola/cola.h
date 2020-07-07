#ifndef COLA_H
#define COLA_H

#include <stdio.h>
#include <stdlib.h>

struct nodoCola
{
  int dato;
  struct nodoCola *siguiente;
};

struct nodoCola *crear (int);
struct nodoCola *enqueue (struct nodoCola *, int);
void dequeue (struct nodoCola *);
void mostrar ();
void eliminaImprime (struct nodoCola *);

#endif

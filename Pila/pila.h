#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <stdlib.h>
struct nodoPila
{
  int dato;
  struct nodoPila *siguiente;
};

struct nodoPila *crear (int);
struct nodoPila *mostrar (struct nodoPila *);
struct nodoPila *push (struct nodoPila *, int);
struct nodoPila *pop (struct nodoPila *);

#endif

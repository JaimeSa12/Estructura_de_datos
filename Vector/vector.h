#ifndef VEC_H
#define VEC_H

#include <stdlib.h>
#include <stdio.h>

struct Vector
{
  int capacidad;
  int cuantos_hay;
  int *datos;
};

int iniciar (struct Vector *);
int agrandar (struct Vector *);
void mostrar (struct Vector *);
int hay_espacio (struct Vector *);
int agregar (struct Vector *, int);

#endif

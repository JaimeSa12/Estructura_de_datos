#ifndef LISTACS_H
#define LISTACS_H

#include <stdio.h>
#include <stdlib.h>

struct nodoCir
{
  int dato;
  struct nodoCir *siguiente;
};

struct nodoCir *crear (int);
void insertar (int);
int validarPos (int);
void eliminarPos (int);
int validarDato (int);
void eliminarDato (int);
void mostrar ();

#endif

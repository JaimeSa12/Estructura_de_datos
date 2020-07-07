#ifndef COLAC_H
#define COLAC_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

struct colaC
{
  int dato[MAX];
  int inicio;
  int final;
};

int cuantosHay (struct colaC *);
int colaVacia (struct colaC *);
int colaLlena (struct colaC *);
void insertar (struct colaC *, int);
void eliminar (struct colaC *);
void mostrar (struct colaC *);

#endif

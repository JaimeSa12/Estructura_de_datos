#ifndef LISTACD_H
#define LISTACD_H

#include <stdio.h>
#include <stdlib.h>

struct nodoCD
{
  int dato;
  struct nodoCD *siguiente;
  struct nodoCD *anterior;
};

struct nodoCD *crear (int);
void insertar (int);
int validarPos (int);
void eliminarPos (int);
int validarDato (int);
void eliminarDato (int);
void mostrar ();

#endif

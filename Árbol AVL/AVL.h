#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

struct nodoAVL
{
  int dato;
  int balance;
  struct nodoAVL *izquierdo;
  struct nodoAVL *derecho;
};

struct nodoAVL * crear (int);
struct nodoAVL * rotacion_derecha (struct nodoAVL *);
struct nodoAVL * rotacion_izquierda (struct nodoAVL *);
int calcularAltura (struct nodoAVL *);
struct nodoAVL *insertar (struct nodoAVL *, int);
void inorden (struct nodoAVL *);
void preorden (struct nodoAVL *);
void postorden (struct nodoAVL *);
void buscar (struct nodoAVL *, int);

#endif

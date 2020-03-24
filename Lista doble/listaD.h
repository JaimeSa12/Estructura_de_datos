#ifndef LISTAD_H
#define LISTAD_H

#include <stdio.h>
#include <stdlib.h>

struct nodoLista{
	int dato;
	struct nodoLista *anterior;
	struct nodoLista *siguiente;
};

struct nodoLista * crear(int);
struct nodoLista * insertar(int);
int validarPos(int);
void eliminarPos(int);
int validarDato(int);
void eliminarDato(int);
void mostrar();

#endif

#ifndef COLAP_H
#define COLAP_H

#include <stdio.h>
#include <stdlib.h>

struct nodoColaP{
	int dato;
	int prioridad;
	struct nodoColaP *siguiente;
};

struct nodoColaP * crear(int, int);
void enqueue(int dato, int prioridad);
void dequeue();
void mostrar();

#endif

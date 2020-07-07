#include "colaC.h"

//Retorna la cantidad de elementos existentes en la cola.
int
cuantosHay (struct colaC *cola)
{
  int cantidad = 0;
  if (cola->final == -1)
    {
      cantidad = 0;
    }
  else
    {
      if (cola->inicio <= cola->final)
	{
	  cantidad = cola->final - cola->inicio + 1;
	}
      else
	{
	  cantidad = MAX - cola->inicio + cola->final + 1;
	}
    }
  return cantidad;
}

//Valida si la cola está vacía.
int
colaVacia (struct colaC *cola)
{
  if (cola->final == -1)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

//Valida si la cola está llena.
int
colaLlena (struct colaC *cola)
{
  if (cuantosHay (cola) == MAX)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

void
insertar (struct colaC *cola, int dato)
{
  if (colaLlena (cola) == 0)
    {
      if (colaVacia (cola) == 1)
	{
	  cola->inicio = 0;
	}
      if (cola->final == MAX - 1)
	{
	  cola->final = 0;
	}
      else
	{
	  cola->final++;
	}
      cola->dato[cola->final] = dato;
      printf ("Dato [%d] insertado.\n", dato);
    }
  else
    {
      printf ("Cola llena. No se ha podido agregar el dato [%d]\n", dato);
    }
}

//Elimina en forma FIFO.
void
eliminar (struct colaC *cola)
{
  if (colaVacia (cola) == 0)
    {
      if (cuantosHay (cola) == 1)
	{
	  cola->inicio = -1;
	  cola->final = -1;
	}
      else
	{
	  cola->inicio++;
	}
    }
  printf ("Dato [%d] eliminado.\n", cola->dato[cola->inicio - 1]);
}

void
mostrar (struct colaC *cola)
{
  if (colaVacia (cola) == 1)
    {
      printf ("Cola vacia.\n");
    }
  else
    {
      for (int i = 0; i < cuantosHay (cola); i++)
	{
	  printf ("[%d] ", cola->dato[i]);
	}
    }
  printf ("\nEl dato inicial es [%d]", cola->dato[cola->inicio]);
  printf ("\nEl dato final es [%d]", cola->dato[cola->final]);
}

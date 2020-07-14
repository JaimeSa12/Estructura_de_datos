#include "vector.h"

int
iniciar (struct Vector *vector)
{
  if (vector == NULL)
    {
      return -1;
    }
  vector->datos = (int *) malloc (sizeof (int));
  if (vector->datos == NULL)
    {
      return -1;
    }
  vector->cuantos_hay = 0;
  vector->capacidad = 0;
}

int
agrandar (struct Vector *vector)
{
  int *otro = NULL;

  if (vector == NULL)
    {
      return -1;
    }
  otro = (int *) malloc (sizeof (int) * 2 * vector->capacidad);
  if (otro == NULL)
    {
      return -2;
    }

  for (int i = 0; i < vector->cuantos_hay; i++)
    {
      *(otro + i) = *(vector->datos + i);
    }
  free (vector->datos);
  vector->capacidad = vector->capacidad * 2;
  vector->datos = otro;
  return 0;
}

void
mostrar (struct Vector *vector)
{
  if (vector == NULL)
    {
      return;
    }
  for (int i = 0; i < vector->cuantos_hay; i++)
    {
      printf ("%d", *(vector->datos + i));
    }
  printf ("\n");
}

int
hay_espacio (struct Vector *vector)
{
  if (vector == NULL)
    {
      return 1;
    }

  if (vector->cuantos_hay < vector->capacidad)
    {
      return 0;
    }
  return 1;
}

int
agregar (struct Vector *vector, int dato)
{
  if (vector = NULL)
    {
      return -1;
    }
  if (!hay_espacio (vector))
    {
      if (agrandar (vector) != 0)
	{
	  return -2;
	}
    }
  *(vector->datos + vector->cuantos_hay) = dato;
  vector->cuantos_hay = vector->cuantos_hay + 1;
}

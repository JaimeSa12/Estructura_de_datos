#include "colaC.h"

int main(){
	struct colaC cola;
	//Se inicializa 'inicio' y 'final' con valores distintos de 0.
	cola.inicio=-1;
	cola.final=-1;
	
	insertar(&cola, 1);
	insertar(&cola, 2);
	insertar(&cola, 3);
	insertar(&cola, 25);
	eliminar(&cola);
	eliminar(&cola);
	insertar(&cola, 5);
	insertar(&cola, 4);
	
	printf("Cola final: \n");
	mostrar(&cola);
	printf("\n");
	
	return 0;
}

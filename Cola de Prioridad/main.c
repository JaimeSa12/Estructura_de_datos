#include "colaP.h"

int main(){
	enqueue(5,1);
	enqueue(7,12);
	enqueue(33,12);
	enqueue(3,6);
	enqueue(9,2);
	enqueue(11,2);
	enqueue(10,1);
	enqueue(53,1);
	enqueue(18,2);
	enqueue(55,1);
	enqueue(8,12);
	
	printf("Notacion: [DATO|PRIORIDAD]:\n");
	mostrar();
	
	dequeue();
	dequeue();
	dequeue();
	printf("\n\nCola final tras eliminar elementos:\n");
	mostrar();
	printf("\n");
	return 0;
}

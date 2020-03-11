#include "pila.h"

int main(){
	struct nodoPila *cima=NULL;
	struct nodoPila *cimaSec=NULL;
	int pos;
	
	cima=push(cima, 1);
	cima=push(cima, 2);
	cima=push(cima, 3);
	cima=push(cima, 4);
	cima=push(cima, 5);
	cima=push(cima, 6);
	
	mostrar(cima);
	
	printf("Ingresa un posicion a eliminar: ");
	scanf("%d", &pos);
	
	cima=pop(cima, cimaSec, pos);
	
	mostrar(cima);
	return 0;
}

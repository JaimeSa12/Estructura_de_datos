#include "pila.h"

struct nodoPila * crear(int dato){
	struct nodoPila *nuevo=NULL;
	
	nuevo=(struct nodoPila *)malloc(sizeof(struct nodoPila));
	if(nuevo==NULL){
		return NULL;
	}
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	return nuevo;
}

struct nodoPila * push(struct nodoPila *cima, int dato){
	struct nodoPila *nuevo=crear(dato);
	nuevo->siguiente=cima;
	return nuevo;
}

//Elimina posición utilizando una pila secundaria.
struct nodoPila * pop(struct nodoPila *cima, struct nodoPila *cimaSec, int pos){
	struct nodoPila *aux=cima;
	if(pos!=1){
		//Hace pop en la pila original y push en la pila secundaria.
		for(int i=1; i<pos; i++){
			cimaSec=push(cimaSec,aux->dato);
			aux=cima->siguiente;
			free(cima);
			cima=aux;		
		}
		cima=aux->siguiente;
		free(aux);
		
		//Se regresan los datos a la pila principal.
		aux=cimaSec;
		for(int i=1; i<pos; i++){
			cima=push(cima,aux->dato);
			aux=cimaSec->siguiente;
			free(cimaSec);
			cimaSec=aux;		
		}
		
		free(aux);
	}
	else{
		aux=cima->siguiente;
		free(cima);
		cima=aux;
	}
	return cima;
}

//Imprime la pila en forma LIFO.
struct nodoPila * mostrar(struct nodoPila *cima){
	while(cima!=NULL){
		printf("[ %d ]\n", cima->dato);
		cima=cima->siguiente;
	}
}

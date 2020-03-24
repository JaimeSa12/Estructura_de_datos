#include "listaCD.h"

//Pendiente implementar 'primero' y 'ultimo' localmente.
struct nodoCD *primero=NULL;
struct nodoCD *ultimo=NULL;

struct nodoCD *crear(int dato){
	struct nodoCD *nuevo=NULL;
	nuevo=(struct nodoCD *)malloc(sizeof(struct nodoCD));
	if(nuevo==NULL){
		printf("No se ha podido reservar el espacio.\n");
	}
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	return nuevo;
}

void insertar(int dato){
	struct nodoCD *nuevo=crear(dato);
	if(primero==NULL){
		primero=nuevo;
		primero->siguiente=primero;
		ultimo=nuevo;
		primero->anterior=ultimo;
	}
	else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=primero;
		nuevo->anterior=ultimo;
		ultimo=nuevo;
		primero->anterior=ultimo;
	}
}

//Validar si la posición ingresada existe en la lista.
int validarPos(int pos){
	struct nodoCD *auxP=primero;
	do{
		auxP=auxP->siguiente;
		pos--;
	}
	while(auxP!=primero);
	if(pos>0){
		return 1;
	}
	else{
		return 0;
	}
}

//Eliminar por posición.
void eliminarPos(int pos){
	struct nodoCD *x=primero;
	struct nodoCD *aux=NULL;
	
	if(validarPos(pos)==1){
		printf("No existe la posici%cn.\n", 162);
	}
	else{
		if(pos==1){
			primero=primero->siguiente;
			primero->anterior=ultimo;
			ultimo->siguiente=primero;
		}
		else{
			for(int i=1; i<pos; i++){
				aux=x;
				x=x->siguiente;
			}
			aux->siguiente=x->siguiente;
			if(aux->siguiente==primero){
				ultimo=aux;
				ultimo->siguiente=primero;
				primero->anterior=ultimo;
			}
			else{
				x->siguiente->anterior=aux;
			}
		}
		free(x);
	}
}

//Validar si el dato ingresado existe en la lista.
int validarDato(int dato){
	struct nodoCD *auxD=primero;
	struct nodoCD *auxA=NULL;
	do{
		if(auxD->dato==dato){
			return 1;
		}
		else{
			auxA=auxD;
			auxD=auxD->siguiente;
		}
	}
	while(auxD!=primero);
}

//Eliminar por dato. En caso de haber datos repetidos, elimina sólo el primero.
void eliminarDato(int dato){
	struct nodoCD *x=primero;
	struct nodoCD *aux=x;
	int flag=0;
	
	if(validarDato(dato)!=1){
		printf("\nEl dato [ %d ] no existe en la lista.\n", dato);
	}
	else{
		do{
			if(x->dato==dato){
				if(x==primero){
					primero=primero->siguiente;
					primero->anterior=ultimo;
					ultimo->siguiente=primero;
				}
				else if(x==ultimo){
					ultimo=aux;
					ultimo->siguiente=primero;
					primero->anterior=ultimo;
				}
				else{
					aux->siguiente=x->siguiente;
					x->siguiente->anterior=aux;	
				}
				flag=1;
			}
			aux=x;
			x=x->siguiente;	
		}
		while(x!=primero && flag!=1);
		free(aux);
	} 
}

void mostrar(){
	struct nodoCD *aux=primero;
	if(primero!=NULL){
		do{
			printf("[ %d ]", aux->dato);
			aux=aux->siguiente;
		}
		while(aux!=primero);
	}
	else{
		printf("La lista est%c vac%ca.", 160, 161);
	}
}

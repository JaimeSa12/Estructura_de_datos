#include <stdio.h>
#include <stdlib.h>

struct nodoCola{
	int dato;
	struct nodoCola *siguiente;
};

//Pendiente implenetar 'frente' y 'atras' localmente.
struct nodoCola *frente=NULL;
struct nodoCola *atras=NULL;

//Función crear nodo.
struct nodoCola * crear(int dato){
	struct nodoCola *nuevo=NULL;
	
	nuevo=(struct nodoCola *)malloc(sizeof(struct nodoCola));
	if(nuevo==NULL){
		printf("No se ha podido crear.\n\n");
	}
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	return nuevo;
}

//Función insertar elementos a la cola.
struct nodoCola * enqueue(int dato){
	struct nodoCola *nuevo=crear(dato);
	if(frente==NULL){
		frente=nuevo;
	}
	else{
		atras->siguiente=nuevo;
	}
	return nuevo;
}

//Función imprimir/mostrar.
void mostrar(){
	struct nodoCola *aux=frente;
	if(aux==NULL){
		printf("Cola vacia.\n");
	}
	while(aux!=NULL){
		printf("[ %d ] ", aux->dato);
		aux=aux->siguiente;
	}
}

//Función eliminar elementos de una cola.
void dequeue(){
	struct nodoCola *aux=frente;
	if(frente==atras){
		frente=NULL;
		atras=NULL;
	}
	else{
		aux=frente->siguiente;
		free(frente);
		frente=aux;
	}
}

int main(){
	//Inserta elementos.
	atras=enqueue(1);
	atras=enqueue(2);
	atras=enqueue(3);
	atras=enqueue(23);
	
	//Muestra cola ingresada.
	mostrar();
	printf("\nEl valor de enfrente es [ %d ] y el de atras es [ %d ]\n\n", frente->dato, atras->dato);
	
	//Elimina e imprime la cola por cada elemento eliminado.
	while(frente!=NULL){
		dequeue();
		mostrar();
		printf("\n");
	}
	return 0;
}

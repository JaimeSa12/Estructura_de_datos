#include <stdio.h>
#include <stdlib.h>

struct Lista{
	int dato;
	struct Lista *siguiente;
};

struct Lista * crear(int dato){
	struct Lista *nueva=NULL;

	nueva=(struct Lista *)malloc(sizeof(struct Lista));
	if(nueva==NULL){
		return NULL;
	}
	nueva->dato=dato;
	nueva->siguiente=NULL;
	return nueva;
}

struct Lista * insertar(struct Lista *lista, int dato){
	struct Lista *nueva = crear(dato);
	nueva->siguiente=lista;
	return nueva;
}

void mostrar(struct Lista *lista){
	while(lista!=NULL){
		printf("%d, ", lista->dato);
		lista=lista->siguiente;
	}
	printf("\n");
}

struct Lista * eliminar(struct Lista *lista, int pos){
	struct Lista *x=lista;
	struct Lista *aux;
	for(int i=1; i<pos; i++){
		aux=x;
		x=x->siguiente;
	}
	aux->siguiente=x->siguiente;
	free(x);
	return x;
}

//Pendiente: invertir.
/*struct Lista * invertir(struct Lista *lista){
	struct Lista *x=lista;
	struct Lista *aux=NULL;
	struct Lista *aux2=NULL;

    while (x!=NULL) {
        aux2 = x->siguiente;
        x->siguiente = aux;
        aux = x;
        x = aux2;
    }
    return aux;
}*/

int main(void){
	int n;
	int data;
	int pos;
	
	struct Lista *miLista=NULL;
	//Ingresa datos a la lista.
	printf("Cuantos numeros vas a ingresar? ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("Ingresa el numero %d de %d: ", i+1, n);
		scanf("%d", &data);
		miLista=insertar(miLista, data);
		
		if(miLista==NULL){
			printf("No se pudo crea la lista. [Falta de memoria].\n");
			return -1;
		}	
	}
	
	//Muestra lista original.
	mostrar(miLista);
	
	//Eliminar
	printf("\n\nIngresa la posicion a eliminar: ");
	scanf("%d", &pos);
	eliminar(miLista, pos);
	
	//Muestra lista con elemento eliminado.
	mostrar(miLista);
	return 0;
}

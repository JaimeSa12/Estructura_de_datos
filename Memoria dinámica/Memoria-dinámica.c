#include <stdio.h>
#include <stdlib.h>

int main(){
	int n=1, m;
	int *din;
	
	din=(int*)malloc(n*sizeof(int));
	if(din==NULL){
		printf("Error. No se ha podido reservar el espacio.\n");
	}
	else{
		printf("Ingresa un n%cmero: ", 163);
		scanf("%d", &m);
		if(m<=0 || m>100000000){
			printf("Fuera de rango.\n");
		}
		else{
			din=(int*)realloc(din,m*sizeof(int));
			if(din==NULL){
				printf("Error. No se ha podido reservar el espacio.\n");
			}
			else{
				for(int i=0; i<m; i++){
					*(din+i)=i+1;
					for(int j=0; j<=i; j++){
						printf("%d ", *(din+j));
					}
					printf("\n");
				}
			}
		}
	}
}

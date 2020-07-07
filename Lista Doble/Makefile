run: a.out
	./a.out 

a.out: main.o listaDoble.o 
	gcc main.o listaDoble.o 
	
listaDoble.o: listaDoble.c 
	gcc listaDoble.c -c 
	
main.o: main.c 
	gcc main.c -c 

clean:
	rm -f a.out *.o

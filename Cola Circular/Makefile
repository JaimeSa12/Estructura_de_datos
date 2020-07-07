run: a.out
	./a.out

a.out: main.o colaCircular.o 
	gcc main.o colaCircular.o 
	
colaCircular.o: colaCircular.c 
	gcc colaCircular.c -c 
	
main.o: main.c 
	gcc main.c -c 

clean: 
	rm -f a.out *.o

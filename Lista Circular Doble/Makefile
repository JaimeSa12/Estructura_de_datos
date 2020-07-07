run: a.out 
	./a.out

a.out: main.o listaCircularD.o 
	gcc main.o listaCircularD.o 

listaCircularD.o: listaCircularD.c 
	gcc listaCircularD.c -c 
	
main.o: main.c 
	gcc main.c -c 
	
clean:
	rm -f a.out *.o

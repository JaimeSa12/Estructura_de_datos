a.out: main.o Pila.o
	gcc main.o Pila.o

Pila.o: Pila.c
	gcc Pila.c -c

main.o: main.c
	gcc main.c -c

run: a.out
	./a.out

clean:
	rm -f a.out  *.o

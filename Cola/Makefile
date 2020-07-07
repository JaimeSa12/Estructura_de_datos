run: a.out
	./a.out

a.out: main.o cola.o
	gcc main.o cola.o

cola.o: cola.c
	gcc cola.c -c

main.o: main.c
	gcc main.c -c

clean:
	rm -f a.out *.o

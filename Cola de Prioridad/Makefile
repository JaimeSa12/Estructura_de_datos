a.out: main.o colaPrioridad.o
	gcc main.c colaPrioridad.o

colaPrioridad.o: colaPrioridad.c
	gcc colaPrioridad.c -c

main.o: main.c
	gcc main.c -c

run: a.out
	./a.out

clean:
	rm -f a.out *.o

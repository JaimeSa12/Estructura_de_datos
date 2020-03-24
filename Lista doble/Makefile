a.out: main.o listaDoble.o
	gcc main.o listaDoble.o

listaDoble.o: listaDoble.c
	gcc listaDoble.c -c

main.o: main.c
	gcc main.c -c

run: a.out
	./a.out

clean:
	rm -f programa a.out  main.o listaDoble.o

a.out: main.o listaCircularS.o
	gcc main.o listaCircularS.o

listaCircularS.o: listaCircularS.c
	gcc listaCircularS.c -c

main.o: main.c
	gcc main.c -c

run: a.out
	./a.out

clean:
	rm -f a.out  *.o

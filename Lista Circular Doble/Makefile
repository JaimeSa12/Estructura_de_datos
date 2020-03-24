a.out: main.o listaCircularD.o
	gcc main.o listaCircularD.o

listaCircularD.o: listaCircularD.c
	gcc listaCircularD.c -c

main.o: main.c
	gcc main.c -c

run: a.out
	./a.out

clean:
	rm -f a.out  *.o

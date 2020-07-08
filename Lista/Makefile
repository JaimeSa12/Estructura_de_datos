run: a.out
	./a.out

a.out: main.o Lista.o
	gcc main.o Lista.o

Lista.o: Lista.c
	gcc Lista.c -c

main.o: main.c
	gcc main.c -c

clean:
	rm -f a.out *.o

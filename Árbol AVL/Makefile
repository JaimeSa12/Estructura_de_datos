run: a.out
	./a.out

a.out: main.o AVL.o
	gcc main.o AVL.o

AVL.o: AVL.c
	gcc AVL.c -c

main.o: main.c
	gcc main.c -c

clean:
	rm -f a.out *.o

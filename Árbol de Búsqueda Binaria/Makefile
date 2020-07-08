run: a.out
	./a.out

a.out: main.o BST.o
	gcc main.o BST.o

BST.o: BST.c
	gcc BST.c -c

main.o: main.c
	gcc main.c -c

clean:
	rm -f a.out *.o

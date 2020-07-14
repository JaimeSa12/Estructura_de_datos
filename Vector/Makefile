run: a.out
	./a.out

a.out: main.o Vector.o
	gcc main.o Vector.o

Vector.o: Vector.c
	gcc Vector.c -c

main.o: main.c
	gcc main.c -c

clean:
	rm -f a.out *.o

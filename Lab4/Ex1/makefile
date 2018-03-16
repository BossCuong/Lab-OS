app: main.o ex1.o
	gcc -o app main.o ex1.o
main.o: main.c ex1.h
	gcc -o main.o -c main.c
ex1.o: ex1.c ex1.h
	gcc -o ex1.o -c ex1.c
clean:
	rm *.o
	rm app

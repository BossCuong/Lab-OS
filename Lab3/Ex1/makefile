app: file.o main.o
	gcc -o app file.o main.o
file.o: file.c file.h
	gcc -o file.o -c file.c
main.o: main.c
	gcc -o main.o -c main.c
clean:
	rm *.o
	rm app

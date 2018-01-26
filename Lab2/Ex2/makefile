all: app

app: main.o file.o
	gcc -o app main.o file.o
main.o: main.c file.h
	gcc -c main.c
file.o: file.c file.h
	gcc -c file.c
clean:
	rm app
	rm *.o

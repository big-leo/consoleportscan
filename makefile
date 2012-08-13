main: main.o addr_to_int.o
	gcc -Wall -g -o main main.o addr_to_int.o

main.o: main.c main.h lib/addr_to_int.c lib/addr_to_int.h
	gcc -Wall -g -c main.c lib/addr_to_int.c

clean:
	rm *.o main
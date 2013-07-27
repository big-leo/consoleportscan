cpscan: main.o child.o addr_to_int.o
	gcc -Wall -g -pthread -o cpscan main.o child.o addr_to_int.o

main.o: main.c main.h child.c child.h
	gcc -Wall -g -c main.c

child.o: child.c child.h
	gcc -Wall -g -c child.c

addr_to_int.o: lib/addr_to_int.c lib/addr_to_int.h
	gcc -Wall -g -c lib/addr_to_int.c

clean:
	rm *.o cpscan
<<<<<<< HEAD
cpscan: main.o addr_to_int.o
	gcc -Wall -g -o cpscan main.o addr_to_int.o
=======
main: main.o addr_to_int.o
	gcc -Wall -g -o main main.o addr_to_int.o
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020

main.o: main.c main.h lib/addr_to_int.c lib/addr_to_int.h
	gcc -Wall -g -c main.c lib/addr_to_int.c

clean:
<<<<<<< HEAD
	rm *.o cpscan
=======
	rm *.o main
>>>>>>> 381e72ec60236271cf0c7680b6b7dc19fa9c8020

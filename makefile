all: main.o rand.o
	gcc main.o rand.o

main.o: main.c rand.h
	gcc -c main.c rand.h

rand.o: rand.c rand.h
	gcc -c rand.c rand.h

run: all
	./a.out

clean:
	rm *.o
	rm ./test

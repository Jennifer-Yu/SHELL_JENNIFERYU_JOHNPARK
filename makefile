all: shell.o
	gcc -o shelltest shell.o

shell.o: shell.c
	gcc -c shell.c

run: shelltest
	./shelltest

clean:
	rm ./shelltest
	rm *.o
	rm *~
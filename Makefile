CC = gcc -std=c99
CFLAGS= -g -Wall -lm

build:task2

task2:tema1.c
	$(CC) -std=c99 -g -o tema1  tema1.c $(CFLAGS)

.PHONY:clean
clean:
	rm -f tema1
	rm -f *.out
	rm my_diff

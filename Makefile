# build an executable named myprog from myprog.c
all: main.c
	gcc -g -Wall -o shell main.c

clean:
	$(RM) shell

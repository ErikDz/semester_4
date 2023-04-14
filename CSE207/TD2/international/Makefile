LANGUAGE=FRENCH
all: international-hello-world

intenational-hello-world: international-hello-world.o
	cc -g -o international-hello-world international-hello-world.o

international-hello-world.o: international-hello-world.c
	cc -c -Wall -g international-hello-world.c -D$(LANGUAGE)

clean:
	rm international-hello-world.o international-hello-world

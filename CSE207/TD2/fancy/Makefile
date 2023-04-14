all: fancy-hello-world
 
fancy-hello-world: fancy-hello-world.o
	cc -g -o fancy-hello-world fancy-hello-world.o
 
fancy-hello-world.o: fancy-hello-world.c
	cc -c -Wall -g fancy-hello-world.c 
 
clean:
	rm fancy-hello-world.o fancy-hello-world

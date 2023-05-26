all: server fancyclient
fancyclient: fancyclient.o
	cc -g -o fancyclient fancyclient.o
fancyclient.o: fancyclient.c
	cc -c -Wall -g fancyclient.c

server: server.o
	cc -g -o server server.o
server.o: server.c
	cc -c -Wall -g server.c

clean:
	rm fancyclient.o fancyclient
	rm server.o server

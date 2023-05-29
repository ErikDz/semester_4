#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
int main(void){
   char* msg = "Hello World\n";
   struct sockaddr_in serverAddr;
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(5000);
   serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   int sockid = socket(AF_INET, SOCK_STREAM, 0);
   int s = connect(sockid, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
   int r = send(sockid, msg, strlen(msg), 0);
   printf("sent %d bytes out of %lu",r,strlen(msg));
   return 0;
}
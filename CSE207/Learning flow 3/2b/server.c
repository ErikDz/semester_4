// ./server PORT_NUMBER
// UDP echo server
/*
I worked on this program with Milos Oundjian
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    // Cool welcome message
    printf("==============================================\n");
    printf(",.-~*´¨¯¨`*·~-.¸-(UDP SERVER)-,.-~*´¨¯¨`*·~-.¸\n");
    printf("==============================================\n");
    if (argc < 2)
    {
        fprintf(stderr, "Missing argument. Please enter port number.\n");
        return 1;
    }

    int port_number = atoi(argv[1]);

    // Create socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return 2;
    }

    //Define maxbuffer
    int maxbuffer = 1024;

    // Create address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_number);
    addr.sin_addr.s_addr = INADDR_ANY;
    // INADDR_ANY is a constant that allows the server to receive messages from any address

    // Bind socket to address
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        return 3;
    }

    char *msg = malloc(sizeof(char) * maxbuffer);
    while(1)
    {
        // Accept connection from client
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_sock < 0)
        {
            perror("accept");
            continue;
        }

        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void *)&client_sock) != 0)
        {
            perror("pthread_create");
            close(client_sock);
        }
    }

    free(msg);
    // Close socket
    close(sock);

    return 0;
}

void *handle_client(void *arg)
{
    int client_sock = *(int *)arg;
    char msg[1024];

        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);

        // We receive the message checking MSG_TRUNC to make sure that the message was not truncated
        int bytes_received = recvfrom(client_sock, msg, sizeof(msg), MSG_TRUNC, (struct sockaddr *)&client_addr, &client_addr_size);
        if (bytes_received < 0)
        {
            perror("recvfrom");
            return NULL;
        }

        printf("Received message: \"%s\" from %s:%d", msg, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        if (bytes_received >= sizeof(msg))
        {
            printf("Message was truncated.\n");
        }

        // Send back the message to the client and we save the thread id
        // If there was a thread already running, we cancel it
        pthread_t thread;
        if (pthread_create(&thread, NULL, infinite_message, (void *)&client_sock) != 0)
        {
            perror("pthread_create");
            close(client_sock);
        }

        memset(msg, 0, sizeof(msg));

    close(client_sock);
    return NULL;
}

void infinite_message(int client_sock, char msg, int bytes_received,struct sockaddr_in client_addr, socklen_t client_addr_size){
    while (1){
        int bytes_sent = sendto(client_sock, msg, bytes_received, 0, (struct sockaddr *)&client_addr, client_addr_size);
        if (bytes_sent < 0)
        {
            perror("sendto");
        }
        }
}
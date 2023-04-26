// ./server PORT_NUMBER
// UDP echo server

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

int main(int argc, char *argv[])
{
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

    char *msg = malloc(sizeof(char) * 20);
    while (1)
    {
        // Receive message
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int bytes_received = recvfrom(sock, msg, sizeof(msg), 0, (struct sockaddr *)&client_addr, &client_addr_size);
        if (bytes_received < 0)
        {
            perror("recvfrom");
            return 4;
        }

        // Print message
        printf("Received message: \"%s\" from %s:%d\n", msg, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Send back the message to the client
        int bytes_sent = sendto(sock, msg, bytes_received, 0, (struct sockaddr *)&client_addr, client_addr_size);
        if (bytes_sent < 0)
        {
            perror("sendto");
            return 5;
        }
    }

    // Close socket
    close(sock);

    return 0;
}
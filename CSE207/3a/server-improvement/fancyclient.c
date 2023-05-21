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

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Missing argument. Please enter IP address and port number.\n");
        return 1;
    }
    char *ip_address = argv[1];
    // If ip address is localhost, change to 127.0.0.1
    if (strcmp(ip_address, "localhost") == 0)
    {
        ip_address = "127.0.0.1";
    }

    int port_number = atoi(argv[2]);

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
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Send message. Allow for infinite message sending

    char *msg = NULL;
    char *msg_received = malloc(sizeof(char) * 1024);
    size_t size = 0;
    printf("=========================================================\n");
    printf("Welcome to ErikDz's UDP echo client. Type 'exit' to exit.\n");
    printf("=========================================================\n\n");
    while (1)
    {
        printf("Enter message: ");
        // We use getline for dynamic allocation
        getline(&msg, &size, stdin);
        // Remove newline from end of msg
        msg[strlen(msg) - 1] = '\0';

        // If exit in message, break
        if (strstr(msg, "exit") != NULL)
        {
            break;
        }
        sendto(sock, msg, strlen(msg), 0, (struct sockaddr *)&addr, sizeof(addr));

        // Receive message
        struct sockaddr_in server_addr;
        socklen_t server_addr_size = sizeof(server_addr);
        int bytes_received = recvfrom(sock, msg_received, 1024, 0, (struct sockaddr *)&server_addr, &server_addr_size);
        if (bytes_received < 0)
        {
            perror("recvfrom");
            return 4;
        }
        printf("Message received: %s\n\n", msg_received);

        memset(msg_received, 0, strlen(msg_received));
        memset(msg, 0, strlen(msg));


    }
    
    free(msg_received);
    free(msg);

    // Close socket
    close(sock);
    return 0;
}


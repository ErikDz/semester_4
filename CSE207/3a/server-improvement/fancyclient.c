/*
Worked with Milos Oundjian
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

#define MSG_SIZE 1024

struct sending_data
{
    int socket;
    struct sockaddr_in server_addr;
};

void *receiving_thread(void *arg);
void *sending_thread(void *arg);

// I worked on this code with Erik Dziekonski
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./fancyclient IP_ADDRESS PORT_NUMBER\n");
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
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    // Create address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));               // Zero out structure
    addr.sin_family = AF_INET;                    // IPv4
    addr.sin_port = htons(port_number);           // Port number
    addr.sin_addr.s_addr = inet_addr(ip_address); // IP address

    // create the threads
    pthread_t receiving_thread_id;
    pthread_t sending_thread_id;

    // Create the receiving thread
    pthread_create(&receiving_thread_id, NULL, receiving_thread, (void *)&sockfd);

    // Create the sending thread
    struct sending_data *sending_data = malloc(sizeof(struct sending_data));
    sending_data->socket = sockfd;
    sending_data->server_addr = addr;
    pthread_create(&sending_thread_id, NULL, sending_thread, (void *)sending_data);

    // Join the threads
    pthread_join(receiving_thread_id, NULL);
    pthread_join(sending_thread_id, NULL);

    // Close socket
    close(sockfd);

    // Free memory
    free(sending_data);

    return 0;
}

void *receiving_thread(void *arg)
{
    int sockfd = *(int *)arg;
    char *msg_received = malloc(MSG_SIZE);
    while (1)
    {
        struct sockaddr_in server_addr;
        socklen_t server_addr_size = sizeof(server_addr);
        memset(msg_received, 0, MSG_SIZE);
        if (recvfrom(sockfd, msg_received, MSG_SIZE, 0, (struct sockaddr *)&server_addr, &server_addr_size) < 0)
        {
            fprintf(stderr, "recvfrom: %s\n", strerror(errno));
            exit(1);
        }
        printf("Message received: %s\n", msg_received);
    }
    free(msg_received);
    return NULL;
}

void *sending_thread(void *arg)
{
    struct sending_data *sending_data = (struct sending_data *)arg;
    int sockfd = sending_data->socket;
    struct sockaddr_in addr = sending_data->server_addr;
    char *msg_to_send = malloc(MSG_SIZE);
    while (1)
    {
        memset(msg_to_send, 0, MSG_SIZE);
        scanf("%[^\n]%*c", msg_to_send);

        if (sendto(sockfd, msg_to_send, strlen(msg_to_send), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        {
            fprintf(stderr, "sendto: %s\n", strerror(errno));
            exit(1);
        }
    }
    free(msg_to_send);
    return NULL;
}
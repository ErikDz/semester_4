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
#define N_THREADS 5
#define MAX_SIZE 1024
// We define a struct to pass the info to handle_response
typedef struct
{
    int sock;
    struct sockaddr_in client_addr;
    char msg[MAX_SIZE];
} msg_info;

typedef struct
{
    pthread_t thread_id;
    struct sockaddr_in client_address;
    msg_info *msg_info;

} client_thread;

void *handle_response(void *arg);
pthread_mutex_t lock;

int main(int argc, char *argv[])
{
    if (argc != 2)
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

    // Define maxbuffer
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

    // We define a list of mofo_thread
    client_thread client_array[N_THREADS];

    int counter = 0;
    while (1)
    {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);

        // We receive the message checking MSG_TRUNC to make sure that the message was not truncated
        char *msg = malloc(sizeof(char) * maxbuffer);
        pthread_mutex_lock(&lock);
        int bytes_received = recvfrom(sock, msg, maxbuffer, MSG_TRUNC, (struct sockaddr *)&client_addr, &client_addr_size);
        pthread_mutex_unlock(&lock);
        if (bytes_received < 0)
        {
            perror("recvfrom");
            return 4;
        }

        int found = 0;
        pthread_t thread;
        for (int i = 0; i < N_THREADS; i++)
        {
            if (memcmp(&client_array[i].client_address, &client_addr, sizeof(struct sockaddr_in)) == 0)
            {
                // return 1;
                printf("User already connected \n");
                found = 1;
                pthread_mutex_lock(&lock);
                strcpy(client_array[i].msg_info->msg, msg);
                pthread_mutex_unlock(&lock);
            }
        }
        // If the client is not found, we create a new thread
        if (found == 0)
        {
            msg_info *info = malloc(sizeof(msg_info));
            info->sock = sock;
            info->client_addr = client_addr;
            strcpy(info->msg, msg);

            pthread_create(&thread, NULL, (void *)handle_response, (void *)info);
            client_array[counter].client_address = client_addr;
            client_array[counter].thread_id = thread;
            client_array[counter].msg_info = info;
            // Increase the counter
            counter++;
        }
    }
    // Close socket
    close(sock);
    return 0;
}

void *handle_response(void *arg)
{
    msg_info *info = (msg_info *)arg;
    int sock = info->sock;
    struct sockaddr_in client_addr = info->client_addr;
    char *msg = info->msg;

    printf("Received message: \"%s\" from %s:%d\n", msg, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Send back the message to the client
    while (1)
    {
        int bytes_sent = sendto(sock, msg, MAX_SIZE, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (bytes_sent < 0)
        {
            perror("sendto");
            exit(5);
        }
        sleep(1);
        printf("%s\n", msg);
    }
    printf("Im outta here lol\n");

    return NULL;
}
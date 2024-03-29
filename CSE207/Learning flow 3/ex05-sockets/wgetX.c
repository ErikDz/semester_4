/**
 *  Jiazi Yi
 *
 * LIX, Ecole Polytechnique
 * jiazi.yi@polytechnique.edu
 *
 * Updated by Pierre Pfister
 *
 * Cisco Systems
 * ppfister@cisco.com
 *
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

#include "url.h"
#include "wgetX.h"

int main(int argc, char *argv[])
{
    url_info info;
    const char *file_name = "received_page";
    if (argc < 2)
    {
        fprintf(stderr, "Missing argument. Please enter URL.\n");
        return 1;
    }

    char *url = argv[1];

    // Get optional file name
    if (argc > 2)
    {
        file_name = argv[2];
    }

    // First parse the URL
    int ret = parse_url(url, &info);
    if (ret)
    {
        fprintf(stderr, "Could not parse URL '%s': %s\n", url, parse_url_errstr[ret]);
        return 2;
    }

    // If needed for debug
    // print_url_info(&info);

    // Download the page
    struct http_reply reply;

    ret = download_page(&info, &reply);
    if (ret)
    {
        return 3;
    }

    // Now parse the responses
    char *response = read_http_reply(&reply);
    if (response == NULL)
    {
        fprintf(stderr, "Could not parse http reply\n");
        return 4;
    }

    // If the response starts with http:// we have a redirection
    // Therefore we run the steps again with the new URL

    int redirect_count = 0;
    while (strncmp(response, "http://", 7) == 0)
    {
        redirect_count++;
        if (redirect_count > 20)
        {
            fprintf(stderr, "Infinite redirect");
            return 5;
        }
        printf("Pong\n");
        fprintf(stderr, "Redirecting to %s \n", response);

        //==================================================================

        // First parse the URL
        ret = parse_url(response, &info);
        if (ret)
        {
            fprintf(stderr, "Could not parse URL '%s': %s\n", url, parse_url_errstr[ret]);
            return 2;
        }

        ret = download_page(&info, &reply);
        if (ret)
        {
            return 3;
        }
        response = read_http_reply(&reply);
        if (response == NULL)
        {
            fprintf(stderr, "Could not parse http reply\n");
            return 4;
        }
    }

    // Write response to a file
    write_data(file_name, response, reply.reply_buffer + reply.reply_buffer_length - response);

    // Free allocated memory
    free(reply.reply_buffer);

    // Just tell the user where is the file
    fprintf(stderr, "the file is saved in %s.", file_name);
    return 0;
}

int download_page(url_info *info, http_reply *reply)
{

    /*
     * To be completed:
     *   You will first need to resolve the hostname into an IP address.
     *
     *     Use gethostbyname function.
     */

    
    struct hostent *host = gethostbyname(info->host);
    if (host == NULL)
    {
        fprintf(stderr, "Could not resolve hostname %s\n", info->host);
        return 1;
    }    



    /*
     * To be completed:
     *   Next, you will need to send the HTTP request.
     *   Use the http_get_request function given to you below.
     *   It uses malloc to allocate memory, and snprintf to format the request as a string.
     *
     *   Use 'write' function to send the request into the socket.
     *
     *   Note: You do not need to send the end-of-string \0 character.
     *   Note2: It is good practice to test if the function returned an error or not.
     *   Note3: Call the shutdown function with SHUT_WR flag after sending the request
     *          to inform the server you have nothing left to send.
     *   Note4: Free the request buffer returned by http_get_request by calling the 'free' function.
     *
     */

    // We create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Could not create socket\n");
        return 1;
    }

    // We connect to the server
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(info->port);
    memcpy(&serveraddr.sin_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        fprintf(stderr, "Could not connect to server\n");
        return 1;
    }

    // We send the request
    char *request = http_get_request(info);
    int request_length = strlen(request);
    int sent = write(sockfd, request, request_length);

    if (sent < 0)
    {
        fprintf(stderr, "Could not send request\n");
        return 1;
    }

    // We shutdown the socket
    shutdown(sockfd, SHUT_WR);

    // We free the request buffer
    free(request);




    /*
     * To be completed:
     *   Now you will need to read the response from the server.
     *   The response must be stored in a buffer allocated with malloc, and its address must be save in reply->reply_buffer.
     *   The length of the reply (not the length of the buffer), must be saved in reply->reply_buffer_length.
     *
     *   Important: calling recv only once might only give you a fragment of the response.
     *              in order to support large file transfers, you have to keep calling 'recv' until it returns 0.
     *
     *
     */

    //*     Do it the proper way by calling recv multiple times.
    //*     Whenever the allocated reply->reply_buffer is not large enough, use realloc to increase its size:
    //*        reply->reply_buffer = realloc(reply->reply_buffer, new_size);

    // We allocate the buffer
    reply->reply_buffer = (char *)malloc(1024);
    int total = 0;
    int n = 0;
    while ((n = recv(sockfd, reply->reply_buffer + total, 1024, 0)) > 0)
    {
        total += n;
        reply->reply_buffer = realloc(reply->reply_buffer, total + 1024);
    }
    reply->reply_buffer_length = total;

    // We close the socket
    close(sockfd);

    return 0;
}

void write_data(const char *path, const char *data, int len)
{
    /*
     * To be completed:
     *   Use fopen, fwrite and fclose functions.
     */
    FILE *file = fopen(path, "w");
    fwrite(data, 1, len, file);
    fclose(file);
}

char *http_get_request(url_info *info)
{
    char *request_buffer = (char *)malloc(100 + strlen(info->path) + strlen(info->host));
    snprintf(request_buffer, 1024, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n",
             info->path, info->host);
    return request_buffer;
}

char *next_line(char *buff, int len)
{
    if (len == 0)
    {
        return NULL;
    }

    char *last = buff + len - 1;
    while (buff != last)
    {
        if (*buff == '\r' && *(buff + 1) == '\n')
        {
            return buff;
        }
        buff++;
    }
    return NULL;
}

char *read_http_reply(struct http_reply *reply)
{

    // Let's first isolate the first line of the reply
    char *status_line = next_line(reply->reply_buffer, reply->reply_buffer_length);
    if (status_line == NULL)
    {
        fprintf(stderr, "Could not find status\n");
        return NULL;
    }
    *status_line = '\0'; // Make the first line is a null-terminated string

    // Now let's read the status (parsing the first line)
    int status;
    double http_version;
    int rv = sscanf(reply->reply_buffer, "HTTP/%lf %d", &http_version, &status);
    if (rv != 2)
    {
        fprintf(stderr, "Could not parse http response first line (rv=%d, %s)\n", rv, reply->reply_buffer);
        return NULL;
    }

    // We implement redirection support only for 301 and 302

    if (status == 301 || status == 302)
    {

        // We add the next few lines to the reply buffer
        // char *location = strstr(reply->reply_buffer, "Location: ");
        // char *location = strstr(next_, "Location: ");
        char *location = strstr(status_line + 1, "Location: ");

        // READ UNTIL NEWLINE OF HEADER!!!!!!!!

        if (location == NULL)
        {
            fprintf(stderr, "Could not find location header in reply (status=%d, %s)\n", status, reply->reply_buffer);
            // We print the next line to see where the problem is with s
            printf("Next line: %s", next_line(reply->reply_buffer, 100));
            return NULL;
        }
        location += strlen("Location: ");
        char *end = strchr(location, '\r');
        if (end == NULL)
        {
            fprintf(stderr, "Could not find end of location header in reply (status=%d, %s)\n", status, reply->reply_buffer);
            return NULL;
        }
        *end = '\0';
        return location;
    }

    /*
     * To be completed:
     *   The previous code only detects and parses the first line of the reply.
     *   But servers typically send additional header lines:
     *     Date: Mon, 05 Aug 2019 12:54:36 GMT<CR><LF>
     *     Content-type: text/css<CR><LF>
     *     Content-Length: 684<CR><LF>
     *     Last-Modified: Mon, 03 Jun 2019 22:46:31 GMT<CR><LF>
     *     <CR><LF>
     *
     *   Keep calling next_line until you read an empty line, and return only what remains (without the empty line).
     *
     *   Difficul challenge:
     *     If you feel like having a real challenge, go on and implement HTTP redirect support for your client.
     *
     */

    char *buf = status_line + 2;
    char *next = next_line(buf, reply->reply_buffer_length - (buf - reply->reply_buffer));
    while (next != NULL)
    {
        if (next[2] == '\r' && next[3] == '\n')
        {
            return next + 4;
        }
        buf = next + 2;
        next = next_line(buf, reply->reply_buffer_length - (buf - reply->reply_buffer));
    }

    return buf;
}

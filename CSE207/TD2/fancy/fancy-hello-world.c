#include <stdio.h>
#include <string.h>
#include "fancy-hello-world.h"

void hello_string(char* name, char* output) { 

    char hello[1000] = "Hello World, hello ";
    strcat(hello, name);
    strcat(hello, "\n");
    strcpy(output, hello);    

}


int main(void) {
    char name[1000];
    char output[1000];

    printf("Enter your name: ");
    scanf("%s", name);
    hello_string(name, output);
    printf("%s", output);
    return 0;
}
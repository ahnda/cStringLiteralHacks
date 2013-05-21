#include <stdlib.h>
#include <stdio.h>

void main(int argc, char **argv) {
    char* secret = "change this";
    if (argc < 2) {
        return;
    }
    if (strcmp(secret, argv[1]) == 0) {
        printf("You win!\n");
    }
}

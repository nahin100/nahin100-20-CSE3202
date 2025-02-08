#define _GNU_SOURCE /* To get various declarations from <stdlib.h> */
#include <stdio.h>
#include <stdlib.h>

//run program by using following commands: gcc new2.c -o new2 && ./new2 SHELL=/bin/sh BYE=byebye

extern char **environ;

int main(int argc, char *argv[]) {
    int j;
    char **ep;

    clearenv();

    for (j = 1; j < argc; j++) {
        printf("Setting environment variable: %s\n", argv[j]); // Print argument before setting
        if (putenv(argv[j]) != 0) {
            printf("Error setting: %s\n", argv[j]); // Minimal error message
        }
    }

    if (setenv("GREET", "Hello world", 0) == -1) {
        printf("Error setting GREET\n");
    }

    unsetenv("BYE");

    for (ep = environ; *ep != NULL; ep++) {
        puts(*ep);
    }

    return 0; 
}

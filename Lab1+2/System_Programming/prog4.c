#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

static int idata = 111; /* Allocated in data segment */

int main(int argc, char *argv[]) {
    int istack = 222; /* Allocated in stack segment */
    pid_t childPid;

    switch (childPid = fork()) {
        case -1:
            printf("Error: fork failed: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        case 0: /* Child process */
            idata *= 3;
            istack *= 3;
            break;
        default: /* Parent process */
            sleep(3); /* Give child a chance to execute */
            break;
    }

    /* Both parent and child come here */
    printf("%s PID=%ld PARENT PID=%ld  idata=%d istack=%d\n",
        (childPid == 0) ? "(child) " : "(parent)", (long) getpid(), (long) getppid(), idata, istack);
    
    return 0;
}
#include <sys/wait.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define NUM_CHILDREN 3
const int sleepTimes[NUM_CHILDREN] = {2, 4, 6};  // Sleep times for children

int main() {
    int numDead = 0; /* Number of children so far waited for */
    pid_t childPid;
    int j;

    setbuf(stdout, NULL); /* Disable buffering of stdout */

    for (j = 0; j < NUM_CHILDREN; j++) { /* Create children with predefined sleep times */
        switch (fork()) {
            case -1:
                printf("Error: fork failed\n");
                exit(EXIT_FAILURE);
            case 0: /* Child sleeps for a while then exits */
                printf("Child %d started with PID %ld, sleeping %d seconds\n", j + 1, (long) getpid(), sleepTimes[j]);
                sleep(sleepTimes[j]);
                exit(EXIT_SUCCESS);
            default: /* Parent just continues around loop */
                break;
        }
    }

    for (;;) { /* Parent waits for each child to exit */
        childPid = wait(NULL);
        if (childPid == -1) {
            if (errno == ECHILD) {
                printf("No more children - bye!\n");
                exit(EXIT_SUCCESS);
            } else { /* Some other (unexpected) error */
                printf("Error: wait failed\n");
                exit(EXIT_FAILURE);
            }
        }
        numDead++;
        printf("wait() returned child PID %ld (numDead=%d)\n", (long) childPid, numDead);
    }
}

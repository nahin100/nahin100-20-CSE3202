#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a new child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("Error: fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process: Replacing program with execv...\n");

        // Path to the new program
        char *program = "./hello_world"; // Path to the "hello_world" program which is compiled already
        char *args[] = {program, NULL};  // Arguments array

        // Replace the child process with the new program
        if (execv(program, args) == -1) {
            printf("Error: execv failed\n");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        printf("Parent process: Waiting for child to complete...\n");
        wait(NULL); // Wait for the child process to finish
        printf("Parent process: Child finished execution.\n");
    }

    return 0;
}

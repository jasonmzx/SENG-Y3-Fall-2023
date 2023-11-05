#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main() {
    int pid = fork();

    if (pid == -1) {
        // Error
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) { // Child process
        // Change the process group of the child
        if (setpgid(0, 0) == -1) {
            perror("setpgid");
            return EXIT_FAILURE;
        }

        // Attempt to read from the control terminal
        char input[10];
        printf("Child process group ID: %d\n", getpgrp());
        printf("Enter some text: ");
        fgets(input, sizeof(input), stdin);
        printf("Child read: %s\n", input);
        return EXIT_SUCCESS;
    } else { // Parent process
        printf("Parent process group ID: %d\n", getpgrp());
        // Wait for the child process to complete
        wait(NULL);
    }

    return EXIT_SUCCESS;
}

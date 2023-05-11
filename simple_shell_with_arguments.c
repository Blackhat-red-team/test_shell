#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS + 1];

    while (1) {
        printf("simple_shell$ ");  // Display the prompt
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("\n");  // Handle EOF (Ctrl+D)
            break;
        }

        command[strcspn(command, "\n")] = '\0';  // Remove trailing newline

        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGUMENTS) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            wait(NULL);  // Wait for the child to complete
        }
    }

    return 0;
}

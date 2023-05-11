#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char *args[] = { NULL };

    while (1) {
        printf("simple_shell$ ");
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0'; 

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
           
            if (execvp(command, args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
           
            wait(NULL);
        }
    }

    return 0;
}

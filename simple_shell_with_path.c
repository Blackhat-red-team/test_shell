#include "shell.h"

int main(void)
{
char command[MAX_COMMAND_LENGTH];
char *args[MAX_ARGUMENTS + 1];

    while (1)
    {
        printf("simple_shell$ ");  
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            printf("\n");  
            break;
        }

        command[strcspn(command, "\n")] = '\0';  

        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGUMENTS)
        {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } 
        else if (pid == 0)
        {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else 
        {
          
            wait(NULL);  
        }
    }

    return (0);
}

#include "shell.h"

void processCommand(char *command)
{

}
void executeCommand(char **args)
{

}

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

        processCommand(command);
        executeCommand(args);

      
    }

    return (0);
}

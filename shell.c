#include "main.h"
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt(void)
{
	char *prompt = "#shell:) ";

	write(STDOUT_FILENO, prompt, strlen(prompt));
}

int read_command(char *command)
{
	ssize_t input = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);

	if (input == -1)
	{
	perror("Error: Failed to read");
	exit(EXIT_FAILURE);
	}

	if (input == 0 || command[0] == '\n')
	{
	/* End of file or empty command (Ctrl+D)*/
	return (0);
	}

	command[input - 1] = '\0'; /*Remove the newline character*/
	return (1);
}

void exec_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
	perror("Error: Failed to create a child process");
	exit(EXIT_FAILURE);
}
	else if (pid == 0)
	{
	/*Child process*/
	char *args[MAX_ARGUMENTS];
	char *token;
	int i = 0;
	token = strtok(command, " ");

	while (token != NULL && i < MAX_ARGUMENTS - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
        }
        args[i] = NULL;

	execvp(args[0], args); /*Execute the command*/
	perror("Error: Command not found");
	exit(EXIT_FAILURE);
	}
	else
	{
	/*Parent process*/
	wait(NULL);
	}
}

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
	display_prompt();
	if (!read_command(command))
	{
	/*End of file (Ctrl+D), exit the shell*/
	write(STDOUT_FILENO, "\n", 1);
	break;
	}
	exec_command(command);
	}

	return (0);
}

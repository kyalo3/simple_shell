#include "main.h"
/**
 * execute_builtin - executes builtin commands
 * @args: arguments
 *Return: 1 or 0
 */
int execute_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
	/* Exit the shell*/
	exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
	/*Print the environment variables*/
	char **env = environ;

	while (*env)
	{
	write(STDOUT_FILENO, *env, strlen(*env));
	write(STDOUT_FILENO, "\n", 1);
	env++;
	}
		return (1);
	}
	return (0);
}

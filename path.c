#include "main.h"
/**
* handle_path - handles the path
* @args: arguments
*
*/

void handle_path(char **args)
{
	char *path = getenv("PATH");
	char *path_token;
	char *file_path = malloc(MAX_INPUT_SIZE * sizeof(char));

	if (file_path == NULL)
	{
	perror("malloc failed");
	exit(EXIT_FAILURE);
	}

	path_token = strtok(path, ":");
	while (path_token != NULL)
	{
	/* Construct the full path of the command*/
	strcpy(file_path, path_token);
	strcat(file_path, "/");
	strcat(file_path, args[0]);

	/*Check if the file is executable*/
	if (access(file_path, X_OK) == 0)
	{
	/* Replace the command with the full path*/
	args[0] = strdup(file_path);
	free(file_path);
		return;
		}

	path_token = strtok(NULL, ":");
	}

	/*Free allocated memory*/
	free(file_path);

	/* Command doesn't exist in any path, display error message */
	fprintf(stderr, "Command not found: %s\n", args[0]);
	exit(EXIT_FAILURE);
}

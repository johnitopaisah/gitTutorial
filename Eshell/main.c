#include "main.h"

int main()
{
	char *strt = ">_ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0, i;
	char *token;
	char **argv;
	

	/* creating a loop for the shell's prompt */
	while(1 == 1)
	{
		printf("%s", strt);
		nchars_read = getline(&lineptr, &n, stdin);

		/* check if the getline function failed or reached EOF or user use CTRL + D */
		if (nchars_read == -1)
		{
			perror("Exiting shell...\n");
			break;
		}

		/* ignoring empty lines */
		if (nchars_read == 1)
			continue;

		/* allocate space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(nchars_read));
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		/* copy lineptr to lineptr_copy */
		strcpy(lineptr_copy, lineptr);

		/**
		 * splitting the string (lineptr into an array of words
		 * 	calculte teh total number of token
		 */
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}


		/* allocating space to hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens + 1);
		if (argv == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		/* store each token in the argv array */
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token) + 1);
			if (argv[i] == NULL)
			{
				perror("tsh: memory allocation error");
				return (-1);
			}
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/* execute the command */
		execmd(argv);

		/* free memory allocated for tokens */
		for (i = 0; argv[i]; i++)
			free(argv[i]);

		/* free up allocation */
		free(argv);
		free(lineptr_copy);

		/* reset num_token for next loop */
		num_tokens = 0;
	}

	free(lineptr);
	return (0);
}

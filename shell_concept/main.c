#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	(void)ac;
	char *enter = "$ ";
	ssize_t char_read;
	char *line = NULL;
	size_t len = 0;
	const char *delim = " ";
	char *tok;

	while (1 == 1)
	{
		printf("%s", enter);
		
		char_read = getline(&line, &len, stdin);
		if (char_read == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		line[char_read - 1] = '\0';
		printf("%lu\n", char_read);
		printf("%ld\n", strlen(line));

		tok = strtok(line, delim);

		while (tok != NULL)
		{
			printf("%s\n", tok);

			tok = strtok(NULL, delim);
		}

	}
	free(line);
	return (0);
}

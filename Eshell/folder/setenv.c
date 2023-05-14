#include <stdio.h>
#include <stdlib.h>


int main()
{
	setenv("MY_VAR", "hello world", 1);
	char* my_var = getenv("MY_VAR");
	printf("MY_VAR: %s\n", my_var);
	return (0);
}

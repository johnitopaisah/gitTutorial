#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("The parent PID: %d\n", getppid());
	return (0);
}

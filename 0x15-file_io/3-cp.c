#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - IS a function that allocates
*                 1024 bytes for a BUFFER.
* @file: is the NAME of the file.
*
* Return: returns a POINTER to the newly-allocated BUFFER.
*/
char *create_buffer(char *file)
{
	char *Buff;

	Buff = malloc(sizeof(char) * 1024);

	if (Buff == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (Buff);
}

/**
* close_file - Is a function that CLOSES a FILE descriptors.
* @fd: IS The FILE descriptor that is going to be closed.
*/
void close_file(int fd)
{
	int CLOSE;

	CLOSE = close(fd);

	if (CLOSE == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
* main -IT COPIES the Contents of a FILE to ANOTHER FILE.
* @argc: IS The number of arguments that are supplied to the program.
* @argv: IS an ARRAY of POINTERS to the arguments.
*
* Return: 0 on success.
**/
int main(int argc, char *argv[])
{
	int FROM, TO, R, W;
	char *Buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	Buff = create_buffer(argv[2]);
	FROM = open(argv[1], O_RDONLY);
	R = read(from, buffer, 1024);
	TO = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (FROM == -1 || R == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(Buff);
			exit(98);
		}

		W = write(TO, Buff, R);
		if (TO == -1 || W == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(Buff);
			exit(99);
		}

		R = read(FROM, Buff, 1024);
		TO = open(argv[2], O_WRONLY | O_APPEND);

	} while (R > 0);

	free(Buff);
	close_file(FROM);
	close_file(TO);

	return (0);
}

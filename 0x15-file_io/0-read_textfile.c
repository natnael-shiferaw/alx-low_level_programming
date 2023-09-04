#include "main.h"
#include <stdlib.h>

/**
* read_textfile- To read Text File.
* @filename: is text file being read
* @letters: Is the number of letters intended to be read.
* Return: the actual Number of Bytes Read and Printed
*,0 when function fails OR filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *Buff;
	ssize_t Fd;
	ssize_t W;
	ssize_t T;

	Fd = open(filename, O_RDONLY);
	if (Fd == -1)
		return (0);
	Buff = malloc(sizeof(char) * letters);
	T = read(Fd, Buff, letters);
W = write(STDOUT_FILENO, Buff, T);

	free(Buff);
	close(Fd);
	return (W);
}

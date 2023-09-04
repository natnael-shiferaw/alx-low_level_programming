#include "main.h"

/**
* read_textfile -it Read and Print a text file to standard output.
* @filename:Is The name of the file to read.
* @letters:is The number of letters to read and print.
*
* Return: The actual number of letters read and printed, or 0 on failure.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rd, wr;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
	{
		close(fd);
		return (0);
	}

	rd = read(fd, buf, letters);
	close(fd);

	if (rd == -1)
	{
		free(buf);
		return (0);
	}

	wr = write(STDOUT_FILENO, buf, rd);
	free(buf);

	if (wr == -1 || wr != rd)
		return (0);

	return (wr);
}

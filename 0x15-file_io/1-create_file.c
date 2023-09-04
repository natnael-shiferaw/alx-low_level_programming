#include "main.h"

/**
* create_file -a function that creates a File.
* @filename: Is a Pointer to the Name of the File to Create.
* @text_content: is a pointer to a String that writes to the file.
*
* Return: returns 1 on success, -1 on failure.
*/
int create_file(const char *filename, char *text_content)
{
	int Fd, W, LEN;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (LEN = 0; text_content[LEN];)
			LEN++;
	}

	Fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	W = write(Fd, text_content, LEN);

	if (Fd == -1 || W == -1)
		return (-1);

	close(Fd);

	return (1);
}

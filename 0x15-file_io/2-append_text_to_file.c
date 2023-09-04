#include "main.h"

/**
* append_text_to_file -Function that APPENDS a text
*                    at the END of a File.
* @filename:Is a POINTER to the name of the File.
* @text_content: IS The string to add to the END of the FILE.
*
* Return: IT returns 1 on success
*          - and -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int O, W, LEN;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (LEN = 0; text_content[LEN];)
			LEN++;
	}

	O = open(filename, O_WRONLY | O_APPEND);
	W = write(O, text_content, LEN);

	if (O == -1 || W == -1)
		return (-1);

	close(O);

	return (1);
}

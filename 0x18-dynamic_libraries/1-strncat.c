#include "main.h"

/**
* _strncat - PERFORMS STRING CONCATNATION
* but add inputted number of bytes
* @dest: DESTINATION
* @src: SOURCE
* @n: INTEGER TO COMPARE TO INDEX
* Return: returns new concatenated string
*/

char *_strncat(char *dest, char *src, int n)
{

	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;

	for (index = 0; src[index] && index < n; index++)
		dest[dest_len++] = src[index];

	return (dest);
}

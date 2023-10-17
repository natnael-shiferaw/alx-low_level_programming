#include "main.h"

/**
* _strncpy - USED TO COPY A STRING USING
*   -INPUTTED NUMBER OF BYTES.
* @dest: DESTINATION.
* @src:SOURCE
* @n:NUMBER OF BYTES TO BE COPIED.
* Return: returns COPIED STRING.
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

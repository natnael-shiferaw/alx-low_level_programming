#include "main.h"

/**
*_strcat - PERFORMS STRING CONCATNATION
*@dest: DESTINATION
*@src: SOURCE
* Return: returns poinTer to DESTINATION
*/

char *_strcat(char *dest, char *src)
{

	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;

	for (index = 0; src[index]; index++)
		dest[dest_len++] = src[index];

	return (dest);
}

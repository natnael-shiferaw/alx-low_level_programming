#include "main.h"

/**
* _strcpy - USED TO COPY STRING
* @dest: DESTINATION
* @src: SOURCE
* Return: THE COPIED STRING.
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

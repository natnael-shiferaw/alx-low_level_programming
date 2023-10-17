#include "main.h"

/**
* _strlen - FINDS LENGTH OF STRING.
*  @s: STRING
* Return: LENGTH OF STRING.
*/

int _strlen(char *s)
{
	int count, i;

	i = 0;

	for (count = 0; s[count] != '\0'; count++)
		i++;

	return (i);
}

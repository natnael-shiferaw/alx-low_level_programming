#include "main.h"
#include <stddef.h>

/**
*_strchr - SEARCHES FOR A CHAR IN STRING.
* @s: STRING.
* @c: CHARACTER
* Return: RETURN FIRST OCCURRENCE OF c,
* - OR NULL ON FAILURE.
*/

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; (s[i] != c) && (s[i] != '\0'); i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

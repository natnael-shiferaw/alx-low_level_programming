#include "main.h"

/**
*_strpbrk - LOCATES FIRST OCCURRENCE OF STRING
*@s: STRING
*@accept: STRING WHERE SEARCH BYTES ARE ACCEPTED.
*
*Return:Returns POINTER TO s, OR NULL.
*/

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (accept[i] == *s)
				return (s);
		}
		s++;
	}

	return ('\0');
}

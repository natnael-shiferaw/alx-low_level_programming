#include "main.h"

/**
 *_memset - USED TO FILL WITH CONSTANT BYTES.
*@s:THE TARGET
*@b: CONSTANT BYTE
*@n:NUMBER OF BYTES
*Return: returns new value of TARGET.
*/

char *_memset(char *s, char b, unsigned int n)
{
	while (n)
	{
		s[n - 1] = b;
		n--;
	}
	return (s);
}

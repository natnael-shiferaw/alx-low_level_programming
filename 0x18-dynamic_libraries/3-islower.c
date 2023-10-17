#include "main.h"

/**
*_islower - CHECKS IF CHAR IS LOWERCASE.
*@c: CHARACTER
*Return: 1 ON SUCCESS, 0 ON FAILURE.
*/

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);

	return (0);
}

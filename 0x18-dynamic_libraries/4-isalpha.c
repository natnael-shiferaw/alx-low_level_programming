#include "main.h"

/**
* _isalpha - CHECKS IF CHAR IS ALPHABET.
* @c: CHARARCTER.
* Return: 1 0N YES, 0 ON NO.
*/

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);

	return (0);
}

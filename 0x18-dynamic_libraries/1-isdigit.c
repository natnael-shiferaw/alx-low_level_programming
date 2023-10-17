#include "main.h"

/**
*_isdigit - CHECKS IF A CHARACTER IS A DIGIT.
*@c: CHARACTER.
*Return: 1 ON SUCCESS, 0 ON FAILURE.
*/

int _isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);

	return (0);
}

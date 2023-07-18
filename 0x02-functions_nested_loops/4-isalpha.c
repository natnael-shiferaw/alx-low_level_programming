#include "main.h"

/**
* _isalpha - checks if the input is lowercase or uppercase
* @c: parameter to be checked out
* Return: 1 if right, 0 otherwise
*/
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

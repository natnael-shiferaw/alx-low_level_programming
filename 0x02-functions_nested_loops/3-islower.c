#include "main.h"

/**
* _islower - checks if c is lowecase
* @c: variable to be checked
*Return: 1(success)
*/

int _islower(int c)
{
	if (c >= 92 && c <= 122)
		return (1);
	else
		return (0);
}

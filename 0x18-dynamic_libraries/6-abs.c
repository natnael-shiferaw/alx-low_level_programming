#include "main.h"

/**
* _abs - PRINTS ABSOLUTE VALUE OF AN INT
* @i: THE NUMBER
* Return: returns AN INTEGER
*/

int _abs(int i)
{
	if (i > 0)
		return (i);
	else if (i < 0)
		return (-i);
	else
		return (0);
}

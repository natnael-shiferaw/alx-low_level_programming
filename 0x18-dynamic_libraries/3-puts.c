#include "main.h"

/**
* _puts - USED TO PRINT STRING.
* @str: STRING.
* RETURN: VOID
*/

void _puts(char *str)
{
	while (*str)
		_putchar(*str++);

	_putchar('\n');
}

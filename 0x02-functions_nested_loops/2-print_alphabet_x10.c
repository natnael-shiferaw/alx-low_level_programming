#include "main.h"
/**
*main - prints 10 times lowercase letters
* description: using userdefined function
* Return: nothing
*/
void print_alphabet_x10(void)
{
int i;
char j;
for (i = 0; i < 10; i++)
{
for (j = 'a'; j <= 'z'; j++)
	_putchar(j);
_putchar('\n');
}
}


#include "main.h"
/**
*_isupper - check for uppercase letter.
* Return: 1 if c is uppercase, 0 otherwise.
* @c: letter to be checked.
*/
int _isupper(int c)
{
if ((c >= 65) && (c <= 90))
return (1);
else
return (0);
}

#include "hash_tables.h"

/**
 * key_index - A FUNCTION THAT IS USED TO GET THE INDEX AT WHINCH
 *  A key/value PAIR IS STORED IN ARRAY OF A HASH TABLE.
 * @key: REPRESENTS THE KEY TO GET THE INTENDED INDEX.
 * @size: REPRESENTS THE SIZE OF ARRAY OF THE HASH TABLE.
 * Description: IT TAKES A key AND A sizE AS INPUT AND IT USES
 *  hash_djb2 FUNCTION FOR GETTING THE HASH OF THE KEY AND FINALLY
 *  IT USES THE MODULO OPERATOR FOR GETTING THE INDEX OF THE KEY.
 *
 * Return: RETURNS THE INDEX OF THE KEY.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

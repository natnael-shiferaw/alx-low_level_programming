#include "hash_tables.h"

/**
 * hash_table_create - A FUNCTION THAT IS USED TO
 *  - CREATE A HASH TABLE
 * @size: REPRESENTS THE SIZE OF ARRAY.
 * Description: THIS FUNCTION ALLOCATES MEMORY FOR THE HASH
 * - TABLE AND THEN FOR THE ARRAY OF POINTERS TO THE NODES AND
 * - THEN IT INITIALIZES THE ARRAY OF POINTERS TO THE NODES AND
 *  - FINALLYRETURN THE POINTER THE HASH TABLE.
 *
 * Return: A POINTER TO A HASH TABLE THAT'S CREATED.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int k;
	hash_table_t *HASHtable;

	HASHtable = malloc(sizeof(hash_table_t));

	if (HASHtable == NULL)
		return (NULL);
	HASHtable->size = size;
	HASHtable->array = malloc(size * sizeof(hash_node_t *));

	if (HASHtable->array == NULL)
	{
		free(HASHtable);
		return (NULL);
	}

	for (k = 0; k < size; k++)
		HASHtable->array[k] = NULL;
	return (HASHtable);
}

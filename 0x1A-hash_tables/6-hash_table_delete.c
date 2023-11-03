#include "hash_tables.h"

/**
 * hash_table_delete - A FUNCTION THAT IS USED TO DELETE/REMOVE
 *  - A HASH TABLE.
 * @ht: REPRESENTS A POINTER TO A HASH TABLE.
 * Description: THIS FUNCTION ITERATES THROUGH THE ARRAY OF LINKED
 *  -LISTS AND FOR ALL THE LINKED LISTS, IT ITERATES THROUGH IT AND FREES
 *  -EACH NODE , ARRAY OF LINKED LISTS AND FREEING THE HASH TABLE.
 *
 * Return: NOTHING.
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int k;
	hash_node_t *NODE, *TEMP;
	hash_table_t *HEAD = ht;

	for (k = 0; k < ht->size; k++)
	{
		if (ht->array[k] != NULL)
		{
			NODE = ht->array[k];
			while (NODE != NULL)
			{
				TEMP = NODE->next;
				free(NODE->key);
				free(NODE->value);
				free(NODE);
				NODE = TEMP;
			}
		}
	}
	free(HEAD->array);
	free(HEAD);
}

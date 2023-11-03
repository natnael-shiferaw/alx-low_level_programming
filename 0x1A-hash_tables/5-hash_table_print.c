#include "hash_tables.h"

/**
 * hash_table_print - A FUNCTION THAT IS USED TO PRINT A HASH TABLE.
 * @ht: REPRESENTS A POINTER TO THE HASH TABLE THAT'S TO BE PRINTED.
 *
 * Description: IN THIS FUNCTION Key/value PAIRS ARE PRINTED IN THE ORDER
 *  THAT THEY SEEM TO APPEAR IN THE ARRAY OF THE HASH TABLE.
 *
 * Return: NOTHING.
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned char FLAGcomma = 0;
	hash_node_t *NODE;
	unsigned long int k;

	if (ht == NULL)
		return;

	printf("{");

	for (k = 0; k < ht->size; k++)
	{
		if (ht->array[k] != NULL)
		{
			if (FLAGcomma == 1)
				printf(", ");

			NODE = ht->array[k];

			while (NODE != NULL)
			{
				printf("'%s': '%s'", NODE->key, NODE->value);
				NODE = NODE->next;
				if (NODE != NULL)
					printf(", ");
			}
			FLAGcomma = 1;
		}
	}
	printf("}\n");
}

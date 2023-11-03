#include "hash_tables.h"

/**
 * hash_table_get - A FUNCTION THAT IS USED TO RETRIEVE VALUE
 *  THAT'S ASSOCIATED WITH A KEY IN A HASH TABLE.
 * @ht: REPRESENTS THE POINTER TO THE HASH TABLE.
 * @key: REPRESENTS THE KEY TO GET THE VALUE.
 *
 * Return: THE VALUE ASSOCIATED WITH THE ELEMENT, NULL ON FAILURE.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int IDX;
	hash_node_t *NODE;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	IDX = key_index((const unsigned char *)key, ht->size);

	if (ht->size <= IDX)
		return (NULL);

	NODE = ht->array[IDX];

	while (NODE && strcmp(NODE->key, key) != 0)
		NODE = NODE->next;

	return ((NODE == NULL) ? NULL : NODE->value);
}

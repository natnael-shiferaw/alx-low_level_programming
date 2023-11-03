#include "hash_tables.h"

/**
 * hash_table_set - A FUNCTION USED TO INSERT OR UPDATE AN ELEMENT
 *  INSIDE THE HASH TABLE.
 * @ht: REPRESENTS A POINTER TO THE HASH TABLE.
 * @key: REPRESENTS THE KEY.
 * @value: REPRESENTS THE VALUE.
 *
 * Return: 1 ON SUCCESS, 0 OTHERWISE.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int INDEX, k;
	char *CPY_VAL;
	hash_node_t *NEW;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	CPY_VAL = strdup(value);

	if (CPY_VAL == NULL)
		return (0);

	INDEX = key_index((const unsigned char *)key, ht->size);

	for (k = INDEX; ht->array[k]; k++)
	{
		if (strcmp(ht->array[k]->key, key) == 0)
		{
			free(ht->array[k]->value);
			ht->array[k]->value = CPY_VAL;
			return (1);
		}
	}
	NEW = malloc(sizeof(hash_node_t));
	if (NEW == NULL)
	{
		free(CPY_VAL);
		return (0);
	}
	NEW->key = strdup(key);

	if (NEW->key == NULL)
	{
		free(NEW);
		return (0);
	}
	NEW->value = CPY_VAL;
	NEW->next = ht->array[INDEX];
	ht->array[INDEX] = NEW;
	return (1);
}

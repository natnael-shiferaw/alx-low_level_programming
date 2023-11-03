#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - A FUNCTION THAT IS USED TO CREATE A SORTED HASH TABLE.
 * @size: REPRESENTS THE SIZE OF THE SORTED HASH TABLE.
 *
 * Return: A POINTER TO THE SORTED HASH TABLE, NULL ON FAILURE.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int k;
	shash_table_t *HASH_T;

	HASH_T = malloc(sizeof(shash_table_t));

	if (HASH_T == NULL)
		return (NULL);

	HASH_T->size = size;
	HASH_T->array = malloc(sizeof(shash_node_t *) * size);

	if (HASH_T->array == NULL)
		return (NULL);

	for (k = 0; k < size; k++)
		HASH_T->array[k] = NULL;
	HASH_T->shead = NULL;
	HASH_T->stail = NULL;

	return (HASH_T);
}

/**
 * shash_table_set - A FUNCTION THAT IS USED TO ADD AN
 *  ELEMENT TO THE SORTED HASH TABLE.
 * @ht: A POINTER TO THE SORTED HASH TABLE.
 * @key: REPRESENTS THE KEY TO ADD.
 * @value: REPRESENTS THE VALUE THAT'S ASSOCIATED WITH THE KEY.
 *
 * Return: 1 ON SUCCESS, 0 OTHERWISE.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int IDX;
	char *CPY_VAL;
	shash_node_t *NEW, *TEMP;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	CPY_VAL = strdup(value);

	if (CPY_VAL == NULL)
		return (0);

	IDX = key_index((const unsigned char *)key, ht->size);
	TEMP = ht->shead;

	while (TEMP)
	{
		if (strcmp(TEMP->key, key) == 0)
		{
			free(TEMP->value);
			TEMP->value = CPY_VAL;
			return (1);
		}
		TEMP = TEMP->snext;
	}

	NEW = malloc(sizeof(shash_node_t));
	if (NEW == NULL)
	{
		free(CPY_VAL);
		return (0);
	}
	NEW->key = strdup(key);
	if (NEW->key == NULL)
	{
		free(CPY_VAL);
		free(NEW);
		return (0);
	}
	NEW->value = CPY_VAL;
	NEW->next = ht->array[IDX];
	ht->array[IDX] = NEW;

	if (ht->shead == NULL)
	{
		NEW->sprev = NULL;
		NEW->snext = NULL;
		ht->shead = NEW;
		ht->stail = NEW;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		NEW->sprev = NULL;
		NEW->snext = ht->shead;
		ht->shead->sprev = NEW;
		ht->shead = NEW;
	}
	else
	{
		TEMP = ht->shead;
		while (TEMP->snext != NULL && strcmp(TEMP->snext->key, key) < 0)
			TEMP = TEMP->snext;
		NEW->sprev = TEMP;
		NEW->snext = TEMP->snext;
		if (TEMP->snext == NULL)
			ht->stail = NEW;
		else
			TEMP->snext->sprev = NEW;
		TEMP->snext = NEW;
	}
	return (1);
}

/**
 * shash_table_get - A FUNCTION THAT IS USED TO RETRIEVE THE VALUE
 * - THAT'S ASSOCIATED WITH THE KEY IN THE SORTED HASH TABLE.
 *
 * @ht: REPRESENTS A POINTER TO THE SORTED HASH TABLE.
 * @key: REPRESENTS THE KEY TO GET THE VALUE.
 *
 * Return: ON SUCCESS THE VALUE THAT'S ASSOCIATED WITH THE KEY
 *    - OTHERWISE NULL.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int IDX;
	shash_node_t *NODE;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	IDX = key_index((const unsigned char *)key, ht->size);

	if (ht->size <= IDX)
		return (NULL);

	NODE = ht->shead;
	while (NULL != NODE && 0 != strcmp(NODE->key, key))
		NODE = NODE->snext;

	return ((NODE == NULL) ? NULL : NODE->value);
}

/**
 * shash_table_print - A FUNCTION THAT'S USED TO PRINT THE SORTED HASH TABLE.
 * @ht: REPRESENTS A POINTER TO THE SORTED HASH TABLE.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *NODE;

	if (ht == NULL)
		return;

	NODE = ht->shead;
	printf("{");

	while (NODE != NULL)
	{
		printf("'%s': '%s'", NODE->key, NODE->value);
		NODE = NODE->snext;
		if (NODE != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - A FUNCTION USED TO PRINT THE SORTED HASH TABLE
 *  - IN REVERSE ORDER.
 * @ht: REPRESENTS A POINTER TO THE SORTED HASH TABLE.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *NODE;

	if (ht == NULL)
		return;

	NODE = ht->stail;
	printf("{");

	while (NODE != NULL)
	{
		printf("'%s': '%s'", NODE->key, NODE->value);
		NODE = NODE->sprev;
		if (NODE != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - A FUNCTION THAT'S USED TO DELETE/REMOVE
 * - SORTED A HASH TABLE.
 * @ht: REPRESENTS A POINTER TO THE SORTED HASH TABLE.
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *NODE, *TEMP;
	shash_table_t *HEAD = ht;

	if (ht == NULL)
		return;

	NODE = ht->shead;

	while (NODE)
	{
		TEMP = NODE->snext;
		free(NODE->key);
		free(NODE->value);
		free(NODE);
		NODE = TEMP;
	}
	free(HEAD->array);
	free(HEAD);
}

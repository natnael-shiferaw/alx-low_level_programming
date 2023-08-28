#include "lists.h"

/**
* add_nodeint - insert/add new node in the beginning of linked list
* @head: is pointer for the first node in the list
* @n: a data to be inserted in a new node
* Return: pointer to the new node, or NULL if it fails
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *a;
a = malloc(sizeof(listint_t));
if (!a)
return (NULL);

a->n = n;
a->next = *head;
*head = a;

return (a);
}

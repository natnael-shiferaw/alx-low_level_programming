#include "lists.h"

/**
* free_listint2 - is used to free a linked list
* @head: a pointer to be freed that represents the listint_t list
*/
void free_listint2(listint_t **head)
{
listint_t *Temp;

if (head == NULL)
return;

while (*head)
{
Temp = (*head)->next;
free(*head);
*head = Temp;
}

*head = NULL;
}

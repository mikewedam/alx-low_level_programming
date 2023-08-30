#include "lists.h"

/**
 * free_listint - Frees all nodes of a linked list.
 * @head: Pointer to the first node of the list to be freed.
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

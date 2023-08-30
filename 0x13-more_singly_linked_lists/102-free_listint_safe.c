#include "lists.h"

/**
 * free_listint_safe - Safely frees a linked list, handling potential loops.
 * @h: Pointer to a pointer to the first node in the linked list.
 *
 * Return: The number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current = *h;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (current)
	{
		temp = current->next;

		if (temp && temp > current)
		{
			free(current);
			current = temp;
			len++;
		}
		else
		{
			free(current);
			current = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}

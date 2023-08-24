#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @p: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */
size_t print_list(const list_t *p)
{
	size_t count = 0;

	while (p)
	{
		if (p->str)
			printf("[%u] %s\n", p->len, p->str);
		else
			printf("[0] (nil)\n");

		p = p->next;
		count++;
	}

	return (count);
}

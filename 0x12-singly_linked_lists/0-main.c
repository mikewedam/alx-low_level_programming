#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	list_t *head;
	list_t *newElement;
	list_t hello = {"World", 5, NULL};
	size_t count;

	head = &hello;
	newElement = malloc(sizeof(list_t));
	if (newElement == NULL)
	{
		printf("Error\n");
		return (1);
	}
	newElement->str = strdup("Hello");
	newElement->len = 5;
	newElement->next = head;
	head = newElement;
	count = print_list(head);
	printf("-> %lu elements\n", count);

	printf("\n");
	free(newElement->str);
	newElement->str = NULL;
	count = print_list(head);
	printf("-> %lu elements\n", count);

	free(newElement);
	return (0);
}

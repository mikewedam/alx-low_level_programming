#include "main.h"
/**
 * add - adds two integers and returnsthe result
 *
 * @x: number being added
 *
 * @y: number being added
 *
 * Return: Always 0.
 *
 */
int add(int x, int y)
{
	return (x + y);
}


Task 11

#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - prints all natural numbers from n to 98
 *
 * @n: starting point
 *
 * Return: returns nothing
 *
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
		for (n = n; n <= 97; n++)
			printf("%d, ", n);
	}
	else
		for (n = n; n > 98; n--)
			printf("%d, ", n);
	printf("98\n");
}

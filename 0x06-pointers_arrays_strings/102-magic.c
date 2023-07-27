#include "main.h"
#include <stdio.h>

/**
 * main - The main function is the entry of the program.
 * It performs an operation and returns an integer value indicatindicating the execution.
 *
 * Return: 0 on success.
 */

int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	/*
	 * write your line of code here...
	 * Remember:
	 * -you are nto allowed to use a
	 *  -you are not allowed to modify p
	 *  -only one statement
	 *  -you are not allowed to code anything else than this line of code
	 */
	*(p + 7) = 98;
	/*... so that this prints 98\n*/
	printf("a[2] = %d\n", a[2]);

	return (0);
}

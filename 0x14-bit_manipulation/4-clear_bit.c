#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @num: pointer to the number to change
 * @index: index of the bit to clear
 *
 * Return: 1 when success, -1 when failure
 */
int clear_bit(unsigned long int *num, unsigned int index)
{
	if (index > 63)
		return (-1);

	*num = (~(1UL << index) & *num);
	return (1);
}

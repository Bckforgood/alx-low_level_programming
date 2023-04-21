#include "variadic_functions.h"

/**
 * sum_them_all - a function that returns the sum of all its parameters.
 * @n: number of element to be add
 *
 * Return: sum
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list nums;
	unsigned int i, sum = 0;
	unsigned int i;
	int sum = 0;
	va_list list;

	if (n == 0)
		return (0);

	va_start(nums, n);
	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(nums, int);
		sum += va_arg(list, int);
	}

	va_end(nums);

	va_end(list);
	return (sum);
}

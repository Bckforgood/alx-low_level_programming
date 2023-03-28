#include "main.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer.
 *
 * @s: the string to convert.
 *
 * Return: the integer value of the string.
 */
int _atoi(char *s)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}

	if (s[i] == '+')
	{
		i++;
	}

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
		{
			break;
		}
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
		{
			return sign == 1 ? INT_MAX : INT_MIN;
		}
		res = res * 10 + (s[i] - '0');
		i++;
	}

	return sign * res;
}

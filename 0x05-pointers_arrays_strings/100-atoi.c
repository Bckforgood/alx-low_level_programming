#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
        int res = 0;
        int sign = 1;
        int i = 0;

        while (s[i] != '\0') {
                if (s[i] == '-') {
                        sign = -sign;
                } else if (s[i] >= '0' && s[i] <= '9') {
                        res = res * 10 + (s[i] - '0');
                } else if (res > 0) {
                        break;
                }
                i++;
        }

        return sign * res;
}

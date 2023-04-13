#include <main.h>
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: First string to concatenate
 * @s2: Second string to concatenate
 * @n: Maximum number of bytes to use from s2
 *
 * Return: Pointer to the newly allocated string, or NULL if allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *concatenated_str;
    unsigned int s1_len = 0, s2_len = 0;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    s1_len = strlen(s1);
    s2_len = strlen(s2);

    if (n >= s2_len)
        n = s2_len;

    concatenated_str = malloc(sizeof(char) * (s1_len + n + 1));

    if (concatenated_str == NULL)
        return (NULL);

    memcpy(concatenated_str, s1, s1_len);
    memcpy(concatenated_str + s1_len, s2, n);
    concatenated_str[s1_len + n] = '\0';

    return (concatenated_str);
}


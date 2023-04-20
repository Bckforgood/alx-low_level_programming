#include <function_pointers.h>

/**
 * print_name - prints a name using a function pointer
 *
 * @name: name to print
 * @f: function pointer to print name
 *
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
    f(name);
}
void print(char *name)
{
    printf("Name: %s\n", name);
}
int main(void)
{
    char *name = "John Doe";
    print_name(name, print);
    return (0);
}

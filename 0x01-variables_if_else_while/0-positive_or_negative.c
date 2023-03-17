#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int n = rand() % 201 - 100; // n will be a random number between -100 and 100

    printf("%d is ", n);
    if (n > 0) {
        printf("positive");
    } else if (n < 0) {
        printf("negative");
    } else {
        printf("zero");
    }
    printf("\n");

    return 0;
}

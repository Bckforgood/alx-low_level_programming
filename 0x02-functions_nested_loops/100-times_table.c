#include <stdio.h>
#include <main.h>
int main() {
    int n;
    printf("Enter n (0 <= n <= 15): ");
    scanf("%d", &n);
    printf("Times table for %d:\n", n);
    print_times_table(n);
    return 0;
}


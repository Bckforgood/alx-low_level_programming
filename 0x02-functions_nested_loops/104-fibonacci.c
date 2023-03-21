#include <stdio.h>
#include <main.h>

void fibonacci_sequence(int n, int sequence[]) {
    /* Computes the first n numbers of the Fibonacci sequence */
    sequence[0] = 1;
    sequence[1] = 2;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
}

int main() {
    int n = 50;
    int fib_sequence[n];
    
    fibonacci_sequence(n, fib_sequence);
    
    // Print the first 50 Fibonacci numbers separated by commas
    for (int i = 0; i < n-1; i++) {
        printf("%d, ", fib_sequence[i]);
    }
    printf("%d\n", fib_sequence[n-1]);
    
    return 0;
}


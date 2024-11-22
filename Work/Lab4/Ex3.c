#include <stdio.h>
#include "Ex3.h"

// Recursive GCD function
int gcd_recursive(int x, int y) {
    if (y == 0)
        return x;
    return gcd_recursive(y, x % y);
}

// Iterative GCD function
int gcd_iterative(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    int x = 98, y = 56;

    // Output GCD using recursive method
    printf("GCD of %d and %d (recursive): %d\n", x, y, gcd_recursive(x, y));

    // Output GCD using iterative method
    printf("GCD of %d and %d (iterative): %d\n", x, y, gcd_iterative(x, y));

    return 0;
}

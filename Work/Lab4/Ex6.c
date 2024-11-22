#include <stdio.h>
#include <math.h>
#include "Ex6.h"

void transform_with_math_h(double *x) {
    printf("Using <math.h>:\n");
    printf("Original value: %.2f\n", *x);

    double ceil_value = ceil(*x);
    printf("Ceil value: %.2f\n", ceil_value);

    double floor_value = floor(*x);
    printf("Floor value: %.2f\n", floor_value);
}

void transform_without_math_h(double *x) {
    printf("\nWithout <math.h>:\n");
    printf("Original value: %.2f\n", *x);

    int ceil_value = (int)(*x);
    if (*x > (double)ceil_value) {
        ceil_value++; 
    }
    printf("Ceil value: %.2f\n", (double)ceil_value);

    int floor_value = (int)(*x);
    if (*x < 0 && *x != (double)floor_value) {
        floor_value--; 
    }
    printf("Floor value: %.2f\n", (double)floor_value);
}

int main() {
    double num;

    printf("Enter a real number: ");
    scanf("%lf", &num);

    transform_with_math_h(&num);
    transform_without_math_h(&num);

    return 0;
}

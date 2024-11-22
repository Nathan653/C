#include <stdio.h>

// Function definitions
int add(int a, int b){
    return a + b;
}
int subtract(int a, int b){
    return a - b;
}
int multiply(int a, int b){
    return a * b;
}

int main(void){
    int num1;
    int num2;
    
    printf("Enter the first number:\n");
    scanf("%d", &num1);
    printf("Enter the second number:\n");
    scanf("%d", &num2);
    
     printf("The sum of %d and %d is: %d\n", num1, num2, add(num1, num2));
    printf("Subtracting %d from %d is: %d\n", num2, num1, subtract(num1, num2));
    printf("The product of %d and %d is: %d\n", num1, num2, multiply(num1, num2));

    return 0;
}
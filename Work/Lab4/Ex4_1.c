#include <stdio.h>
#include "Ex4_1.h"

void decimal_to_hexadecimal(int n) {
    // Base case: when the number is 0
    if (n == 0)
        return;

    decimal_to_hexadecimal(n / 16);
  
    int remainder = n % 16;
    if (remainder < 10)
        printf("%d", remainder);  
    else
        printf("%c", 'A' + remainder - 10);  
}

int main() {
    int decimal = 456; 
    printf("Decimal %d in hexadecimal is: ", decimal);
    if (decimal == 0) {
        printf("0");
    } else {
        decimal_to_hexadecimal(decimal);  
    }
    printf("\n");
    return 0;
}

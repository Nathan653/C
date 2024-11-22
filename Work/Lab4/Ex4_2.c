#include <stdio.h>
#include "Ex4_2.h"
#include <string.h>

void reverse_string(char str[], int start, int end) {
    if (start >= end)
        return;
    
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    reverse_string(str, start + 1, end - 1);
}

int main() {
    char str[] = "whats up";
    int len = strlen(str); 
    
    printf("Original string: %s\n", str);
    
    reverse_string(str, 0, len - 1);
    
    printf("Reversed string: %s\n", str);
    return 0;
}

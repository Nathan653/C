#include <stdio.h>
#include <string.h>
#include "Ex5.h"

void analyze_string(char str[]){
    int length = strlen(str);
    int freq[256] = {0};
    char most_freq_char = '\0';
    int max_freq = 0;
    int is_valid = 1;

    for(int i = 0; i < length; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            is_valid = 0;
            break;
        }

        freq[(unsigned char)str[i]]++;

        if(freq[(unsigned char)str[i]] > max_freq){
            max_freq = freq[(unsigned char)str[i]];
            most_freq_char = str[i];
        }
    }
    printf("Input validity: %s\n", is_valid ? "Valid" : "Invalid");
    if (is_valid) {
        printf("Input length: %d\n", length);
        printf("Input's first character: %c\n", str[0]);
        printf("Input's most frequent character: %c\n", most_freq_char);
}
}

int main(){
    char input[100]; 
    printf("Enter a string (no numeric characters allowed): ");
    fgets(input, sizeof(input), stdin);

     size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    analyze_string(input);

    return 0;

}
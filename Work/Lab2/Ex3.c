#include <stdio.h>
#include <string.h>

void reverseWord(char word[]){
    int length = strlen(word);

    for (int i = length - 1; i >= 0; i--){
        printf("%c", word[i]);
    }
    printf("\n");
}


int main(){
    char word1[100], word2[100], word3[100];

    printf("Enter your first word: \n");
    scanf("%s", word1);
    
    printf("Enter your second word: \n");
    scanf("%s", word2);

    printf("Enter your third word: \n");
    scanf("%s", word3);

    printf("\nReversed words:\n");
    reverseWord(word1);
    reverseWord(word2);
    reverseWord(word3);

    return 0;

}
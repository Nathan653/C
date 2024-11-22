#include <stdio.h>

int main(){
    int pin;
    int guess;
    int tries = 5;

    printf("Create your pin (please remember your pin): ");
    scanf("%d", &pin);

    printf(".\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n");
    
    
    while(tries > 0){
        printf("Enter the pin: ");
        scanf("%d", &guess);
        
        if(guess == pin){
            printf("Pin is correct\n");
            break;
        } else{
            tries--;
            if(tries > 0){
            printf("Wrong, you have %d tries left\n", tries);
            } else {
                printf("You have been locked out due to too many failed attempts.\n");
            }
        }
    }
    return 0;
    
}
#include <stdio.h>

int main(){
    int n;
    long long factorial = 1;
    printf("Enter n (to calculate n!) : ");
    scanf("%d", &n);
    if(n<0){
        printf("Invalid, must be a positive integer...\n");

    } else{
    for(int i = 1; i<=n; i++){
        factorial *= i;
    }
    printf("The factorial of %d is %lld\n", n, factorial);
    }
}
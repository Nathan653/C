#include <stdio.h>

int main(){
    int inputs[10];
    int weeks[10], days[10];


    for(int i = 0; i < 10; i++){
        printf("Enter value %d(in days):\n", i+1);
        scanf("%d", &inputs[i]);

        weeks[i] = inputs[i]/7;
        days[i] = inputs[i]%7;


        printf("Value %d = %d weeks and %d days\n", i+1, weeks[i], days[i]);
    }

    return 0;
}
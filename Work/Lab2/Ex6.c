#include <stdio.h>

int main(){
    
    double dollars, euros;
    
for(int i = 0; i < 10; i++){
    printf("(%d) Amount in Dollars: \n", i+1);
    scanf("%lf", &dollars);

    euros = dollars * 0.93;
    printf("Amount in Euros: %.2lf\n", euros);
    printf("\n");
}

}
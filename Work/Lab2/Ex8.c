#include <stdio.h>
#include <math.h>

double zetaFunction(double s, int limit){
    double sum = 0.0;

    for(int n = 1; n <= limit; n++){
        sum += 1.0 / pow(n, s);
    }
    return sum;
}

int main(){
    double s;
    int limit;

    printf("Enter value of s (must be > 1): ");
    scanf("%lf", &s);

    if(s <= 1){
        printf("Error, must be > 1...");
        return 1;
    }

    printf("Enter value of approx. (ex: 1000, 100000...): ");
    scanf("%d", &limit);

    double result = zetaFunction(s, limit);
    printf("Approx. of the Riemann zeta function for s = %.2f with limit %d is: %.10f\n", s, limit, result);

    return 0;
}
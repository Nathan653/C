#include <stdio.h>

double calculateTax(double income, int isICTIndustry, int collectsOldElectronics){
    double tax = 0.0;

    double firstBracket = collectsOldElectronics ? 15000 : 10000;
    double secondBracket = 8000;
    double rate1 = 0.18;
    double rate2 = 0.20;
    double rate3 = 0.25;

    if(income <= firstBracket){
        tax = income * rate1;
    }   else if(income <= firstBracket + secondBracket){
        tax = income * rate1 + (income - firstBracket) * rate2;
    }   else{
        tax = income * rate1 + secondBracket * rate2 + (income - firstBracket - secondBracket) * rate3;
    }
    if(isICTIndustry){
        tax *= 0.95;
    }
    return tax;
}

int main(){
    double income;
    int isICTIndustry, collectsOldElectronics;

    printf("Enter your annual income: ");
    scanf("%lf", &income);

    printf("Are you in ICT industry? (1 for yes, 0 for no): ");
    scanf("%d", &isICTIndustry);
    
    printf("Do you collect old electronics for green disposal? (1 for yes, 0 for no): ");
    scanf("%d", &collectsOldElectronics);

    double tax = calculateTax(income, isICTIndustry, collectsOldElectronics);

    printf("Your calculated tax is $%.2f\n", tax);

    return 0;
}
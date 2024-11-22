#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 5
#define MAX_LENGTH 10

void truncateString(char str[]){
    if (strlen(str) > MAX_LENGTH){
        str[MAX_LENGTH] = '\0';
    }
}

int main(){
    char empName[MAX_EMPLOYEES][MAX_LENGTH], empSur[MAX_EMPLOYEES][MAX_LENGTH];
    int empAge[MAX_EMPLOYEES];
    double monthPay[MAX_EMPLOYEES];
    double yearTot[MAX_EMPLOYEES];
    double total = 0;
    int precision;

    printf("Enter the desired precision for salary columns: ");
    scanf("%d", &precision);

    for(int i = 0; i < MAX_EMPLOYEES; i++){
        printf("(%d) Please enter your name: \n", i + 1);
        scanf("%s", empName[i]);
        truncateString(empName[i]);

        printf("(%d) Please enter your surname: \n", i + 1);
        scanf("%s", empSur[i]);
        truncateString(empSur[i]);

        printf("(%d) Please enter your Age: \n", i + 1);
        scanf("%d", &empAge[i]);

        printf("(%d) Please enter your Monthly pay: \n", i + 1);
        scanf("%lf", &monthPay[i]);
        yearTot[i] = monthPay[i] * 12;

        if (i == 0) {
            printf("\n| %-5s | %-10s | %-10s | %-5s | %-15s | %-15s |\n", "No.", "Name", "Surname", "Age", "Monthly Salary", "Yearly Total");
            printf("----------------------------------------------------------------------------------------------\n");
        }

        printf("| %-5d | %-10s | %-10s | %-5d | %-*.*f | %-*.*f |\n", 
               i + 1, 
               empName[i], 
               empSur[i], 
               empAge[i], 
               15, precision, monthPay[i], 
               15, precision, yearTot[i]);
        printf("----------------------------------------------------------------------------------------------\n");
       
        total += yearTot[i];
    }


    printf("\n| %-5s | %-10s | %-10s | %-5s | %-15s | %-15s |\n", "No.", "Name", "Surname", "Age", "Monthly Salary", "Yearly Total");
    printf("----------------------------------------------------------------------------------------------\n");


    for(int i = 0; i < MAX_EMPLOYEES; i++){
        printf("| %-5d | %-10s | %-10s | %-5d | %-*.*f | %-*.*f |\n", 
               i + 1, 
               empName[i], 
               empSur[i], 
               empAge[i], 
               15, precision, monthPay[i], 
               15, precision, yearTot[i]);
        printf("----------------------------------------------------------------------------------------------\n");
    }

    double averageSal = total / MAX_EMPLOYEES;
    printf("Average Yearly Salary: %.*lf\n", precision, averageSal);  

    return 0;
}

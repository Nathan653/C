#include <stdio.h>

#define InitialStock 1000
#define MaxOrder 1000

int main(void){
    int A3Stock = InitialStock;
    int A4Stock = InitialStock;
    int A5Stock = InitialStock;
    int A3Order, A4Order, A5Order;

    printf("How any A3 pages would you like to order? (max %d)\n", MaxOrder);
    scanf("%d", &A3Order);

    if(A3Order < 0 || A3Order > MaxOrder){
        printf("Invalid, it has to be between 0 and %d", MaxOrder);
        return 1;
    }

    printf("How any A4 pages would you like to order? (max %d)\n", MaxOrder);
    scanf("%d", &A4Order);

     if(A4Order < 0 || A4Order > MaxOrder){
        printf("Invalid, it has to be between 0 and %d", MaxOrder);
        return 1;
    }

    printf("How any A5 pages would you like to order? (max %d)\n", MaxOrder);
    scanf("%d", &A5Order);

     if(A5Order < 0 || A5Order > MaxOrder){
        printf("Invalid, it has to be between 0 and %d", MaxOrder);
        return 1;
    }

    A3Stock -= A3Order;
    A4Stock -= A4Order;
    A5Stock -= A5Order;

    printf("You ordered %d A3 Pages, there are %d A3 pages left in stock\n", A3Order, A3Stock);
    printf("You ordered %d A4 Pages, there are %d A4 pages left in stock\n", A4Order, A4Stock);
    printf("You ordered %d A5 Pages, there are %d A5 pages left in stock\n", A5Order, A5Stock);

    return 0;
}
#include <stdio.h>
#include "Ex2.h"

//Iterative version:
long fib_Iterative(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++){
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
//Recursive version:
long fib_Recursive(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib_Recursive(n - 1) + fib_Recursive(n - 2);
}
/*Readability: Recursive is elegant but harder to follow, iterative is simpler.
Stack Usage: Recursive uses O(n)O(n) space (can cause overflow); iterative uses O(1)
O(1) space (more efficient).*/
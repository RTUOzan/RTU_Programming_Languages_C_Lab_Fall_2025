#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
    // TODO: compute factorial iteratively
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact; // placeholder
}

int main(void) {
    int n;
    printf("Enter a non-negative integer n: ");
    scanf("%d", &n);

    if (n < 0) {
       printf("Error: n must be non negative. \n "); 
    }else{
        long long result = factorial(n);
        printf("%d! = %11d\n ", n, result);     
    }

    // TODO: validate input, call function, print result

    return 0;
}

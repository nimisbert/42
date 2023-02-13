/* OREILLY : Algorithm in C, 2002
 * Author : Kyle Loudon
 * Notes :
 * Recopie personel des codes du livre lors de sa lecture
 */

#include <stdio.h>

int fact( int n);               // recursive factoriel
int fact_term( int n, int a);   // recursive terminal factoriel

int main(void)
{
    int n = 3, a = 1;
    printf("factoriel   %d = %d",n,fact(n));
    printf("tfactoriel  %d = %d",n,fact_term(n,a));
}

int fact( int n)
{
    if ( n < 0 ) {
        return 0;
    } else if ( n == 0 ) {
        return 1;
    } else if ( n == 1 ) {
        return 1;
    }  else {
        return n*fact(n-1);
    }
}

int fact_term( int n, int a)
{
    if ( n < 0 ) {
        return 0;
    } else if ( n == 0 ) {
        return 1;
    } else if ( n == 1 ) {
        return a;
    } else {
        return fact_term( n-1, n*a);
    }
}

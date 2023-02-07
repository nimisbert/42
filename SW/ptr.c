/* OREILLY : Algorithm in C, 2002
 * Author : Kyle Loudon
 * Notes :
 * Recopie personel des codes du livre lors de sa lecture
 */

#include <stdlib.h> 

int f(int **iptr); // pointeur et variables automatique. CHAP2.p13
int g(int **iptr); // allocation dynamique de memoire. CHAP2.p14

int array_f(void); // sequence elements homogene par tableau
int array_g(void); // sequence elements homogene par pointeur
int array_gg(void);// sequence 2D d elements homogene par pointeur

void main(void)
{
    int *a;
    f(&a);
    g(&a);
    free(a);
}

int f(int **iptr)
{
    int a = 10; // variable automatic a
    *iptr = &a; // init de iptr avec addresse de a
    array_f();  // manipulation elements homogenes par tableau
    array_g();  // manipulation elements homogenes par pointeurs
    array_gg(); // manipulation elements homogenes par pointeurs 2D
    return 0;   // return a devient dangling ptr
}

int g(int **iptr)
{
    // addresse de espace memoire de int du tas est associe a iptr
    if ( (*iptr = (int*)malloc(sizeof(int))) == NULL) {
        return -1; // espace memoire pas alloue
    }
    return 0; // iptr existe toujours apres la sortie de g
}

int array_f(void)
{
    int a[10], *iptr;
    iptr = a;
    for( int i = 0; i < 10 ; i++) {
        iptr[i] = 1;
    }
    return 0;
}

int array_g(void)
{
    int a[10], *iptr;
    iptr = a;
    for( int i = 0; i < 10; i++) {
        *(iptr+i) = 1;
    }

    return 0;
}

int array_gg(void)
{
    int a[10][10];
    for( int i = 0; i < 10; i++ ) {
        for( int j = 0; j < 10; j++) {
            *(*(a+i)+j) = 1;    // meme ligne que $+1
            a[i][j] = 1;        // meme ligne que $-1
        }
    }
}

/* OREILLY : Algorithm in C, 2002
 * Author : Kyle Loudon
 * Notes :
 * Recopie personel des codes du livre lors de sa lecture
 */

#include <stdlib.h> 
#include <string.h>

int f(int **iptr); // pointeur et variables automatique. CHAP2.p13
int g(int **iptr); // allocation dynamique de memoire. CHAP2.p14

int array_f(void); // sequence elements homogene par tableau
int array_g(void); // sequence elements homogene par pointeur
int array_gg(void);// sequence 2D d elements homogene par pointeur

int swap_1(int a, int b); // echange incorrect acause de passage par valeur
int swap_2(int *a, int *b); // echange correct par passage par reference

int f1(int tab[]); // passage de tableau
int f2(int *tab); // passage de pointeur identique a f1
int f3(int tab[][2]); // passage de tableau de plusieurs dimensions

int swap_3(void *x, void *y, int taille); // pointeurs generiques

void main(void)
{
    int *a;
    f(&a);
    g(&a);
    free(a);
    int c = 10, d = 20;
    swap_1(c, d);
    swap_2(&c, &d);
    f1(a);
    f2(a);
    int b[2][2];
    f3(b);
    swap_3(&c, &d, sizeof(int));
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
    return 0;
}

int swap_1(int x, int y) // passage de parametre par valeur
{
    int tmp = x;
    x = y;
    y = tmp;
    return 0; // swap incorrect
}

int swap_2(int *x, int *y) // passage de parametre par reference
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return 0; // swap correct
}

int f1(int tab[]) 
{
    tab[0] = 5;
    return 0;
}

int f2(int *tab)
{
    *tab = 5;
    return 0;
}

int f3( int tab[][2]) // deuxieme dimension necessaire pour appliquer arithmetique des pointeurs
{                    // stockage ligne par ligne du tableau a deux dimensions
    tab[0][2] = 5;
}

int swap_3( void *x, void *y, int taille)
{
    void *tmp;
    if((tmp = malloc(taille)) == NULL)
        return -1;
    memcpy(tmp,x,taille);
    memcpy(x,y,taille);
    memcpy(y,tmp,taille);
    free(tmp);
    return 0;
}

// Q&A
/*
int qAnda_q1(void)
{
    char *sptr = "abc", *tptr;
    *tptr = sptr; // erreur de compilation ; dereference de pointeur de char auquel est assigne pointeur de char
}
*/
int qAnda_q2(void)
{
    char *sptr = "abc", *tptr;
    tptr = sptr; // code ok
}

int qAnda_q3(void)
{
    char *sptr = "abc", *tptr;
    *tptr = *sptr; // erreur execution ; dereference de pointeur non initialiser
}

int qAnda_q4(void)
{
    int *iptr = (int*)10;
    *iptr=11; // erreur execution ; assignation du pointeur entier iptr a adresse fixe
}
/*
int qAnda_q5(void)
{
    int *iptr = 10; // erreur de compilation ; initialisation de pointeur entier avec la valeur d'un entier
    *iptr = 11;
}
*/
int qAnda_q6(void)
{
    int *iptr = (int *)10; // init a adresse fixe dangereux
    iptr = NULL; // reinit avec NULL qui ce qui est ok
}

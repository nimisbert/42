/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#include "chtbl.h"

typedef enum Token_ {
    finlex,
    erreur,
    chiffre,
    autre
} Token;

Token lex( const char *flot_entree, CHTbl *symtab);

void main(void)
{
    return;
}

Token lex( const char *flot_entree, CHTbl *symtab)
{
    
}
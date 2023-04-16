/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 * Exemple page 198
 */
#include <stdio.h>
#include "bitree.h"
#include "sll.h"

int preorder    ( const BiTreeNode *noeud, List *liste);
int inorder     ( const BiTreeNode *noeud, List *liste);
int postorder   ( const BiTreeNode *noeud, List *liste);

void main(void)
{
    printf("Solving prefix representation of\r\n");
    printf("(* (/ (-74 10) 32) (+ 23 17)) = 80\r\n");
// Building the Tree :
    BiTree prefixEquationTree;
    bitree_init( &prefixEquationTree, free);
    bitree_destroy( &prefixEquationTree);    
    return;
}

int preorder( const BiTreeNode *noeud, List *liste)
{
    if( !bitree_is_eob( noeud) ) {
        if( list_ins_next( liste, list_tail( liste), bitree_data(noeud)) != 0) {
            return -1;
        }
        if( !bitree_is_eob( bitree_left( noeud))) {
            if( preorder( bitree_left( noeud), liste) != 0) {
                return -1;
            }
        }
        if( !bitree_is_eob( bitree_right( noeud))) {
            if( preorder( bitree_right( noeud), liste) != 0) {
                return -1;
            }
        }
        return 0;
    }
}


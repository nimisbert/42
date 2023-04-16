/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#ifndef BITREE_H
#define BITREE_H

typedef struct BitTreeNode_{
    void *donnee;
    struct BiTreeNode_ *gauche;
    struct BiTreeNode_ *droite;
} BiTreeNode;

typedef struct BiTree_ {
    int taille;
    int  (*compare)     ( const void *cle1, const void *cl2);
    void (*detruire)    ( void *donnee);
    BiTreeNode *racine;
} BiTree;

void bitree_init        ( BiTree *arbre, void (*detruire)(void *donnee));
void bitree_destroy     ( BiTree *arbre);

int bitree_ins_left     ( BiTree *arbre, BiTreeNode *noeud, const void *donnee);
int bitree_ins_right    ( BiTree *arbre, BiTreeNode *noeud, const void *donnee);

void bitree_rem_left    ( BiTree *arbre, BiTreeNode *noeud);
void bitree_rem_right   ( BiTree *arbre, BiTreeNode *noeud);

int bitree_merge        ( BiTree *fusion, BiTree *gauche, BiTree *droite, const void *donnee);

#define bitree_size(arbre)      ((arbre)->taille)
#define bitree_root(arbre)      ((arbre)->racine)
#define bitree_is_eob(noeud)    ((noeud) == NULL)
#define bitree_is_leaf(noeud)   ((noeud)->gauche == NULL && (noeud)->droite == NULL)
#define bitree_data(noeud)      ((noeud)->donnee)
#define bitree_left(noeud)      ((noeud)->gauche)
#define bitree_right(noeud)     ((noeud)->droite) 

#endif 
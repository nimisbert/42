/* OREILLY : Mastering algorithm with C, 2004
 * Author  : Kyle Loudon
 * Notes   :
 * Recopie personelle des codes du livre lors de sa lecture
 */
#include <stdlib.h>
#include <string.h>

#include "bitree.h"

void bitree_init( BiTree *arbre, void (*detruire)(void *donnee))
{
    arbre->taille = 0;
    arbre->detruire = detruire;
    arbre->racine = NULL;
    return;
}

void bitree_destroy( BiTree *arbre)
{
    bitree_rem_left( arbre, NULL);
    memset(arbre, 0, sizeof(BiTree));
    return;
}

int bitree_ins_left( BiTree *arbre, BiTreeNode *noeud, const void *donnee)
{
    BiTreeNode *nouveau_noeud, **position;
    if( noeud == NULL) {
        if( bitree_size(arbre) > 0) {
            return -1;
        } 
        position = &arbre->racine;
    } else {
        if( bitree_left( noeud) != NULL) {
            return -1;
        }
        position = &noeud->gauche;
    }
    if((nouveau_noeud = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL) {
        return -1;
    }
    nouveau_noeud->donnee = (void*) donnee;
    nouveau_noeud->gauche = NULL;
    nouveau_noeud->droite = NULL;
    *position = nouveau_noeud;
    arbre->taille++;
    return 0;
}

int bitree_ins_right( BiTree *arbre, BiTreeNode *noeud, const void *donnee)
{
    BiTreeNode *nouveau_noeud, **position;
    if( noeud == NULL) {
        if( bitree_size(arbre) > 0) {
            return -1;
        }
        position = &arbre->racine;
    } else {
        if( bitree_right(noeud) != NULL) {
            return -1;
        }
        position = &noeud->droite;
    }
    if ( (nouveau_noeud = (BiTreeNode*)malloc(sizeof(BiTreeNode))) == NULL) {
        return -1;
    }
    nouveau_noeud->donnee = (void*)donnee;
    nouveau_noeud->gauche = NULL;
    nouveau_noeud->droite = NULL;
    *position = nouveau_noeud;
    arbre->taille++;
    return 0;
}

void bitree_rem_left( BiTree *arbre, BiTreeNode *noeud)
{
    BiTreeNode **position;
    if( bitree_size(arbre) == 0) {
        return;
    }
    if( noeud == NULL) {
        position = &arbre->racine;
    } else {
        position = &noeud->gauche;
    }
    if( *position != NULL) {
        bitree_rem_left( arbre, *position);
        bitree_rem_right( arbre, *position);
        if( arbre->detruire != NULL) {
            arbre->detruire((*position)->donnee);
        }
        free(*position);
        *position = NULL;
        arbre->taille--;
    }
    return;
}

void bitree_rem_right( BiTree *arbre, BiTreeNode *noeud)
{
    BiTreeNode **position;
    if( bitree_size(arbre) == 0) {
        return;
    }
    if( noeud == NULL) {
        position = &arbre->racine;
    } else {
        position = &noeud->droite;
    }
    if( *position != NULL) {
        bitree_rem_left( arbre, position);
        bitree_rem_right( arbre, position);
        if( arbre->detruire != NULL) {
            arbre->detruire((*position)->donnee);
        }
        free( *position);
        *position = NULL;
        arbre->taille--;
    }
    return;
}

int bitree_merge( BiTree *fusion, BiTree *gauche, BiTree *droite, const void *donnee)
{
    bitree_init( fusion, gauche->detruire);
    if( bitree_ins_left(fusion, NULL, donnee) != 0) {
        bitree_destroy(fusion);
        return -1;
    }

    bitree_root(fusion)->gauche = bitree_root(gauche);
    bitree_root(fusion)->droite = bitree_root(droite);

    fusion->taille = fusion->taille + bitree_size(droite) + bitree_size(gauche);

    gauche->racine = NULL;
    gauche->taille = 0;
    droite->racine = NULL;
    droite->taille = 0;
    return 0;
}
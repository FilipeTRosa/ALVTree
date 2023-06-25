#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"





node * createNodo(){//create a new empty nodo
    node * newNode = (node *) malloc (sizeof(node));

    newNode->father = NULL;
    newNode->key;
    newNode->right = NULL;
    newNode->left =  NULL;
    newNode->factor = 0;
    newNode->balance;

    return newNode;
}

desc_avl * createAVL(){//create a new empty tree
    desc_avl * newTree = (desc_avl *) malloc (sizeof(desc_avl));

    newTree->raiz = NULL;
    newTree->tamanho = 0;

    return newTree;
}

node * removeAvl(desc_avl * favl, int chave){//remove and return one node

    node * aux = NULL;



    return aux;
}
desc_avl * insertAvl(desc_avl * favl, int cha);



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"





node * createNode(int key){//create a new empty nodo
    node * newNode = (node *) malloc (sizeof(node));

    newNode->father = NULL;
    newNode->key = key;
    newNode->right = NULL;
    newNode->left =  NULL;
    newNode->factor = 0;
    newNode->balance;

    return newNode;
}

desc_avl * createAVL(){//create a new empty tree
    desc_avl * newTree = (desc_avl *) malloc (sizeof(desc_avl));

    newTree->root = NULL;
    newTree->height = 0;

    return newTree;
}

node * removeAvl(node * root, int key){//remove and return one node
//    return aux;
}
node * insertAvl(node * root, int key){//insert one node and updade the tree
    // If the tree is empty, create a new node and set it as the root
    if (root == NULL) {
        return createNode(key);
    }

    // Otherwise, recur down the tree
    if (key < root->key) {
        root->left = insertAvl(root->left, key);
    } else if (key > root->key) {
        root->right = insertAvl(root->right, key);
    }

    return root;
}


node * simpleLeftRotation(node * fnode){
    node * ptu;
    ptu = fnode->right;
    fnode->right = ptu->left;
    ptu->left = fnode;
    fnode->factor = 0;
    fnode = ptu;
    return fnode;
}
node * simpleRightRotation(node * fnode){
    node * ptu;
    ptu = fnode->left;
    fnode->left = ptu->right;
    ptu->right = fnode;
    fnode->factor = 0;
    fnode = ptu;
    return fnode;
}
node * doubleLeftRotation(node * fnode){
    node *ptu,*ptv;
    ptu = fnode->right;
    ptv = ptu->left;
    ptu->left = ptv->right;
    ptv->right = ptu;
    fnode->right = ptv->right;
    ptv->left = fnode;
    if(ptv->factor == -1)
        fnode->factor = 1;
    else
        fnode->factor = 0;
    if(ptv->factor == 1)
        ptu->factor = -1;
    else
        ptu->factor = 0;
    fnode = ptv;
    
    return fnode;
}
node * doubleRightRotation(node * fnode){
    node *ptu,*ptv;
    ptu = fnode->left;
    ptv = ptu->right;
    ptu->right = ptv->left;
    ptv->left = ptu;
    fnode->left = ptv->right;
    ptv->right = fnode;
    if(ptv->factor == 1)
        fnode->factor = -1;
    else    
        fnode->factor = 0;
    if(ptv->factor == -1)
        ptu->factor = 1;
    else    
        ptu->factor = 0;
    fnode = ptv;

    return fnode;
}
void printNode(node * fnode){}
void preOrdePrintTree(node * root){
    if (root != NULL) {
        printf("[%d] ", root->key);
        preOrdePrintTree(root->left);
        preOrdePrintTree(root->right);
    }
}
void inOrderPrintTree(node * root){
    if (root != NULL) {
        inOrderPrintTree(root->left);
        printf("[%d] ", root->key);
        inOrderPrintTree(root->right);
    }
}
void postOrdePrintTree(node * root){
    if (root != NULL) {
        postOrdePrintTree(root->left);
        postOrdePrintTree(root->right);
        printf("[%d] ", root->key);
    }
}

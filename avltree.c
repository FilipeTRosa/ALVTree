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
    newNode->height = 0;

    return newNode;
}

desc_avl * createAVL(){//create a new empty tree
    desc_avl * newTree = (desc_avl *) malloc (sizeof(desc_avl));

    newTree->root = NULL;
    newTree->height = 0;

    return newTree;
}
//funcao para pegar altura do nodo
//vai servir para as rotações
int getHeight(node * node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

//calcular o fator debalanço.
int getBalanceFactor(node * node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

//atualizar o fator de balanço
void updateHeight(node* node) {
    printf("Entrada em updateheight\n");
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    printf("nodo [%d] - altura [%d] \n", node->key,node->height);
    
}


node * removeAvl(node * root, int key){//remove and return one node
//    return aux;
}
node * insertAvl(node * root, int key){//insert one node and updade the tree
    //se a arvore estiver vazia
    if (root == NULL) {
        return createNode(key);
    }

    //caso tenha algum nó na arvore
    if (key < root->key) {
        root->left = insertAvl(root->left, key);
    } else if (key > root->key) {
        root->right = insertAvl(root->right, key);
    }else{
        return root;
    }

    // Update the height of the current node
    printf("chamada para updateheight\n");
    updateHeight(root);

    // Check the balance factor and perform necessary rotations
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (key < root->left->key) {
            // Left-left case, perform a right rotation
            return singleRightRotation(root);
        } else {
            // Left-right case, perform a left rotation followed by a right rotation
            root->left = singleLeftRotation(root->left);
            return singleRightRotation(root);
        }
    } else if (balanceFactor < -1) {
        if (key > root->right->key) {
            // Right-right case, perform a left rotation
            return singleLeftRotation(root);
        } else {
            // Right-left case, perform a right rotation followed by a left rotation
            root->right = singleRightRotation(root->right);
            return singleLeftRotation(root);
        }
    }

    return root;
}


// Função para encontrar o nó com o valor mínimo na subárvore direita
node * findMinValueNode(node * fnode) {
    node* aux = fnode;
    while (aux->left != NULL) {
        aux = aux->left;
    }
    return aux;
}


// Função para remover um nó de uma árvore AVL
node * removeNode(node * root, int value) {
    // Caso base: árvore vazia
    if (root == NULL) {
        return root;
    }

    // Caso contrário, execute a remoção de um nó em uma BST normal
    if (value < root->key) {
        root->left = removeNode(root->left, value);
    } else if (value > root->key) {
        root->right = removeNode(root->right, value);
    } else {
        // Encontrou o nó a ser removido

        // Caso 1: nó com um ou nenhum filho
        if (root->left == NULL) {
            node * temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node * temp = root->left;
            free(root);
            return temp;
        }

        // Caso 2: nó com dois filhos
        node* minValueNode = findMinValueNode(root->right);
        root->key = minValueNode->key;
        root->right = removeNode(root->right, minValueNode->key);
    }

    // Atualize a altura do nó atual
    updateHeight(root);

    // Verifique o fator de balanceamento e execute as rotações necessárias
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (getBalanceFactor(root->left) >= 0) {
            // Caso LL, execute uma rotação à direita
            return singleRightRotation(root);
        } else {
            // Caso LR, execute uma rotação à esquerda seguida de uma rotação à direita
            root->left = singleLeftRotation(root->left);
            return singleRightRotation(root);
        }
    } else if (balanceFactor < -1) {
        if (getBalanceFactor(root->right) <= 0) {
            // Caso RR, execute uma rotação à esquerda
            return singleLeftRotation(root);
        } else {
            // Caso RL, execute uma rotação à direita seguida de uma rotação à esquerda
            root->right = singleRightRotation(root->right);
            return singleLeftRotation(root);
        }
    }

    return root;
}


node * singleLeftRotation(node * fnode){
    node * ptu;
    ptu = fnode->right;
    fnode->right = ptu->left;
    ptu->left = fnode;
    fnode->factor = 0;
    fnode = ptu;
    return fnode;
}
node * singleRightRotation(node * fnode){
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
void printNode(node * fnode){
    printf("[K:%d - F:%d] - A[%d] ", fnode->key, fnode->factor, fnode->height);
}
void preOrdePrintTree(node * root){
    if (root != NULL) {
        printNode(root);
        //printf("[%d] ", root->key);
        preOrdePrintTree(root->left);
        preOrdePrintTree(root->right);
    }
}
void inOrderPrintTree(node * root){
    if (root != NULL) {
        inOrderPrintTree(root->left);
        printNode(root);
        //printf("[%d] ", root->key);
        inOrderPrintTree(root->right);
    }
}
void postOrdePrintTree(node * root){
    if (root != NULL) {
        postOrdePrintTree(root->left);
        postOrdePrintTree(root->right);
        printNode(root);
        //printf("[%d] ", root->key);
    }
}

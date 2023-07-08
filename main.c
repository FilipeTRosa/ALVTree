#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"



int main(){

    desc_avl * AVLtree = NULL;
    node * root = NULL;
    int menu, printMenu, key;

    printf("\nSetando TAD AVL\n");
    do
    {
        printf("\nMenu Principal\n");
        printf("[1] - Criar arvore.\n");
        printf("[2] - Inserir no na arvore.\n");
        printf("[3] - Imprimir arvore.\n");
        printf("[6] - Sair.\n");
        //setbuf(stdin(NULL));
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            AVLtree = createAVL();
            break;
        case 2:
            printf("Digite o valor que gostaria de inserir.\n");
            scanf("%d", &key);
            AVLtree->root = insertAvl(AVLtree->root, key);
            AVLtree->height++;
            break;
        case 3:
           
            printf("\n PRE ORDER: \n");
            preOrdePrintTree(AVLtree->root);
            printf("\n IN ORDER: \n");
            inOrderPrintTree(AVLtree->root);
            printf("\n POST ORDER: \n");
            postOrdePrintTree(AVLtree->root);
          
            break;
        default:
            break;
        }
    } while (menu < 6); // Fim MENU PRINCIPAL



    return 0;
}
typedef struct node {

    struct node * father;
    int key;
    struct node * left;
    struct node * right;
    int factor;
    int balance;

}node;

typedef struct desc_avl{

    struct node * root;
    int leght;

}desc_avl;


node * createNodo();
desc_avl * createAVL();
node * removeAvl(desc_avl * favl, int key);
desc_avl * insertAvl(desc_avl * favl, int key);
node * simpleLeftRotation(node * fnode);
node * simpleRightRotation(node * fnode);
node * doubleLeftRotation(node * fnode);
node * doubleRightRotation(node * fnode);
void printNode(node * fnode);
void preOrdePrintTree(node * root);
void inOrderPrintTree(node * root);
void preOrdePrintTree(node * root);
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
    int height;

}desc_avl;


node * createNode(int key);
desc_avl * createAVL();
node * removeAvl(node * root, int key);
node * insertAvl(node * root, int key);
node * simpleLeftRotation(node * fnode);
node * simpleRightRotation(node * fnode);
node * doubleLeftRotation(node * fnode);
node * doubleRightRotation(node * fnode);
void printNode(node * fnode);
void preOrdePrintTree(node * root);
void inOrderPrintTree(node * root);
void postOrdePrintTree(node * root);
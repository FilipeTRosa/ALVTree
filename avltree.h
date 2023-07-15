typedef struct node {

    struct node * father;
    int key;
    struct node * left;
    struct node * right;
    int factor;
    int balance;
    int height;

}node;

typedef struct desc_avl{

    struct node * root;
    int height;

}desc_avl;


node * createNode(int key);
desc_avl * createAVL();
int getHeight(node * node);
int getBalanceFactor(node * node);
void updateHeight(node * node);
node * removeAvl(node * root, int key);
node * insertAvl(node * root, int key);
node * findMinValueNode(node * fnode);
node * removeNode(node * root, int value);
node * singleLeftRotation(node * fnode);
node * singleRightRotation(node * fnode);
node * doubleLeftRotation(node * fnode);
node * doubleRightRotation(node * fnode);
void printNode(node * fnode);
void preOrdePrintTree(node * root);
void inOrderPrintTree(node * root);
void postOrdePrintTree(node * root);
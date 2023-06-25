typedef struct node {

    struct nodo * father;
    int key;
    struct nodo * left;
    struct nodo * right;
    int factor;
    int balance;

}node;

typedef struct desc_avl{

    struct nodo * raiz;
    int tamanho;

}desc_avl;


node * createNodo();
desc_avl * createAVL();
node * removeAvl(desc_avl * favl, int key);
desc_avl * insertAvl(desc_avl * favl, int key);

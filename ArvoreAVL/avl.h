
#include<stdio.h>
#include<stdlib.h>
extern int comparacaoAVL=0;
struct Node
{
    char key[21];
    int cont;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a, int b);
int height(struct Node *N);
int max(int a, int b);
struct Node* newNode(char key[]);
struct Node *rightRotate(struct Node *y);
struct Node *leftRotate(struct Node *x);
int getBalance(struct Node *N);
struct Node* insert(struct Node* node, char key[]);
void preOrder(struct Node *root);
void emOrdem_ArvAVL(struct Node *root);
void libera_ArvAVL(struct Node* root);

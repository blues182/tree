// Binary Tree traversals: preorder, inorder, postorder
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

Node* createNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(1); }
    n->value = v;
    n->left = n->right = NULL;
    return n;
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->right = createNode(20); // ya son 6 nodos

    printf("Pre-order:  ");
    preorder(root);
    printf("\n");

    printf("In-order:   ");
    inorder(root);
    printf("\n");

    printf("Post-order: ");
    postorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}

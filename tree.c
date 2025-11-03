
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

Node* createNode(int v){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){ perror("malloc"); exit(1); }
    n->value = v; n->left = n->right = NULL;
    return n;
}


Node* insert(Node* root, int v){
    if(!root) return createNode(v);
    if(v < root->value)  root->left  = insert(root->left, v);
    else                 root->right = insert(root->right, v);
    return root;
}


void preorder(Node* r){ if(!r) return; printf("%d ", r->value); preorder(r->left); preorder(r->right); }
void inorder (Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->value); inorder(r->right); }
void postorder(Node* r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->value); }

void freeTree(Node* r){ if(!r) return; freeTree(r->left); freeTree(r->right); free(r); }

int main(void){
    
    int valores[] = {10, 5, 15, 2, 7, 12, 20};
    int n = sizeof(valores)/sizeof(valores[0]);

    Node* root = NULL;
    for(int i = 0; i < n; ++i) root = insert(root, valores[i]);

 
    printf("Pre-order:  "); preorder(root);  printf("\n");
    printf("In-order:   "); inorder(root);   printf("\n");
    printf("Post-order: "); postorder(root); printf("\n");

    freeTree(root);
    return 0;
}

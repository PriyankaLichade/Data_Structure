#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* root = NULL;

Node* newNode(int x) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* r, int x) {
    if (r == NULL) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}

void inorder(Node* r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void printRange(Node* r, int L, int R) {
    if (!r) return;

    if (L < r->data)
        printRange(r->left, L, R);

    if (r->data >= L && r->data <= R)
        printf("%d ", r->data);

    if (R > r->data)
        printRange(r->right, L, R);
}

int main() {
    int ch, val, L, R;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Display\n");
        printf("3. Print Nodes in Range\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter range L and R: ");
                scanf("%d %d", &L, &R);
                printf("Values in range [%d, %d]: ", L, R);
                printRange(root, L, R);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

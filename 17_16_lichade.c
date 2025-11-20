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

    if (x < r->data)
        r->left = insert(r->left, x);
    else if (x > r->data)
        r->right = insert(r->right, x);

    return r;
}

void inorder(Node* r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

int findMin(Node* r) {
    if (!r) return -1;
    while (r->left) r = r->left;
    return r->data;
}

int findMax(Node* r) {
    if (!r) return -1;
    while (r->right) r = r->right;
    return r->data;
}

int main() {
    int ch, val;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert Node\n");
        printf("2. Display Inorder\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                val = findMin(root);
                if (val == -1) printf("Tree is empty\n");
                else printf("Minimum = %d\n", val);
                break;

            case 4:
                val = findMax(root);
                if (val == -1) printf("Tree is empty\n");
                else printf("Maximum = %d\n", val);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* root = NULL;

Node* makeNode(int x) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* r, int x) {
    if (r == NULL) return makeNode(x);
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

void preorder(Node* r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(Node* r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

typedef struct queue {
    Node* arr[100];
    int front, rear;
} Queue;

void initQ(Queue* q) { q->front = q->rear = -1; }
int empty(Queue* q) { return q->front == -1; }

void enqueue(Queue* q, Node* x) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = x;
}

Node* dequeue(Queue* q) {
    if (empty(q)) return NULL;
    Node* t = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return t;
}

void bfs(Node* r) {
    if (!r) return;
    Queue q;
    initQ(&q);
    enqueue(&q, r);

    while (!empty(&q)) {
        Node* t = dequeue(&q);
        printf("%d ", t->data);
        if (t->left) enqueue(&q, t->left);
        if (t->right) enqueue(&q, t->right);
    }
}

void dfs(Node* r) {
    preorder(r);
}

Node* mirror(Node* r) {
    if (r == NULL) return r;
    Node* temp = r->left;
    r->left = r->right;
    r->right = temp;
    mirror(r->left);
    mirror(r->right);
    return r;
}

Node* parent(Node* r, int x) {
    if (!r) return NULL;
    if ((r->left && r->left->data == x) ||
        (r->right && r->right->data == x))
        return r;
    if (x < r->data) return parent(r->left, x);
    else return parent(r->right, x);
}

void children(Node* r, int x) {
    if (!r) return;
    if (r->data == x) {
        printf("Left Child: ");
        if (r->left) printf("%d", r->left->data);
        else printf("None");

        printf("\nRight Child: ");
        if (r->right) printf("%d", r->right->data);
        else printf("None");
        return;
    }
    if (x < r->data) children(r->left, x);
    else children(r->right, x);
}

void sibling(int x) {
    Node* p = parent(root, x);
    if (!p) { printf("No parent → no sibling\n"); return; }

    if (p->left && p->left->data == x) {
        if (p->right) printf("Sibling = %d\n", p->right->data);
        else printf("No sibling\n");
    }
    else {
        if (p->left) printf("Sibling = %d\n", p->left->data);
        else printf("No sibling\n");
    }
}

void grandParent(int x) {
    Node* p = parent(root, x);
    if (!p) { printf("No parent\n"); return; }
    Node* gp = parent(root, p->data);
    if (!gp) printf("No grandparent\n");
    else printf("Grandparent = %d\n", gp->data);
}

void uncle(int x) {
    Node* p = parent(root, x);
    if (!p) { printf("No parent\n"); return; }

    Node* gp = parent(root, p->data);
    if (!gp) { printf("No grandparent → no uncle\n"); return; }

    if (gp->left && gp->left->data == p->data) {
        if (gp->right) printf("Uncle = %d\n", gp->right->data);
        else printf("No uncle\n");
    } else {
        if (gp->left) printf("Uncle = %d\n", gp->left->data);
        else printf("No uncle\n");
    }
}

// Main menu
int main() {
    int ch, x;

    while (1) {
        printf("\n---- BST MENU ----\n");
        printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.BFS\n6.DFS\n");
        printf("7.Mirror Tree\n8.Children\n9.Parent\n10.Sibling\n11.Grandparent\n12.Uncle\n13.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: 
                printf("Enter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2: inorder(root); break;
            case 3: preorder(root); break;
            case 4: postorder(root); break;
            case 5: bfs(root); break;
            case 6: dfs(root); break;

            case 7: root = mirror(root); printf("Mirror created\n"); break;

            case 8: 
                printf("Enter node: ");
                scanf("%d", &x);
                children(root, x);
                break;

            case 9:
                printf("Enter node: ");
                scanf("%d", &x);
                Node* p = parent(root, x);
                if (p) printf("Parent = %d\n", p->data);
                else printf("No parent\n");
                break;

            case 10: 
                printf("Enter node: ");
                scanf("%d", &x);
                sibling(x);
                break;

            case 11:
                printf("Enter node: ");
                scanf("%d", &x);
                grandParent(x);
                break;

            case 12:
                printf("Enter node: ");
                scanf("%d", &x);
                uncle(x);
                break;

            case 13: exit(0);

            default: printf("Invalid choice\n");
        }
    }
}

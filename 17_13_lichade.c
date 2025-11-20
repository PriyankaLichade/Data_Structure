#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* head = NULL;

Node* createNode(int x) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->prev = t->next = NULL;
    return t;
}

void insertBeg(int x) {
    Node* t = createNode(x);
    if (head != NULL) {
        t->next = head;
        head->prev = t;
    }
    head = t;
}

void insertEnd(int x) {
    Node* t = createNode(x);
    if (head == NULL) {
        head = t; 
        return;
    }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = t;
    t->prev = p;
}

void insertPos(int x, int pos) {
    if (pos == 1) { insertBeg(x); return; }

    Node* p = head;
    for (int i = 1; p && i < pos - 1; i++) p = p->next;

    if (!p) { printf("Invalid Position\n"); return; }

    Node* t = createNode(x);
    t->next = p->next;
    t->prev = p;

    if (p->next) p->next->prev = t;
    p->next = t;
}

void deleteBeg() {
    if (!head) { printf("List Empty\n"); return; }

    Node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(t);
}

void deleteEnd() {
    if (!head) { printf("List Empty\n"); return; }

    Node* p = head;
    if (!p->next) { head = NULL; free(p); return; }

    while (p->next) p = p->next;
    p->prev->next = NULL;
    free(p);
}

void deletePos(int pos) {
    if (!head) { printf("Empty\n"); return; }

    if (pos == 1) { deleteBeg(); return; }

    Node* p = head;
    for (int i = 1; p && i < pos; i++) p = p->next;

    if (!p) { printf("Invalid Position\n"); return; }

    if (p->next) p->next->prev = p->prev;
    if (p->prev) p->prev->next = p->next;
    free(p);
}

void display() {
    Node* p = head;
    if (!p) { printf("List Empty\n"); return; }
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void reverseList() {
    Node *curr = head, *temp = NULL;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) head = temp->prev;
}

void middleNode() {
    if (!head) { printf("Empty\n"); return; }

    Node *s = head, *f = head;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    printf("Middle = %d\n", s->data);
}

void sortDLL() {
    if (!head) return;

    Node* p = head;
    while (p) {
        Node* q = p->next;
        while (q) {
            if (p->data > q->data) {
                int t = p->data;
                p->data = q->data;
                q->data = t;
            }
            q = q->next;
        }
        p = p->next;
    }
    printf("List Sorted\n");
}

void detectLoop() {
    Node *s = head, *f = head;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
        if (s == f) {
            printf("Loop Found\n");
            return;
        }
    }
    printf("No Loop\n");
}

void sumList() {
    int sum = 0;
    Node* p = head;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    printf("Sum = %d\n", sum);
}

void printOddEven() {
    Node* p = head;
    printf("Odd: ");
    while (p) {
        if (p->data % 2 != 0) printf("%d ", p->data);
        p = p->next;
    }
    printf("\nEven: ");
    p = head;
    while (p) {
        if (p->data % 2 == 0) printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Node* mergeDLL(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node* p = h1;
    while (p->next) p = p->next;
    p->next = h2;
    h2->prev = p;

    return h1;
}

int main() {
    int choice, val, pos;
    Node *list1 = NULL, *list2 = NULL;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1.Insert Beg\n2.Insert End\n3.Insert Pos\n4.Delete Beg\n5.Delete End\n6.Delete Pos\n");
        printf("7.Display\n8.Reverse\n9.Middle\n10.Sort\n11.Loop Check\n12.Sum\n13.Print Odd/Even\n");
        printf("14.Merge Two Lists\n15.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: printf("Value: "); scanf("%d", &val); insertBeg(val); break;
        case 2: printf("Value: "); scanf("%d", &val); insertEnd(val); break;
        case 3: printf("Value & Position: "); scanf("%d%d", &val, &pos); insertPos(val,pos); break;
        case 4: deleteBeg(); break;
        case 5: deleteEnd(); break;
        case 6: printf("Position: "); scanf("%d",&pos); deletePos(pos); break;
        case 7: display(); break;
        case 8: reverseList(); break;
        case 9: middleNode(); break;
        case 10: sortDLL(); break;
        case 11: detectLoop(); break;
        case 12: sumList(); break;
        case 13: printOddEven(); break;

        case 14:
            printf("Merging two simple lists...\n");
            list1 = head;
            list2 = createNode(100);
            list2->next = createNode(200);
            head = mergeDLL(list1, list2);
            break;

        case 15: exit(0);

        default: printf("Wrong Choice\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int x) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    return t;
}

void insertBeg(int x) {
    struct node *t = createNode(x);
    t->next = head;
    head = t;
}

void insertEnd(int x) {
    struct node *t = createNode(x);
    if (head == NULL) {
        head = t;
        return;
    }
    struct node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = t;
}

void insertPos(int x, int pos) {
    if (pos == 1) {
        insertBeg(x);
        return;
    }
    struct node *t = createNode(x), *p = head;
    for (int i = 1; p != NULL && i < pos-1; i++)
        p = p->next;

    if (p == NULL) {
        printf("Invalid position\n");
        free(t);
        return;
    }

    t->next = p->next;
    p->next = t;
}

void deleteBeg() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct node *t = head;
    head = head->next;
    printf("Deleted: %d\n", t->data);
    free(t);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *p = head, *q = NULL;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    printf("Deleted: %d\n", p->data);
    free(p);
    q->next = NULL;
}

void deletePos(int pos) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (pos == 1) {
        deleteBeg();
        return;
    }
    struct node *p = head, *q = NULL;
    for (int i = 1; p != NULL && i < pos; i++) {
        q = p;
        p = p->next;
    }
    if (p == NULL) {
        printf("Invalid position\n");
        return;
    }
    q->next = p->next;
    printf("Deleted: %d\n", p->data);
    free(p);
}

void display() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct node *p = head;
    printf("List: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void reverse() {
    struct node *prev = NULL, *cur = head, *next;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

struct node* merge(struct node *a, struct node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct node *res = NULL, *tail = NULL;

    while (a && b) {
        struct node *temp;
        if (a->data <= b->data) {
            temp = a;
            a = a->next;
        } else {
            temp = b;
            b = b->next;
        }

        temp->next = NULL;

        if (res == NULL) {
            res = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    if (a) tail->next = a;
    if (b) tail->next = b;

    return res;
}

void findMiddle() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

void sort() {
    if (head == NULL) return;
    struct node *i, *j;
    for (i = head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
}

void detectLoop() {
    struct node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop detected!\n");
            return;
        }
    }
    printf("No loop in list\n");
}

void sumData() {
    int sum = 0;
    struct node *p = head;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    printf("Sum = %d\n", sum);
}

void oddEven() {
    printf("Odd: ");
    struct node *p = head;
    while (p) {
        if (p->data % 2 != 0)
            printf("%d ", p->data);
        p = p->next;
    }
    printf("\nEven: ");
    p = head;
    while (p) {
        if (p->data % 2 == 0)
            printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int choice, val, pos;
    struct node *list2 = NULL;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1.Insert Beg\n2.Insert End\n3.Insert Pos\n");
        printf("4.Delete Beg\n5.Delete End\n6.Delete Pos\n");
        printf("7.Display\n8.Reverse\n9.Find Middle\n10.Sort\n");
        printf("11.Sum of Data\n12.Odd/Even Print\n13.Detect Loop\n14.Merge Another List\n15.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insertBeg(val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(val);
            break;

        case 3:
            printf("Enter value and position: ");
            scanf("%d%d", &val, &pos);
            insertPos(val, pos);
            break;

        case 4:
            deleteBeg(); 
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePos(pos);
            break;

        case 7:
            display();
            break;

        case 8:
            reverse();
            printf("List reversed\n");
            break;

        case 9:
            findMiddle();
            break;

        case 10:
            sort();
            printf("List sorted\n");
            break;

        case 11:
            sumData();
            break;

        case 12:
            oddEven();
            break;

        case 13:
            detectLoop();
            break;

        case 14: {
            list2 = NULL;
            printf("Enter 3 elements for 2nd list: ");
            for (int i = 0; i < 3; i++) {
                scanf("%d", &val);
                struct node *t = createNode(val);

                if (list2 == NULL)
                    list2 = t;
                else {
                    struct node *p = list2;
                    while (p->next != NULL) p = p->next;
                    p->next = t;
                }
            }
            head = merge(head, list2);
            printf("Lists merged.\n");
            break;
        }

        case 15:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}

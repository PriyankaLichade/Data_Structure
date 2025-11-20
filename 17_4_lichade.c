#include <stdio.h>
#define SIZE 10


int data[SIZE];

int f1 = -1, r1 = -1;


int f2 = SIZE, r2 = SIZE;


void pushQ1(int val) {
    if (r1 + 1 == r2) {
        printf("Queue 1 is full. No free space.\n");
        return;
    }

    if (f1 == -1)        
        f1 = 0;

    data[++r1] = val;
    printf("%d added to Queue 1.\n", val);
}


void pushQ2(int val) {
    if (r1 + 1 == r2) {
        printf("Queue 2 is full. No free space.\n");
        return;
    }

    if (f2 == SIZE)    
        f2 = SIZE - 1;

    data[--r2] = val;
    printf("%d added to Queue 2.\n", val);
}


void popQ1() {
    if (f1 == -1 || f1 > r1) {
        printf("Queue 1 is empty.\n");
        f1 = r1 = -1;
        return;
    }

    printf("%d removed from Queue 1.\n", data[f1]);
    f1++;
}

void popQ2() {
    if (f2 == SIZE || f2 < r2) {
        printf("Queue 2 is empty.\n");
        f2 = r2 = SIZE;
        return;
    }

    printf("%d removed from Queue 2.\n", data[f2]);
    f2--;
}

void showQ1() {
    if (f1 == -1 || f1 > r1) {
        printf("Queue 1 is empty.\n");
        return;
    }

    printf("Queue 1 elements: ");
    for (int i = f1; i <= r1; i++)
        printf("%d ", data[i]);
    printf("\n");
}

void showQ2() {
    if (f2 == SIZE || f2 < r2) {
        printf("Queue 2 is empty.\n");
        return;
    }

    printf("Queue 2 elements: ");
    for (int i = f2; i >= r2; i--)
        printf("%d ", data[i]);
    printf("\n");
}

int main() {
    int option, value;

    while (1) {
        printf("\n=== Two Queue Menu ===\n");
        printf("1. Enqueue in Q1\n");
        printf("2. Dequeue from Q1\n");
        printf("3. Display Q1\n");
        printf("4. Enqueue in Q2\n");
        printf("5. Dequeue from Q2\n");
        printf("6. Display Q2\n");
        printf("7. Exit\n");

        printf("Choose: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                pushQ1(value);
                break;

            case 2:
                popQ1();
                break;

            case 3:
                showQ1();
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                pushQ2(value);
                break;

            case 5:
                popQ2();
                break;

            case 6:
                showQ2();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid selection. Try again.\n");
        }
    }
}

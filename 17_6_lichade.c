#include <stdio.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        return -1;
    } 
    return stack[top--];
}

void decToBinary(int num) {
    int n = num;

    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    top = -1; 

    while (n > 0) {
        push(n % 2);
        n = n / 2;
    }

    printf("Binary: ");
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int choice, n;

    while (1) {
        printf("\n--- Decimal to Binary Menu ---\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter decimal number: ");
                scanf("%d", &n);
                decToBinary(n);
                break;

            case 2:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

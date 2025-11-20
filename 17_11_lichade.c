#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1)
        stack[++top] = x;
    else
        printf("Stack full\n");
}

int pop() {
    if (top >= 0)
        return stack[top--];
    else
        return -1;
}

int evaluatePostfix(char exp[]) {
    int i = 0;
    char ch;
    int val1, val2;

    top = -1;  

    while (exp[i] != '\0') {
        ch = exp[i];

        if (isdigit(ch)) {
            push(ch - '0');   
        }
        else {
            val2 = pop();
            val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }

    return pop();
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    char expr[MAX];
    int choice, result;

    while (1) {
        printf("\n--- Arithmetic Expression Evaluation (Postfix) ---\n");
        printf("1. Enter Expression\n");
        printf("2. Evaluate Expression\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", expr);
                break;

            case 2:
                result = evaluatePostfix(expr);
                printf("Result = %d\n", result);
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

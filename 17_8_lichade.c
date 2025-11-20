#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top < MAX - 1)
        stack[++top] = x;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int prec(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
    }
    return 0;
}

void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void swapBrackets(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') expr[i] = ')';
        else if (expr[i] == ')') expr[i] = '(';
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    char temp[MAX];
    int i = 0, k = 0;
    char ch;

    top = -1;

    strcpy(temp, infix);
    reverse(temp);
    swapBrackets(temp);

    while (temp[i] != '\0') {
        ch = temp[i];

        if (isalnum(ch)) {
            prefix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                prefix[k++] = pop();
            pop();
        }
        else {
            while (top != -1 && prec(stack[top]) > prec(ch))
                prefix[k++] = pop();
            push(ch);
        }
        i++;
    }

    while (top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';

    reverse(prefix);  
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%c ", stack[i]);
    printf("\n");
}

int main() {
    char infix[MAX], prefix[MAX];
    int choice;

    while (1) {
        printf("\n--- Infix to Prefix Menu ---\n");
        printf("1. Enter Infix Expression\n");
        printf("2. Convert to Prefix\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix: ");
                scanf("%s", infix);
                break;

            case 2:
                infixToPrefix(infix, prefix);
                printf("Prefix: %s\n", prefix);
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

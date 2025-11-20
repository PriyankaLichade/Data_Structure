#include <stdio.h>
#include <string.h>

#define MAX 100

char stackArr[MAX];
int top = -1;

// push character into stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack overflow.\n");
        return;
    }
    stackArr[++top] = ch;
}

// pop character from stack
char pop() {
    if (top == -1)
        return '\0';
    return stackArr[top--];
}

// check matching pair
int matchPair(char a, char b) {
    if (a == '(' && b == ')') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '[' && b == ']') return 1;
    return 0;
}

// function to test balance
void checkExpression(char exp[]) {
    top = -1;   // reset stack before checking

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // opening brackets → push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // closing brackets → must match
        else if (ch == ')' || ch == '}' || ch == ']') {
            char removed = pop();
            if (!matchPair(removed, ch)) {
                printf("Unbalanced expression.\n");
                return;
            }
        }
    }

    // after complete scan
    if (top == -1)
        printf("Expression is balanced.\n");
    else
        printf("Unbalanced expression.\n");
}

// display current stack content
void showStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack content: ");
    for (int i = 0; i <= top; i++)
        printf("%c ", stackArr[i]);
    printf("\n");
}

int main() {
    int choice;
    char inputExp[200];

    while (1) {
        printf("\n--- Parenthesis Checker Menu ---\n");
        printf("1. Enter expression & test\n");
        printf("2. View current stack\n");
        printf("3. Clear stack\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline

        switch (choice) {
            case 1:
                printf("Enter expression: ");
                fgets(inputExp, sizeof(inputExp), stdin);
                inputExp[strcspn(inputExp, "\n")] = '\0';  // remove newline
                checkExpression(inputExp);
                break;

            case 2:
                showStack();
                break;

            case 3:
                top = -1;
                printf("Stack cleared.\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid option. Try again.\n");
        }
    }
}

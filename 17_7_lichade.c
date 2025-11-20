#include <stdio.h>
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

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    top = -1;  

    while (infix[i] != '\0') {
        ch = infix[i];

      
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
       
        else if (ch == '(') {
            push(ch);
        }
        
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); 
        }
       
        else {
            while (top != -1 && prec(stack[top]) >= prec(ch))
                postfix[k++] = pop();
            push(ch);
        }
        i++;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';  
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
    char infix[MAX], postfix[MAX];
    int choice;

    while (1) {
        printf("\n--- Infix to Postfix Menu ---\n");
        printf("1. Enter Infix Expression\n");
        printf("2. Convert to Postfix\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                break;

            case 2:
                infixToPostfix(infix, postfix);
                printf("Postfix: %s\n", postfix);
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

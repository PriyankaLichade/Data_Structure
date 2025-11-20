#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x) {
    if (top1 + 1 == top2) {
        printf("Overflow in Stack1\n");
        return;
    }
    arr[++top1] = x;
    printf("%d pushed to Stack1\n", x);
}

void push2(int x) {
    if (top1 + 1 == top2) {
        printf("Overflow in Stack2\n");
        return;
    }
    arr[--top2] = x;
    printf("%d pushed to Stack2\n", x);
}

void pop1() {
    if (top1 == -1) {
        printf("Underflow in Stack1\n");
    } else {
        printf("%d popped from Stack1\n", arr[top1--]);
    }
}

void pop2() {
    if (top2 == MAX) {
        printf("Underflow in Stack2\n");
    } else {
        printf("%d popped from Stack2\n", arr[top2++]);
    }
}

int main() {
    push1(10);
    push1(20);
    push2(40);
    push2(50);
    pop1();
    pop2();
    return 0;
}

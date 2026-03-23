/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if(*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    scanf("%s", exp);

    struct Node* top = NULL;

    for(int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if(isdigit(ch)) {
            push(&top, ch - '0');
        } else {
            int val2 = pop(&top);
            int val1 = pop(&top);
            int res;

            if(ch == '+') res = val1 + val2;
            else if(ch == '-') res = val1 - val2;
            else if(ch == '*') res = val1 * val2;
            else if(ch == '/') res = val1 / val2;

            push(&top, res);
        }
    }

    printf("%d", pop(&top));

    return 0;
}


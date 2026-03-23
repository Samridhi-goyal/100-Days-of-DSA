/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom*/

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int main() {
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if(top < MAX - 1)
            stack[++top] = x;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(top >= 0)
            top--;
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}

/*Problem Statement:Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty*/

#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    int i = size - 1;
    while(i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    size++;
}

int deleteMin() {
    if(size == 0) return -1;
    int val = pq[0];
    for(int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }
    size--;
    return val;
}

int peek() {
    if(size == 0) return -1;
    return pq[0];
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        } else if(op[0] == 'd') {
            printf("%d\n", deleteMin());
        } else if(op[0] == 'p') {
            printf("%d\n", peek());
        }
    }

    return 0;
}


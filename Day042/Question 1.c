/*Problem Statement: Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue*/

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int n, x, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    while (front <= rear) {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while (top != -1) {
        enqueue(pop());
    }

    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}

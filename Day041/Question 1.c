/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue* q, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if(q->front == NULL) return -1;

    struct Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

int main() {
    int n, x;
    char op[10];
    scanf("%d", &n);

    struct Queue q;
    q.front = q.rear = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%s", op);
        if(strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(&q, x);
        } else if(strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(&q));
        }
    }

    return 0;
}

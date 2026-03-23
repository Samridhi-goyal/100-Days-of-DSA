/*Problem: Deque (Double-Ended Queue)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (front == (rear + 1) % MAX);
}

void push_front(int x) {
    if(isFull()) return;

    if(isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    dq[front] = x;
}

void push_back(int x) {
    if(isFull()) return;

    if(isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    dq[rear] = x;
}

void pop_front() {
    if(isEmpty()) return;

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void pop_back() {
    if(isEmpty()) return;

    if(front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

int getFront() {
    if(isEmpty()) return -1;
    return dq[front];
}

int getBack() {
    if(isEmpty()) return -1;
    return dq[rear];
}

int size() {
    if(isEmpty()) return 0;
    if(rear >= front)
        return rear - front + 1;
    return MAX - front + rear + 1;
}

void display() {
    if(isEmpty()) return;

    int i = front;
    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if(strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if(strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if(strcmp(op, "pop_back") == 0) {
            pop_back();
        } else if(strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        } else if(strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        } else if(strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if(strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } else if(strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}

/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m, x;

    scanf("%d", &n);

    struct Node *front = NULL, *rear = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;

        if(front == NULL) {
            front = rear = newNode;
            newNode->next = front;
        } else {
            newNode->next = front;
            rear->next = newNode;
            rear = newNode;
        }
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(front == NULL) break;

        if(front == rear) {
            free(front);
            front = rear = NULL;
        } else {
            struct Node* temp = front;
            front = front->next;
            rear->next = front;
            free(temp);
        }
    }

    if(front != NULL) {
        struct Node* temp = front;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != front);
    }

    return 0;
}

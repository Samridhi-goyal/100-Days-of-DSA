/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    struct Node *curr = head, *prev = NULL;

    while(curr != NULL) {
        if(curr->data == key) {
            if(prev == NULL)
                head = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

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
    return head;
}

int length(struct Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* l1 = createList(n);

    scanf("%d", &m);
    struct Node* l2 = createList(m);

    int len1 = length(l1);
    int len2 = length(l2);

    struct Node *p1 = l1, *p2 = l2;

    int diff = abs(len1 - len2);

    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            p1 = p1->next;
    } else {
        for(int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    while(p1 != NULL && p2 != NULL) {
        if(p1->data == p2->data) {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}

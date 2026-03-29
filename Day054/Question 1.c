/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void zigzagTraversal(Node* root) {
    if (!root) return;

    Node** currentLevel = (Node**)malloc(1000 * sizeof(Node*));
    Node** nextLevel = (Node**)malloc(1000 * sizeof(Node*));

    int currTop = -1, nextTop = -1;
    int leftToRight = 1;

    currentLevel[++currTop] = root;

    while (currTop >= 0) {
        Node* node = currentLevel[currTop--];
        printf("%d ", node->data);

        if (leftToRight) {
            if (node->left) nextLevel[++nextTop] = node->left;
            if (node->right) nextLevel[++nextTop] = node->right;
        } else {
            if (node->right) nextLevel[++nextTop] = node->right;
            if (node->left) nextLevel[++nextTop] = node->left;
        }

        if (currTop < 0) {
            leftToRight = !leftToRight;

            Node** temp = currentLevel;
            currentLevel = nextLevel;
            nextLevel = temp;

            currTop = nextTop;
            nextTop = -1;
        }
    }

    free(currentLevel);
    free(nextLevel);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}

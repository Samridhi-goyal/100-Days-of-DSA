/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m*/

#include <stdio.h>
#define SIZE 100

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) table[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int h = hash(key);
    int i = 0;
    while (i < SIZE) {
        int idx = (h + i * i) % SIZE;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != -1)
            printf("%d:%d\n", i, table[i]);
    }
}

int main() {
    init();
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }
    display();
    return 0;
}


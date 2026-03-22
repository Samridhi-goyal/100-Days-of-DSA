//Problem: Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int a[100], temp[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    k = k % n;

    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = a[i];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}

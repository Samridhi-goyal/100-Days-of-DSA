/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        int count = 1;
        if(a[i] == -1) continue;

        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
                a[j] = -1;
            }
        }

        printf("%d %d\n", a[i], count);
    }

    return 0;
}

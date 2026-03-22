/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max = a[0], min = a[0];

    for(int i = 1; i < n; i++) {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d", min);

    return 0;
}

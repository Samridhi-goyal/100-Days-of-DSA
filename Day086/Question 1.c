/*Problem: Find the integer square root of a given non-negative integer using Binary Search. 
The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.*/

#include <stdio.h>

int intSqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Avoid overflow: check mid <= n / mid
        if (mid <= n / mid) {
            ans = mid;      // mid is a possible answer
            low = mid + 1;  // try to find bigger value
        } else {
            high = mid - 1; // reduce search space
        }
    }

    return ans;
}

int main() {
    int n;
    printf("Enter a non-negative number: ");
    scanf("%d", &n);

    printf("Integer square root = %d\n", intSqrt(n));

    return 0;
}

/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students,
allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
Books must be allocated in contiguous order.*/

#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0; // single book exceeds limit

        if (currentSum + arr[i] > maxPages) {
            students++;          // allocate to next student
            currentSum = arr[i];

            if (students > m)
                return 0;
        } else {
            currentSum += arr[i];
        }
    }

    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n)
        return -1;

    int low = arr[0], high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;        // valid allocation
            high = mid - 1;   // try smaller max pages
        } else {
            low = mid + 1;    // increase limit
        }
    }

    return ans;
}

int main() {
    int n, m;

    printf("Enter number of books: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter pages in books:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number of students: ");
    scanf("%d", &m);

    int result = allocateBooks(arr, n, m);

    printf("Minimum maximum pages = %d\n", result);

    return 0;
}

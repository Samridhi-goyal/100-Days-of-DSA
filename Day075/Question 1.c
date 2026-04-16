/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple structure for hashmap
typedef struct {
    int sum;
    int index;
} Hash;

int main() {
    int n;
    int arr[MAX];

    printf("Enter size: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Hash hash[MAX];
    int hashSize = 0;

    int sum = 0, maxLen = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if(sum == 0) {
            maxLen = i + 1;
        }

        // Check if sum already exists
        int found = 0;
        for(int j = 0; j < hashSize; j++) {
            if(hash[j].sum == sum) {
                int len = i - hash[j].index;
                if(len > maxLen) {
                    maxLen = len;
                }
                found = 1;
                break;
            }
        }

        // Store sum if not found
        if(!found) {
            hash[hashSize].sum = sum;
            hash[hashSize].index = i;
            hashSize++;
        }
    }

    printf("Length of longest subarray with sum 0: %d\n", maxLen);

    return 0;
}



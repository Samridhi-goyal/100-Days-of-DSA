//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

#include <stdlib.h>

typedef struct {
    int val;
    int freq;
} Pair;

int cmp(const void* a, const void* b) {
    return ((Pair*)b)->freq - ((Pair*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    Pair* arr = (Pair*)malloc(sizeof(Pair) * numsSize);
    int size = 0;

    for(int i = 0; i < numsSize; i++) {
        int found = 0;
        for(int j = 0; j < size; j++) {
            if(arr[j].val == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }
        if(!found) {
            arr[size].val = nums[i];
            arr[size].freq = 1;
            size++;
        }
    }

    qsort(arr, size, sizeof(Pair), cmp);

    int* result = (int*)malloc(sizeof(int) * k);
    for(int i = 0; i < k; i++) {
        result[i] = arr[i].val;
    }

    *returnSize = k;
    free(arr);
    return result;
}

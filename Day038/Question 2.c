/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.*/

#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if(numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int* dq = (int*)malloc(sizeof(int) * numsSize);

    int front = 0, rear = 0;
    int idx = 0;

    for(int i = 0; i < numsSize; i++) {
        if(front < rear && dq[front] <= i - k)
            front++;

        while(front < rear && nums[dq[rear - 1]] < nums[i])
            rear--;

        dq[rear++] = i;

        if(i >= k - 1)
            result[idx++] = nums[dq[front]];
    }

    *returnSize = idx;
    free(dq);
    return result;
}

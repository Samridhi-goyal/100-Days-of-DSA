/*You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time.
This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously 
returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.*/

#include <stdlib.h>

typedef struct {
    int* heap;
    int size;
    int capacity;
    int k;
} KthLargest;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(KthLargest* obj, int i) {
    while(i > 0) {
        int p = (i - 1) / 2;
        if(obj->heap[p] > obj->heap[i]) {
            swap(&obj->heap[p], &obj->heap[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(KthLargest* obj, int i) {
    while(1) {
        int l = 2*i + 1, r = 2*i + 2, smallest = i;

        if(l < obj->size && obj->heap[l] < obj->heap[smallest]) smallest = l;
        if(r < obj->size && obj->heap[r] < obj->heap[smallest]) smallest = r;

        if(smallest != i) {
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        } else break;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;
    obj->k = k;

    for(int i = 0; i < numsSize; i++) {
        if(obj->size < k) {
            obj->heap[obj->size++] = nums[i];
            heapifyUp(obj, obj->size - 1);
        } else if(nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if(obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    } else if(val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.*/

#include <stdlib.h>

#define CAP 200000

typedef struct {
    int *maxHeap;
    int *minHeap;
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int *heap, int idx) {
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (heap[p] >= heap[idx]) break;
        swap(&heap[p], &heap[idx]);
        idx = p;
    }
}

void maxHeapifyDown(int *heap, int size, int idx) {
    while (1) {
        int l = 2 * idx + 1, r = 2 * idx + 2, largest = idx;
        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest == idx) break;
        swap(&heap[idx], &heap[largest]);
        idx = largest;
    }
}

void minHeapifyUp(int *heap, int idx) {
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (heap[p] <= heap[idx]) break;
        swap(&heap[p], &heap[idx]);
        idx = p;
    }
}

void minHeapifyDown(int *heap, int size, int idx) {
    while (1) {
        int l = 2 * idx + 1, r = 2 * idx + 2, smallest = idx;
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        if (smallest == idx) break;
        swap(&heap[idx], &heap[smallest]);
        idx = smallest;
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = malloc(sizeof(MedianFinder));
    obj->maxHeap = malloc(CAP * sizeof(int));
    obj->minHeap = malloc(CAP * sizeof(int));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        obj->maxHeap[obj->maxSize++] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    } else {
        obj->minHeap[obj->minSize++] = num;
        minHeapifyUp(obj->minHeap, obj->minSize - 1);
    }

    if (obj->maxSize > obj->minSize + 1) {
        int val = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);
        obj->minHeap[obj->minSize++] = val;
        minHeapifyUp(obj->minHeap, obj->minSize - 1);
    } else if (obj->minSize > obj->maxSize) {
        int val = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);
        obj->maxHeap[obj->maxSize++] = val;
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) return obj->maxHeap[0];
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}

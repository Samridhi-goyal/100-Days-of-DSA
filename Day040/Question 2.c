/*Given an array of integers temperatures represents the daily temperatures, 
  return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.*/

#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * temperaturesSize);
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    for(int i = 0; i < temperaturesSize; i++) {
        result[i] = 0;
    }

    for(int i = 0; i < temperaturesSize; i++) {
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            result[idx] = i - idx;
        }
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    free(stack);
    return result;
}

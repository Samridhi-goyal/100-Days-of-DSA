//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

#include <stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int n, int* colSize, int* returnSize, int** returnColumnSizes){
    qsort(intervals, n, sizeof(int*), cmp);

    int **res = (int**)malloc(n*sizeof(int*));
    *returnColumnSizes = (int*)malloc(n*sizeof(int));

    int idx=0;

    res[idx] = (int*)malloc(2*sizeof(int));
    res[idx][0] = intervals[0][0];
    res[idx][1] = intervals[0][1];
    (*returnColumnSizes)[idx]=2;

    for(int i=1;i<n;i++){
        if(intervals[i][0] <= res[idx][1]){
            if(intervals[i][1] > res[idx][1])
                res[idx][1] = intervals[i][1];
        } else{
            idx++;
            res[idx] = (int*)malloc(2*sizeof(int));
            res[idx][0] = intervals[i][0];
            res[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx]=2;
        }
    }

    *returnSize = idx+1;
    return res;
}

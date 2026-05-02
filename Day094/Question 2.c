/*Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.*/

#include <stdlib.h>

int* relativeSortArray(int* arr1, int n, int* arr2, int m, int* returnSize){
    int count[1001]={0};

    for(int i=0;i<n;i++) count[arr1[i]]++;

    int *res = (int*)malloc(n*sizeof(int));
    int idx=0;

    for(int i=0;i<m;i++){
        while(count[arr2[i]]-- > 0){
            res[idx++] = arr2[i];
        }
    }

    for(int i=0;i<=1000;i++){
        while(count[i]-- > 0){
            res[idx++] = i;
        }
    }

    *returnSize = n;
    return res;
}

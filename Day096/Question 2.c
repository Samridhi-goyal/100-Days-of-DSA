/*Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].*/
 
#include <stdlib.h>

long long merge(int a[], int l, int m, int r){
    long long count = 0;

    int j = m + 1;
    for(int i = l; i <= m; i++){
        while(j <= r && (long long)a[i] > 2LL * a[j]) j++;
        count += (j - (m + 1));
    }

    int i=l, k=0;
    j = m+1;
    int temp[r-l+1];

    while(i<=m && j<=r){
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }

    while(i<=m) temp[k++] = a[i++];
    while(j<=r) temp[k++] = a[j++];

    for(i=l,k=0;i<=r;i++,k++) a[i]=temp[k];

    return count;
}

long long mergeSort(int a[], int l, int r){
    long long count = 0;
    if(l < r){
        int m = (l + r) / 2;
        count += mergeSort(a, l, m);
        count += mergeSort(a, m+1, r);
        count += merge(a, l, m, r);
    }
    return count;
}

int reversePairs(int* nums, int numsSize){
    return (int)mergeSort(nums, 0, numsSize-1);
}


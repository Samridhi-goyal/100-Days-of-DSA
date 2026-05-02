//Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

#include <stdlib.h>

typedef struct{
    int val, idx;
}Node;

void merge(Node a[], int l, int m, int r, int count[]){
    int i=l, j=m+1, k=0;
    Node temp[r-l+1];

    while(i<=m && j<=r){
        if(a[i].val <= a[j].val){
            count[a[i].idx] += (j - (m + 1));
            temp[k++] = a[i++];
        } else{
            temp[k++] = a[j++];
        }
    }

    while(i<=m){
        count[a[i].idx] += (j - (m + 1));
        temp[k++] = a[i++];
    }

    while(j<=r){
        temp[k++] = a[j++];
    }

    for(i=l,k=0;i<=r;i++,k++) a[i]=temp[k];
}

void mergeSort(Node a[], int l, int r, int count[]){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m,count);
        mergeSort(a,m+1,r,count);
        merge(a,l,m,r,count);
    }
}

int* countSmaller(int* nums, int n, int* returnSize){
    Node a[n];
    int *count = (int*)calloc(n,sizeof(int));

    for(int i=0;i<n;i++){
        a[i].val = nums[i];
        a[i].idx = i;
    }

    mergeSort(a,0,n-1,count);

    *returnSize = n;
    return count;
}

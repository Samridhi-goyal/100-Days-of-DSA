/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val, idx;
}Node;

void merge(Node a[], int l, int m, int r, int count[]){
    int i=l,j=m+1,k=0;
    Node temp[r-l+1];

    while(i<=m && j<=r){
        if(a[i].val <= a[j].val){
            count[a[i].idx] += (j - (m+1));
            temp[k++] = a[i++];
        } else{
            temp[k++] = a[j++];
        }
    }

    while(i<=m){
        count[a[i].idx] += (j - (m+1));
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

int main(){
    int arr[]={5,2,6,1};
    int n=4;

    Node a[n];
    int count[n];

    for(int i=0;i<n;i++){
        a[i].val=arr[i];
        a[i].idx=i;
        count[i]=0;
    }

    mergeSort(a,0,n-1,count);

    for(int i=0;i<n;i++) printf("%d ",count[i]);
    return 0;
}

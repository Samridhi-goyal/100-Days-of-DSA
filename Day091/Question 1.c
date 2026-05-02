/*Problem: Implement merge sort (divide, sort halves, merge).
Print sorted array.*/

#include <stdio.h>

void merge(int a[], int l, int m, int r){
    int i=l,j=m+1,k=0,b[100];
    while(i<=m && j<=r){
        if(a[i]<a[j]) b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=m) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(i=l,k=0;i<=r;i++,k++) a[i]=b[k];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int a[]={38,27,43,3,9,82,10};
    int n=7;
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}

//Problem: Count number of inversions using modified merge sort. Inversion if i < j and a[i] > a[j].

#include <stdio.h>

long long merge(int a[], int l, int m, int r){
    int i=l,j=m+1,k=0;
    int b[100000];
    long long inv=0;

    while(i<=m && j<=r){
        if(a[i]<=a[j]) b[k++]=a[i++];
        else{
            b[k++]=a[j++];
            inv += (m - i + 1);
        }
    }

    while(i<=m) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++) a[i]=b[k];

    return inv;
}

long long mergeSort(int a[], int l, int r){
    long long inv=0;
    if(l<r){
        int m=(l+r)/2;
        inv += mergeSort(a,l,m);
        inv += mergeSort(a,m+1,r);
        inv += merge(a,l,m,r);
    }
    return inv;
}

int main(){
    int a[]={2,4,1,3,5};
    int n=5;
    long long inv = mergeSort(a,0,n-1);
    printf("%lld",inv);
    return 0;
}

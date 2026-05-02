//Problem: Sort array of non-negative integers using counting sort. Find max, build freq array, compute prefix sums, build output.

#include <stdio.h>

void countingSort(int a[], int n){
    int max=a[0];
    for(int i=1;i<n;i++) if(a[i]>max) max=a[i];

    int count[max+1];
    for(int i=0;i<=max;i++) count[i]=0;

    for(int i=0;i<n;i++) count[a[i]]++;

    for(int i=1;i<=max;i++) count[i]+=count[i-1];

    int output[n];
    for(int i=n-1;i>=0;i--){
        output[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }

    for(int i=0;i<n;i++) a[i]=output[i];
}

int main(){
    int a[]={4,2,2,8,3,3,1};
    int n=7;
    countingSort(a,n);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}

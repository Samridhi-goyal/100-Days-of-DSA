//Problem: Given n real numbers in [0,1), sort using bucket sort algorithm. Distribute into buckets, sort each, concatenate.

#include <stdio.h>

void bucketSort(float a[], int n){
    float bucket[n][n];
    int count[n];

    for(int i=0;i<n;i++) count[i]=0;

    for(int i=0;i<n;i++){
        int bi = n * a[i];
        bucket[bi][count[bi]++] = a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<count[i];j++){
            float key = bucket[i][j];
            int k = j-1;
            while(k>=0 && bucket[i][k] > key){
                bucket[i][k+1] = bucket[i][k];
                k--;
            }
            bucket[i][k+1] = key;
        }
    }

    int idx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<count[i];j++){
            a[idx++] = bucket[i][j];
        }
    }
}

int main(){
    float a[]={0.42,0.32,0.33,0.52,0.37,0.47,0.51};
    int n=7;
    bucketSort(a,n);
    for(int i=0;i<n;i++) printf("%.2f ",a[i]);
    return 0;
}

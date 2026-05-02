/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.*/

#include <stdio.h>

int max(int a,int b){return a>b?a:b;}

int sum(int arr[],int n){
    int s=0;
    for(int i=0;i<n;i++) s+=arr[i];
    return s;
}

int isPossible(int arr[],int n,int k,int mid){
    int painters=1, curr=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) return 0;
        if(curr+arr[i]>mid){
            painters++;
            curr=arr[i];
            if(painters>k) return 0;
        } else curr+=arr[i];
    }
    return 1;
}

int paintersPartition(int arr[],int n,int k){
    int low=0, high=sum(arr,n), ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(arr,n,k,mid)){
            ans=mid;
            high=mid-1;
        } else low=mid+1;
    }
    return ans;
}

int main(){
    int arr[]={10,20,30,40};
    int n=4,k=2;
    printf("%d",paintersPartition(arr,n,k));
    return 0;
}

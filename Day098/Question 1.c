//Problem: Given intervals, merge all overlapping ones. Sort first, then compare with previous.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int start,end;
}Interval;

int cmp(const void *a,const void *b){
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void mergeIntervals(Interval arr[],int n){
    qsort(arr,n,sizeof(Interval),cmp);

    Interval res[n];
    int idx=0;

    res[idx]=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i].start <= res[idx].end){
            if(arr[i].end > res[idx].end)
                res[idx].end = arr[i].end;
        } else{
            idx++;
            res[idx]=arr[i];
        }
    }

    for(int i=0;i<=idx;i++)
        printf("%d %d\n",res[i].start,res[i].end);
}

int main(){
    Interval arr[]={{1,3},{2,6},{8,10},{15,18}};
    int n=4;
    mergeIntervals(arr,n);
    return 0;
}

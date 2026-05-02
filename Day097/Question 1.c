//Problem: Given meeting intervals, find minimum number of rooms required. Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int start,end;
}Interval;

int cmpStart(const void *a,const void *b){
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int cmpEnd(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}

int minRooms(Interval arr[],int n){
    qsort(arr,n,sizeof(Interval),cmpStart);

    int *heap = (int*)malloc(n*sizeof(int));
    int size=0;

    heap[size++]=arr[0].end;

    for(int i=1;i<n;i++){
        if(arr[i].start >= heap[0]){
            heap[0]=arr[i].end;
        } else{
            heap[size++]=arr[i].end;
        }
        qsort(heap,size,sizeof(int),cmpEnd);
    }
    return size;
}

int main(){
    Interval arr[]={{0,30},{5,10},{15,20}};
    int n=3;
    printf("%d",minRooms(arr,n));
    return 0;
}

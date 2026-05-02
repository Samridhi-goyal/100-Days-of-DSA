/*Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. 
  Return the minimum number of rooms required to attend all meetings.*/

#include <stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int* start, int* end, int n){
    qsort(start,n,sizeof(int),cmp);
    qsort(end,n,sizeof(int),cmp);

    int i=0,j=0;
    int rooms=0,maxRooms=0;

    while(i<n){
        if(start[i] < end[j]){
            rooms++;
            i++;
        } else{
            rooms--;
            j++;
        }
        if(rooms > maxRooms) maxRooms = rooms;
    }

    return maxRooms;
}

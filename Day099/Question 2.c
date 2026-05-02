/*There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
You are given two integer arrays position and speed, both of length n, where position[i] is the starting mile of the ith car and 
speed[i] is the speed of the ith car in miles per hour.
A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
A car fleet is a single car or a group of cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.
If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.
Return the number of car fleets that will arrive at the destination.*/


#include <stdlib.h>

typedef struct{
    int pos;
    int speed;
}Car;

int cmp(const void *a,const void *b){
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize){
    Car cars[positionSize];

    for(int i=0;i<positionSize;i++){
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), cmp);

    int fleets = 0;
    double prevTime = 0;

    for(int i=0;i<positionSize;i++){
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if(time > prevTime){
            fleets++;
            prevTime = time;
        }
    }

    return fleets;
}

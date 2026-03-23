/*Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.*/

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* in;
    int* out;
    int topIn;
    int topOut;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 10000;
    obj->in = (int*)malloc(sizeof(int) * obj->capacity);
    obj->out = (int*)malloc(sizeof(int) * obj->capacity);
    obj->topIn = -1;
    obj->topOut = -1;
    return obj;
}

void move(MyQueue* obj) {
    if(obj->topOut == -1) {
        while(obj->topIn != -1) {
            obj->out[++obj->topOut] = obj->in[obj->topIn--];
        }
    }
}

void myQueuePush(MyQueue* obj, int x) {
    obj->in[++obj->topIn] = x;
}

int myQueuePop(MyQueue* obj) {
    move(obj);
    return obj->out[obj->topOut--];
}

int myQueuePeek(MyQueue* obj) {
    move(obj);
    return obj->out[obj->topOut];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->topIn == -1 && obj->topOut == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->in);
    free(obj->out);
    free(obj);
}

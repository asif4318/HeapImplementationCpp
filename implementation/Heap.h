#include <iostream>
#pragma once

/* This is a min heap*/
class Heap
{
private:
    int size;
    int arraySize;
    int *arr;
    void swap(int parentIndex, int childIndex);
    void heapify(int index);
    void siftUp(int index);

public:
    Heap();
    Heap(int *array, int size);
    ~Heap();
    void printHeap();
    void pop();
    void insert(int val);
};
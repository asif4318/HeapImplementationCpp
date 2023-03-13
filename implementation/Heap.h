#include <iostream>
#pragma once

/* This is a min heap*/
class Heap
{
private:
    int size;
    int *arr;
    void swap(int parent, int child);
public:
    Heap();
    Heap(int* array, int size);
    ~Heap();
    void heapify(int index);
    void printHeap();
    void pop();
};
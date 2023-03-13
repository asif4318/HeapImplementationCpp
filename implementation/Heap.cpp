#include "Heap.h"

void Heap::swap(int parent, int child)
{
    int temporary = arr[child];
    arr[child] = arr[parent];
    arr[parent] = temporary;
}

Heap::Heap()
{
    this->size = 0;
    this->arr = new int[10];
}

Heap::Heap(int *array, int size)
{
    this->arr = new int[size*2]; //Make array with size * 2 for expansion

    //copy values into class array
    for (int i = 0; i < size; i++) {
        this->arr[i] = array[i];
    }

    this->size = size;

    int startIndex = (size/2) - 1; // Last non leaf node
    for (int i = startIndex; i >= 0; i--) {
        heapify(i); // Heapify in reverse level order
    }
}

Heap::~Heap()
{
    delete[] this->arr;
}

void Heap::heapify(int index) //heapify for max heap
{
    int largest = index;
    int leftChild = index*2+1;
    int rightChild = index*2+2;

    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(index, largest);
        heapify(largest);
    }
}

void Heap::printHeap()
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::pop()
{
    // Set first element of array equal to last and decrement size;
    arr[0] = arr[--size];
    heapify(0);
}

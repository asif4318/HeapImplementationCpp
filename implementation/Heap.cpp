#include "Heap.h"

void Heap::swap(int parentIndex, int childIndex)
{
    int temporary = arr[childIndex];
    arr[childIndex] = arr[parentIndex];
    arr[parentIndex] = temporary;
}

Heap::Heap()
{
    this->size = 0;
    this->arr = new int[0];
    this->arraySize = 0;
}

Heap::Heap(int *array, int size)
{
    this->arr = new int[size];
    // copy values into class array
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = array[i];
    }

    this->size = size;
    this->arraySize = size;

    int startIndex = (size / 2) - 1; // Last non leaf node
    for (int i = startIndex; i >= 0; i--)
    {
        heapify(i); // Heapify in reverse level order
    }
}

Heap::~Heap()
{
    delete[] this->arr;
}

void Heap::heapify(int index) // heapify for max heap
{
    int largest = index;
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;

    if (leftChild < size && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild < size && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != index)
    {
        swap(index, largest);
        heapify(largest);
    }
}

void Heap::siftUp(int index)
{
    int parentIndex;
    int temp;

    if (index != 0)
    {
        parentIndex = (index - 1) / 2;
        if (arr[parentIndex] < arr[index])
        {
            swap(parentIndex, index);
            siftUp(parentIndex);
        }
    }
}

void Heap::printHeap()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::pop()
{
    // Set first element of array equal to last and decrement size;
    arr[0] = arr[--size];
    std::cout << "Size: " << size << std::endl;
    heapify(0);
}

void Heap::insert(int val)
{
    if (arraySize == size)
    {
        std::cout << "No more array space" << std::endl;
    }
    else
    { // Set last element to value
        size++;
        arr[size - 1] = val;
        siftUp(size - 1);
    }
}

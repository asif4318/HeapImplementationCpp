#include <iostream>
#include "Heap.h"

int main() {
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    Heap hp = Heap(arr, 11);
    hp.printHeap();
    hp.pop();
    hp.printHeap();
    hp.insert(19);
    hp.printHeap();
    hp.insert(40);
    return 0;
}
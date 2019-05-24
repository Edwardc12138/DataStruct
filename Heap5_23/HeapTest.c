#include <stdio.h>
#include "Heap.h"

int main() {
    Heap heap;
    int arr[] = {1,3,5,7,9,2,4,6,8,0};
    InitHeap(&heap, arr, sizeof(arr) / sizeof(arr[0]), More);
    PrintHeap(&heap);
    InsertHeap(&heap, 4);
    PrintHeap(&heap);
    RemoveHeap(&heap);
    PrintHeap(&heap);
    DetroyHeap(&heap);
    return 0;
}

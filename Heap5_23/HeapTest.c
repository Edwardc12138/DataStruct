#include <stdio.h>
#include "Heap.h"

int main() {
    Heap heap;
    int arr[] = {1,3,5,7,9,2,4,6,8,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    InitHeap(&heap, arr, size, More);
    PrintHeap(&heap);
    InsertHeap(&heap, 4);
    PrintHeap(&heap);
    RemoveHeap(&heap);
    PrintHeap(&heap);
    HeapSort(arr, size, More);
    int i;
    for(i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    DetroyHeap(&heap);
    return 0;
}

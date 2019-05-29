#include <stdio.h>
#include "Sort.h"

int main()
{
    printf("插入排序: \n");
    SortTest(InsertSort);
    printf("希尔排序: \n");
    SortTest(ShellSort);
    printf("选择排序: \n");
    SortTest(SlectSort);
    printf("  堆排序: \n");
    SortTest(HeapSort);
    printf("冒泡排序: \n");
    SortTest(BubbleSort);
    printf("快速排序: \n");
    SortTest(QuickSort);
    printf("归并排序: \n");
    SortTest(MergeSort);
    return 0;
}


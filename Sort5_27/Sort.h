#pragma once

typedef int SortDataType;

typedef int(*Type)(SortDataType, SortDataType);

// 大
int More(SortDataType left, SortDataType right);

// 小
int Less(SortDataType left, SortDataType right);

// 插入排序
void InsertSort(SortDataType* arr, int size, Type tp);

// 希尔排序
void ShellSort(SortDataType* arr, int size, Type tp);

// 选择排序
void SlectSort(SortDataType* arr, int size, Type tp);

// 堆排
void HeapSort(SortDataType* arr, int size, Type tp);

// 冒泡
void BubbleSort(SortDataType* arr, int size, Type tp);

// 快排
void QuickSort(SortDataType* arr, int size, Type tp);

// 归并排序
void MergeSort(SortDataType* arr, int size, Type tp);




typedef void(*SortType)(SortDataType*, int, Type);

// 排序测试
void SortTest(SortType st);

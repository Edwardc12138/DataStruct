#pragma once

typedef int HeapDataType;

// 堆类型函数指针
typedef int(*HeapType)(HeapDataType x, HeapDataType y);

typedef struct Heap {
    HeapDataType* _data;    // 堆数据
    int _size;      // 堆元素
    int _cap;       // 堆容量
    HeapType _ht;   // 堆类型
} Heap;

// 大堆
int More(HeapDataType x, HeapDataType y);

// 小堆
int Less(HeapDataType x, HeapDataType y);

// 初始化
void InitHeap(Heap* ph, HeapDataType* data, int n, HeapType ht);

// 初始化空堆
void InitEmptyHeap(Heap* ph, HeapType ht);

// 销毁
void DetroyHeap(Heap* ph);

// 打印
void PrintHeap(Heap* ph);

// 插入
void InsertHeap(Heap* ph, HeapDataType data);

// 删除对顶元素
void RemoveHeap(Heap* ph);

// 堆有效元素个数
int SizeHeap(Heap* ph);

// 堆是否为空
int EmptyHeap(Heap* ph);

// 获取堆顶元素
HeapDataType TopHeap(Heap* ph);

#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>

typedef int SLDataType;

// 顺序表
typedef struct SeqList
{
	//SLDataType data[1024];	// 静态顺序表
	SLDataType *_data;		// 动态顺序表
	size_t _size;			// 有效元素个数
	size_t _cap;			// 容量
} SeqList, *SeqListPtr;

// 将slp初始化为容量大小为cap的顺序表
void InitSeqList(SeqListPtr slp, size_t cap);

// 销毁顺序表
void DestroySeqList(SeqListPtr slp);

// 改变顺序表的容量
void ReCapSeqList(SeqListPtr slp, size_t cap);

// 在pos位置插入data
void InsertSeqList(SeqListPtr slp, size_t pos, SLDataType data);

// 删除pos位置的元素
void EraseSeqList(SeqListPtr slp, size_t pos);

// 打印顺序表的元素
void PrintSeqList(SeqListPtr slp);

// 在顺序表的尾部插入数据
void PushBackSeqList(SeqListPtr slp, SLDataType data);

// 删除顺序表尾部数据
void PopBackSeqList(SeqListPtr slp);

// 在顺序表的首部插入数据
void PushFrontSeqList(SeqListPtr slp, SLDataType data);

// 删除顺序表首部的数据
void PopFrontSeqList(SeqListPtr slp);

// 在顺序表中查找data,找到返回data的下标,否则返回-1
int SearchSeqList(SeqListPtr slp, SLDataType data);

// 顺序表是否为空
int EmptySeqList(SeqListPtr slp);

// 有效元素的个数
int SizeSeqList(SeqListPtr slp);

// 容量大小
int CapSeqList(SeqListPtr slp);

// 清空顺序表的所有数据
void ClearSeqList(SeqListPtr slp);

// 删除顺序表中第一个值为data的元素
void RemoveSeqList(SeqListPtr slp, SLDataType data);

// 对顺序表进行冒泡排序
void BubbleSortSeqList(SeqListPtr slp);

// 对顺序表进行二分查找
int BinarySearchSeqList(SeqListPtr slp, SLDataType data);

// 移除顺序表中所有与data相等的数据
void RemoveAllSeqList(SeqListPtr slp, SLDataType data);
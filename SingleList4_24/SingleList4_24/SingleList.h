#pragma once

#include <stdio.h>

typedef int SingleListDataType;

// 节点
typedef struct Node {
	SingleListDataType _data;	// 存储数据
	struct Node *_next;			// 指向下一节点的指针
} Node, *NodePtr;

// 不带头结点的单链表
typedef struct SingleList {
	NodePtr _head;	// 指向第一个节点的指针
	size_t _size;	// 元素个数
} SingleList, *SingleListPtr;

// 初始化链表
void InitSingleList(SingleListPtr psl);

// 新建节点
NodePtr NewSLNode(SingleListDataType data);

// 在pos处插入data
void InsertSLNode(SingleListPtr psl, size_t pos, SingleListDataType data);

// 删除pos处的节点
void RemoveAtSLNode(SingleListPtr psl, size_t pos);

// 头插
void PushFrontSLNode(SingleListPtr psl, SingleListDataType data);

// 头删
void PopFrontSLNode(SingleListPtr psl);

// 尾插
void PushBackSLNode(SingleListPtr psl, SingleListDataType data);

// 尾删
void PopBackSLNode(SingleListPtr psl);

// 查找值为data的节点
NodePtr SearchSLNode(SingleListPtr psl, SingleListDataType data);

// 删除值为data的节点
void RemoveSLNode(SingleListPtr psl, SingleListDataType data);

// 删除全部值为data的节点
void RemoveAllSLNode(SingleListPtr psl, SingleListDataType data);

// 链表的长度
size_t SizeofSingleList(SingleListPtr psl);

// 链表是否为空
int EmptySingleList(SingleListPtr psl);

// 清空链表
void ClearSingleList(SingleListPtr psl);

// 打印链表
void PrintSingleList(SingleListPtr psl);
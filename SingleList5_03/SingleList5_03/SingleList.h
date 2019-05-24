#pragma once

#include <assert.h>

typedef int SLDataType;

typedef struct SLNode {
	SLDataType _data;	// 存储数据
	struct SLNode *_next;	// 下一节点
} SLNode, *SLNodePtr;

// 初始化单链表
inline void InitSingleList(SLNodePtr *head) {
	assert(head);	// 指针不为空
	*head = NULL;	// 头指针置空
}

// 在pos处插入data
void InsertData(SLNodePtr *head, int pos, SLDataType data);

// 删除pos处的节点
void RemoveSLNode(SLNodePtr *head, int pos);

// 打印链表数据
void PrintSL(SLNodePtr head);

// 头插
void PushFrontData(SLNodePtr *head, SLDataType data);

// 头删
void PopFrontSLNode(SLNodePtr *head);

// 尾插
void PushBackData(SLNodePtr *head, SLDataType data);

// 尾删
void PopBackSLNode(SLNodePtr *head);

// 清空链表
void ClearSL(SLNodePtr *head);

// 查找节点,返回第一个匹配data的节点
SLNodePtr FindSLNode(SLNodePtr head, SLDataType data);

// 查找第n个节点
SLNodePtr FindnSLNode(SLNodePtr head, const int n);

// 移除所有值为data的节点
void RemoveAllSLNode(SLNodePtr *head, SLDataType data);

// 移除重复的节点
SLNodePtr deleteDuplication(SLNodePtr pHead);
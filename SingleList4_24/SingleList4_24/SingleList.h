#pragma once

#include <stdio.h>

typedef int SingleListDataType;

// �ڵ�
typedef struct Node {
	SingleListDataType _data;	// �洢����
	struct Node *_next;			// ָ����һ�ڵ��ָ��
} Node, *NodePtr;

// ����ͷ���ĵ�����
typedef struct SingleList {
	NodePtr _head;	// ָ���һ���ڵ��ָ��
	size_t _size;	// Ԫ�ظ���
} SingleList, *SingleListPtr;

// ��ʼ������
void InitSingleList(SingleListPtr psl);

// �½��ڵ�
NodePtr NewSLNode(SingleListDataType data);

// ��pos������data
void InsertSLNode(SingleListPtr psl, size_t pos, SingleListDataType data);

// ɾ��pos���Ľڵ�
void RemoveAtSLNode(SingleListPtr psl, size_t pos);

// ͷ��
void PushFrontSLNode(SingleListPtr psl, SingleListDataType data);

// ͷɾ
void PopFrontSLNode(SingleListPtr psl);

// β��
void PushBackSLNode(SingleListPtr psl, SingleListDataType data);

// βɾ
void PopBackSLNode(SingleListPtr psl);

// ����ֵΪdata�Ľڵ�
NodePtr SearchSLNode(SingleListPtr psl, SingleListDataType data);

// ɾ��ֵΪdata�Ľڵ�
void RemoveSLNode(SingleListPtr psl, SingleListDataType data);

// ɾ��ȫ��ֵΪdata�Ľڵ�
void RemoveAllSLNode(SingleListPtr psl, SingleListDataType data);

// ����ĳ���
size_t SizeofSingleList(SingleListPtr psl);

// �����Ƿ�Ϊ��
int EmptySingleList(SingleListPtr psl);

// �������
void ClearSingleList(SingleListPtr psl);

// ��ӡ����
void PrintSingleList(SingleListPtr psl);
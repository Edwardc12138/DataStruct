#pragma once

#include <assert.h>

typedef int SLDataType;

typedef struct SLNode {
	SLDataType _data;	// �洢����
	struct SLNode *_next;	// ��һ�ڵ�
} SLNode, *SLNodePtr;

// ��ʼ��������
inline void InitSingleList(SLNodePtr *head) {
	assert(head);	// ָ�벻Ϊ��
	*head = NULL;	// ͷָ���ÿ�
}

// ��pos������data
void InsertData(SLNodePtr *head, int pos, SLDataType data);

// ɾ��pos���Ľڵ�
void RemoveSLNode(SLNodePtr *head, int pos);

// ��ӡ��������
void PrintSL(SLNodePtr head);

// ͷ��
void PushFrontData(SLNodePtr *head, SLDataType data);

// ͷɾ
void PopFrontSLNode(SLNodePtr *head);

// β��
void PushBackData(SLNodePtr *head, SLDataType data);

// βɾ
void PopBackSLNode(SLNodePtr *head);

// �������
void ClearSL(SLNodePtr *head);

// ���ҽڵ�,���ص�һ��ƥ��data�Ľڵ�
SLNodePtr FindSLNode(SLNodePtr head, SLDataType data);

// ���ҵ�n���ڵ�
SLNodePtr FindnSLNode(SLNodePtr head, const int n);

// �Ƴ�����ֵΪdata�Ľڵ�
void RemoveAllSLNode(SLNodePtr *head, SLDataType data);

// �Ƴ��ظ��Ľڵ�
SLNodePtr deleteDuplication(SLNodePtr pHead);
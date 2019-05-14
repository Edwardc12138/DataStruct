#pragma once
// ��ͷѭ��˫����

typedef int CDLDataType;

typedef struct CDLNode {
	CDLDataType _data;	// �洢����
	struct CDLNode *_front;	// ǰһ���ڵ�
	struct CDLNode *_next;	// ��һ���ڵ�
} CDLNode, *CDLNodePtr;

// ��ʼ������
void InitCDL(CDLNodePtr *head);

// ��pos������data
void InsertData(CDLNodePtr head, int pos, CDLDataType data);

// ɾ��pos���Ľڵ�
void RemoveCDLNode(CDLNodePtr head, int pos);

// ��ӡ����
void PrintCDL(CDLNodePtr head);

// ͷ��
void PushFrontData(CDLNodePtr head, CDLDataType data);

// ͷɾ
void PopFrontCDLNode(CDLNodePtr head);

// β��
void PushBackData(CDLNodePtr head, CDLDataType data);

// βɾ
void PopBackCDLNode(CDLNodePtr head);

// ���
void ClearCDL(CDLNodePtr head);

// ����
void DesroyCDL(CDLNodePtr *head);

// ����
CDLNodePtr SearchCDLNode(CDLNodePtr head, CDLDataType data);

// �Ƴ���data��ͬ��ȫ���ڵ�
void RemoveAllData(CDLNodePtr head, CDLDataType data);
#pragma once
// 带头循环双链表

typedef int CDLDataType;

typedef struct CDLNode {
	CDLDataType _data;	// 存储数据
	struct CDLNode *_front;	// 前一个节点
	struct CDLNode *_next;	// 下一个节点
} CDLNode, *CDLNodePtr;

// 初始化链表
void InitCDL(CDLNodePtr *head);

// 在pos处插入data
void InsertData(CDLNodePtr head, int pos, CDLDataType data);

// 删除pos处的节点
void RemoveCDLNode(CDLNodePtr head, int pos);

// 打印链表
void PrintCDL(CDLNodePtr head);

// 头插
void PushFrontData(CDLNodePtr head, CDLDataType data);

// 头删
void PopFrontCDLNode(CDLNodePtr head);

// 尾插
void PushBackData(CDLNodePtr head, CDLDataType data);

// 尾删
void PopBackCDLNode(CDLNodePtr head);

// 清空
void ClearCDL(CDLNodePtr head);

// 销毁
void DesroyCDL(CDLNodePtr *head);

// 查找
CDLNodePtr SearchCDLNode(CDLNodePtr head, CDLDataType data);

// 移除与data相同的全部节点
void RemoveAllData(CDLNodePtr head, CDLDataType data);
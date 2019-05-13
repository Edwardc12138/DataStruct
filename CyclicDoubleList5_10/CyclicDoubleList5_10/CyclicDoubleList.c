#include "CyclicDoubleList.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

// 新建节点
CDLNodePtr _NewCDLNode(CDLDataType data) {
	CDLNodePtr new_node = (CDLNodePtr)malloc(sizeof(CDLNode));
	if (!new_node) {
		return NULL;
	}
	new_node->_data = data;
	new_node->_front = NULL;
	new_node->_next = NULL;
	return new_node;
}

void InitCDL(CDLNodePtr *head) {
	assert(head);

	*head = _NewCDLNode(NULL);
	if (!*head) {
		printf("InitCDL : 初始化失败,节点新建失败\n");
		return;
	}
	(*head)->_front = *head;	// 指向自己
	(*head)->_next = *head;
}

void InsertData(CDLNodePtr head, int pos, CDLDataType data) {
	assert(head);

	if (pos <= 0) {
		printf("InsertData : 插入位置不能小于1\n");
		return;
	}

	CDLNodePtr node = _NewCDLNode(data);	// 新建节点
	if (!node) {
		printf("InsertData : 插入失败,节点新建失败\n");
		return;
	}

	if (head->_next == head && pos == 1) {		// 空链表
		head->_front = node;		// 头结点指向新节点
		head->_next = node;
		node->_front = head;		// 新节点指向头结点
		node->_next = head;
	}
	else {		// 非空链表
		CDLNodePtr pcur = head;
		while (pcur->_next != head && pos != 1) {	// 当前节点的下一节点不为头结点
			pcur = pcur->_next;
			--pos;
		}
		if (pos == 1) {
			node->_front = pcur;		// 新节点向前指向当前节点
			node->_next = pcur->_next;	// 向后指向当前节点的下一节点
			pcur->_next->_front = node;	// 当前节点的下一节点向前指向新节点
			pcur->_next = node;			// 当前节点向后指向新节点
		}
		else {
			printf("InsertData : 插入位置越界\n");
		}
	}
}

void RemoveCDLNode(CDLNodePtr head, int pos) {
	assert(head);

	if (pos <= 0) {
		return;
	}

	CDLNodePtr pcur = head;
	while (pcur->_next != head && pos) {
		pcur = pcur->_next;
		--pos;
	}
	if (!pos) {
		pcur->_front->_next = pcur->_next;	// 当前节点的前一个节点向后指向当前节点的下一个节点
		pcur->_next->_front = pcur->_front;	// 当前节点的下一个节点向前指向当前节点的前一个节点
		free(pcur);
	}
}

void PrintCDL(CDLNodePtr head) {
	assert(head);

	CDLNodePtr pcur = head->_next;
	printf("HEAD <=> ");
	while (pcur != head) {
		printf("%d <=> ", pcur->_data);
		pcur = pcur->_next;
	}
	printf("HEAD\n");
}

void PushFrontData(CDLNodePtr head, CDLDataType data) {
	assert(head);

	//InsertData(head, 1, data);
	CDLNodePtr node = _NewCDLNode(data);
	if (!node) {
		printf("PushFrontData : 插入失败,新建节点失败\n");
		return;
	}

	node->_next = head->_next;	// 新节点的next是第一个节点
	node->_front = head;		// front是头结点
	head->_next->_front = node;	// 第一个节点的front是新节点
	head->_next = node;			// 头结点的next是新节点
}

void PopFrontCDLNode(CDLNodePtr head) {
	assert(head);

	if (head->_next != head) {
		CDLNodePtr pcur = head->_next;
		pcur->_front->_next = pcur->_next;	// 头结点的next指向第二个节点
		pcur->_next->_front = pcur->_front;	// 第二个节点的front指向头结点
		free(pcur);
	}
}

void PushBackData(CDLNodePtr head, CDLDataType data) {
	assert(head);

	CDLNodePtr node = _NewCDLNode(data);
	if (!node) {
		printf("PushBackData : 插入失败,新建节点失败\n");
		return;
	}

	node->_next = head;				// 新节点的next指向头结点
	node->_front = head->_front;	// 新节点的front指向最后一个节点
	head->_front->_next = node;		// 最后一个节点的next指向新节点
	head->_front = node;			// 头结点的front指向新节点
}

void PopBackCDLNode(CDLNodePtr head) {
	assert(head);

	if (head->_front != head) {
		CDLNodePtr pcur = head->_front;
		head->_front = pcur->_front;	// 头节点的front指向倒数第二个节点
		pcur->_front->_next = head;		// 倒数第二个节点的next指向头结点
	}
}

void ClearCDL(CDLNodePtr head) {
	assert(head);

	// 释放节点
	for (CDLNodePtr pcur = head->_next; pcur != head; pcur = head->_next) {
		head->_next = pcur->_next;
		free(pcur);
	}
	head->_front = head;	// 头结点的front指向自己
}

void DesroyCDL(CDLNodePtr *head) {
	assert(head);

	ClearCDL(*head);	// 先清空链表
	free(*head);		// 在释放头结点
	*head = NULL;
}

CDLNodePtr SearchCDLNode(CDLNodePtr head, CDLDataType data) {
	assert(head);

	CDLNodePtr pcur = head->_next;
	while (pcur != head) {		// 遍历链表
		if (pcur->_data == data) {	// 数据匹配
			return pcur;		// 返回当前节点
		}
		pcur = pcur->_next;		// 否则,节点后移
	}
	return NULL;	// 没找到返回NULL
}

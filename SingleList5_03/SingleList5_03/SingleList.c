#define _CRT_SECURE_NO_WARNINGS

#include "SingleList.h"
#include <malloc.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

// 新建节点
SLNodePtr _NewSLNode(SLDataType data) {
	// 新建节点
	SLNodePtr new_node = (SLNodePtr)malloc(sizeof(SLNode));
	if (new_node == NULL) {			// 新建节点失败
		perror(strerror(errno));	// 打印错误信息
		return NULL;
	}
	// 节点创建成功
	new_node->_data = data;		// 存储数据
	new_node->_next = NULL;
	return new_node;
}

void InsertData(SLNodePtr * head, int pos, SLDataType data) {
	assert(head);

	if (pos < 0) {	// pos位置非法
		perror("pos 位置小于 0");
		return;
	}

	if (pos == 0) {		// 在第0个位置插入
		SLNodePtr node = _NewSLNode(data);
		if (node) {
			if (*head == NULL) {		// 空链表
				*head = node;
				return;
			}
			else {
				node->_next = *head;
				*head = node;
				return;
			}
		}
	}
	else {
		SLNodePtr pcur = *head;
		while (pcur) {		// 当前节点不为空
			if ((pos--) == 1) {
				SLNodePtr node = _NewSLNode(data);
				if (node) {
					// 插入节点
					node->_next = pcur->_next;
					pcur->_next = node;
				}
				return;
			}
			pcur = pcur->_next;
		}
	}
	perror("pos 位置超出链表长度");
	return;
}

void RemoveSLNode(SLNodePtr * head, int pos) {
	assert(head);

	if (pos < 0 || *head == NULL) {
		return;
	}

	SLNodePtr pcur = *head;
	if (pos == 0) {		// 第0个节点
		*head = pcur->_next;
	}
	else {
		SLNodePtr ppre = pcur;	// 存储当前节点的上一节点
		pcur = ppre->_next;
		while (pcur) {			// 当前节点不为空
			if ((pos--) == 1) {		// 找到待删除位置
				ppre->_next = pcur->_next;	// 将其从链表中移除
				break;
			}
			ppre = pcur;
			pcur = pcur->_next;
		}
	}
	if (pcur) {
		free(pcur);		// 销毁节点
	}
	return;
}

void PrintSL(SLNodePtr head) {
	SLNodePtr pcur = head;
	while (pcur) {	// 当前节点不为空
		printf("%d -> ", pcur->_data);	// 打印数据
		pcur = pcur->_next;
	}
	printf("NULL\n");
	return;
}

void PushFrontData(SLNodePtr * head, SLDataType data) {
	assert(head);
	InsertData(head, 0, data);
}

void PopFrontSLNode(SLNodePtr * head) {
	assert(head);
	RemoveSLNode(head, 0);
}

void PushBackData(SLNodePtr * head, SLDataType data) {
	assert(head);

	SLNodePtr node = _NewSLNode(data);
	if (*head == NULL) {	// 空链表
		*head = node;
	}
	else {
		SLNodePtr pcur = *head;
		while (pcur->_next) {	// 定位最后一个节点
			pcur = pcur->_next;
		}
		pcur->_next = node;
	}
}

void PopBackSLNode(SLNodePtr * head) {
	assert(head);

	if (*head == NULL) {
		return;
	}

	SLNodePtr ppre = NULL;
	SLNodePtr pcur = *head;
	while (pcur->_next) {	// 当前节点的下一节点不为空
		ppre = pcur;
		pcur = ppre->_next;
	}
	if (ppre) {		// 前一节点不为空
		ppre->_next = NULL;
	}
	else {			// 前一节点为空
		*head = NULL;
	}
	free(pcur);
}

// 不用二级指针头指针会变成野指针
void ClearSL(SLNodePtr *head) {
	assert(head);

	for (SLNodePtr pcur = *head; pcur; pcur = *head) {
		*head = pcur->_next;
		free(pcur);
	}
}

SLNodePtr FindSLNode(SLNodePtr head, const SLDataType data) {
	assert(head);

	SLNodePtr pcur = head;
	while (pcur) {
		if (pcur->_data == data) {	// 匹配相等
			return pcur;	// 返回当前节点
		}
		pcur = pcur->_next;
	}
	return NULL;	// 未找到节点
}

SLNodePtr FindnSLNode(SLNodePtr head, const int n) {
	assert(head);

	if (n < 0) {
		perror("n 不能小于 0");
		return NULL;
	}
	SLNodePtr pcur = head;
	for (int i = 0; i < n && pcur; ++i, pcur = pcur->_next);
	if (pcur) {
		return pcur;
	}
	return NULL;	// 未找到
}

void RemoveAllSLNode(SLNodePtr * head, SLDataType data) {
	assert(head);

	SLNodePtr ppre = NULL;
	SLNodePtr pcur = *head;
	while (pcur) {		// 当前节点不为空
		if (pcur->_data == data) {		// 数据相等
			if (ppre) {		// 不是第0个节点
				ppre->_next = pcur->_next;
				free(pcur);
				pcur = ppre->_next;
			}
			else {			// 第0个节点
				*head = pcur->_next;
				free(pcur);
				pcur = *head;
			}
		}
		else {
			ppre = pcur;
			pcur = ppre->_next;
		}
	}
}

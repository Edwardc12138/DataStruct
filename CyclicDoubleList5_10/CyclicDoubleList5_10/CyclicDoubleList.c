#include "CyclicDoubleList.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

// �½��ڵ�
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
		printf("InitCDL : ��ʼ��ʧ��,�ڵ��½�ʧ��\n");
		return;
	}
	(*head)->_front = *head;	// ָ���Լ�
	(*head)->_next = *head;
}

void InsertData(CDLNodePtr head, int pos, CDLDataType data) {
	assert(head);

	if (pos <= 0) {
		printf("InsertData : ����λ�ò���С��1\n");
		return;
	}

	CDLNodePtr node = _NewCDLNode(data);	// �½��ڵ�
	if (!node) {
		printf("InsertData : ����ʧ��,�ڵ��½�ʧ��\n");
		return;
	}

	if (head->_next == head && pos == 1) {		// ������
		head->_front = node;		// ͷ���ָ���½ڵ�
		head->_next = node;
		node->_front = head;		// �½ڵ�ָ��ͷ���
		node->_next = head;
	}
	else {		// �ǿ�����
		CDLNodePtr pcur = head;
		while (pcur->_next != head && pos != 1) {	// ��ǰ�ڵ����һ�ڵ㲻Ϊͷ���
			pcur = pcur->_next;
			--pos;
		}
		if (pos == 1) {
			node->_front = pcur;		// �½ڵ���ǰָ��ǰ�ڵ�
			node->_next = pcur->_next;	// ���ָ��ǰ�ڵ����һ�ڵ�
			pcur->_next->_front = node;	// ��ǰ�ڵ����һ�ڵ���ǰָ���½ڵ�
			pcur->_next = node;			// ��ǰ�ڵ����ָ���½ڵ�
		}
		else {
			printf("InsertData : ����λ��Խ��\n");
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
		pcur->_front->_next = pcur->_next;	// ��ǰ�ڵ��ǰһ���ڵ����ָ��ǰ�ڵ����һ���ڵ�
		pcur->_next->_front = pcur->_front;	// ��ǰ�ڵ����һ���ڵ���ǰָ��ǰ�ڵ��ǰһ���ڵ�
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
		printf("PushFrontData : ����ʧ��,�½��ڵ�ʧ��\n");
		return;
	}

	node->_next = head->_next;	// �½ڵ��next�ǵ�һ���ڵ�
	node->_front = head;		// front��ͷ���
	head->_next->_front = node;	// ��һ���ڵ��front���½ڵ�
	head->_next = node;			// ͷ����next���½ڵ�
}

void PopFrontCDLNode(CDLNodePtr head) {
	assert(head);

	if (head->_next != head) {
		CDLNodePtr pcur = head->_next;
		pcur->_front->_next = pcur->_next;	// ͷ����nextָ��ڶ����ڵ�
		pcur->_next->_front = pcur->_front;	// �ڶ����ڵ��frontָ��ͷ���
		free(pcur);
	}
}

void PushBackData(CDLNodePtr head, CDLDataType data) {
	assert(head);

	CDLNodePtr node = _NewCDLNode(data);
	if (!node) {
		printf("PushBackData : ����ʧ��,�½��ڵ�ʧ��\n");
		return;
	}

	node->_next = head;				// �½ڵ��nextָ��ͷ���
	node->_front = head->_front;	// �½ڵ��frontָ�����һ���ڵ�
	head->_front->_next = node;		// ���һ���ڵ��nextָ���½ڵ�
	head->_front = node;			// ͷ����frontָ���½ڵ�
}

void PopBackCDLNode(CDLNodePtr head) {
	assert(head);

	if (head->_front != head) {
		CDLNodePtr pcur = head->_front;
		head->_front = pcur->_front;	// ͷ�ڵ��frontָ�����ڶ����ڵ�
		pcur->_front->_next = head;		// �����ڶ����ڵ��nextָ��ͷ���
	}
}

void ClearCDL(CDLNodePtr head) {
	assert(head);

	// �ͷŽڵ�
	for (CDLNodePtr pcur = head->_next; pcur != head; pcur = head->_next) {
		head->_next = pcur->_next;
		free(pcur);
	}
	head->_front = head;	// ͷ����frontָ���Լ�
}

void DesroyCDL(CDLNodePtr *head) {
	assert(head);

	ClearCDL(*head);	// ���������
	free(*head);		// ���ͷ�ͷ���
	*head = NULL;
}

CDLNodePtr SearchCDLNode(CDLNodePtr head, CDLDataType data) {
	assert(head);

	CDLNodePtr pcur = head->_next;
	while (pcur != head) {		// ��������
		if (pcur->_data == data) {	// ����ƥ��
			return pcur;		// ���ص�ǰ�ڵ�
		}
		pcur = pcur->_next;		// ����,�ڵ����
	}
	return NULL;	// û�ҵ�����NULL
}

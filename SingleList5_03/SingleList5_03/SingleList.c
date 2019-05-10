#define _CRT_SECURE_NO_WARNINGS

#include "SingleList.h"
#include <malloc.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

// �½��ڵ�
SLNodePtr _NewSLNode(SLDataType data) {
	// �½��ڵ�
	SLNodePtr new_node = (SLNodePtr)malloc(sizeof(SLNode));
	if (new_node == NULL) {			// �½��ڵ�ʧ��
		perror(strerror(errno));	// ��ӡ������Ϣ
		return NULL;
	}
	// �ڵ㴴���ɹ�
	new_node->_data = data;		// �洢����
	new_node->_next = NULL;
	return new_node;
}

void InsertData(SLNodePtr * head, int pos, SLDataType data) {
	assert(head);

	if (pos < 0) {	// posλ�÷Ƿ�
		perror("pos λ��С�� 0");
		return;
	}

	if (pos == 0) {		// �ڵ�0��λ�ò���
		SLNodePtr node = _NewSLNode(data);
		if (node) {
			if (*head == NULL) {		// ������
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
		while (pcur) {		// ��ǰ�ڵ㲻Ϊ��
			if ((pos--) == 1) {
				SLNodePtr node = _NewSLNode(data);
				if (node) {
					// ����ڵ�
					node->_next = pcur->_next;
					pcur->_next = node;
				}
				return;
			}
			pcur = pcur->_next;
		}
	}
	perror("pos λ�ó���������");
	return;
}

void RemoveSLNode(SLNodePtr * head, int pos) {
	assert(head);

	if (pos < 0 || *head == NULL) {
		return;
	}

	SLNodePtr pcur = *head;
	if (pos == 0) {		// ��0���ڵ�
		*head = pcur->_next;
	}
	else {
		SLNodePtr ppre = pcur;	// �洢��ǰ�ڵ����һ�ڵ�
		pcur = ppre->_next;
		while (pcur) {			// ��ǰ�ڵ㲻Ϊ��
			if ((pos--) == 1) {		// �ҵ���ɾ��λ��
				ppre->_next = pcur->_next;	// ������������Ƴ�
				break;
			}
			ppre = pcur;
			pcur = pcur->_next;
		}
	}
	if (pcur) {
		free(pcur);		// ���ٽڵ�
	}
	return;
}

void PrintSL(SLNodePtr head) {
	SLNodePtr pcur = head;
	while (pcur) {	// ��ǰ�ڵ㲻Ϊ��
		printf("%d -> ", pcur->_data);	// ��ӡ����
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
	if (*head == NULL) {	// ������
		*head = node;
	}
	else {
		SLNodePtr pcur = *head;
		while (pcur->_next) {	// ��λ���һ���ڵ�
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
	while (pcur->_next) {	// ��ǰ�ڵ����һ�ڵ㲻Ϊ��
		ppre = pcur;
		pcur = ppre->_next;
	}
	if (ppre) {		// ǰһ�ڵ㲻Ϊ��
		ppre->_next = NULL;
	}
	else {			// ǰһ�ڵ�Ϊ��
		*head = NULL;
	}
	free(pcur);
}

// ���ö���ָ��ͷָ�����Ұָ��
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
		if (pcur->_data == data) {	// ƥ�����
			return pcur;	// ���ص�ǰ�ڵ�
		}
		pcur = pcur->_next;
	}
	return NULL;	// δ�ҵ��ڵ�
}

SLNodePtr FindnSLNode(SLNodePtr head, const int n) {
	assert(head);

	if (n < 0) {
		perror("n ����С�� 0");
		return NULL;
	}
	SLNodePtr pcur = head;
	for (int i = 0; i < n && pcur; ++i, pcur = pcur->_next);
	if (pcur) {
		return pcur;
	}
	return NULL;	// δ�ҵ�
}

void RemoveAllSLNode(SLNodePtr * head, SLDataType data) {
	assert(head);

	SLNodePtr ppre = NULL;
	SLNodePtr pcur = *head;
	while (pcur) {		// ��ǰ�ڵ㲻Ϊ��
		if (pcur->_data == data) {		// �������
			if (ppre) {		// ���ǵ�0���ڵ�
				ppre->_next = pcur->_next;
				free(pcur);
				pcur = ppre->_next;
			}
			else {			// ��0���ڵ�
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

#define _CRT_SECURE_NO_WARNINGS
#include "SingleList.h"
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>

void InitSingleList(SingleListPtr psl) {
	assert(psl);
	psl->_head = NULL;	// ͷָ���ÿ�
	psl->_size = 0;		// Ԫ��Ϊ��
}

NodePtr NewSLNode(SingleListDataType data) {
	NodePtr pnew = (NodePtr)malloc(sizeof(Node));	// �����ڴ�
	if (pnew == NULL) {
		perror(strerror(errno));
		return NULL;	// �ڵ�δ�����ɹ�,���ؿ�
	}
	pnew->_data = data;		// ��_data��ֵ
	pnew->_next = NULL;		// ָ���ÿ�
	return pnew;	// �����½��Ľڵ�
}

void InsertSLNode(SingleListPtr psl, size_t pos, SingleListDataType data) {
	assert(psl);
	if (pos > psl->_size) {	// ����λ��Խ��
		return;
	}
	NodePtr pnew = NewSLNode(data);	// �½��ڵ�
	if (pnew == NULL) {		// �����ڵ�ʧ��
		return;
	}

	if (pos == 0) {		// ��0��λ��
		pnew->_next = psl->_head;	// �½ڵ�ָ��ͷָ��ָ���λ��
		psl->_head = pnew;			// ͷָ��ָ���½ڵ�
	}
	else {	// ����λ��
		NodePtr pcur = psl->_head;
		for (size_t i = 1; i < pos; ++i) {	// ��λ��pos��ǰһ��λ��
			pcur = pcur->_next;
		}
		pnew->_next = pcur->_next;	// �½ڵ�ָ��posλ�õĽڵ�
		pcur->_next = pnew;			// ��ǰ��λ�ڵ�ָ���½ڵ�
	}
	++psl->_size;
}

void RemoveAtSLNode(SingleListPtr psl, size_t pos) {
	assert(psl);
	if (pos >= psl->_size) {	// λ��Խ��
		return;
	}

	NodePtr pdel;		// ��ɾ���ڵ�
	if (pos == 0) {		// ��0��λ��
		pdel = psl->_head;			// ��ɾ���ڵ�ָ���0���ڵ�
		psl->_head = pdel->_next;	// ͷָ��ָ����һ���ڵ�
	}
	else {	// ����λ��
		NodePtr ppre = psl->_head;			// �����洢��ɾ���ڵ��ǰһ���ڵ�
		for (size_t i = 1; i < pos; ++i) {	// ��λǰһ��λ��
			ppre = ppre->_next;
		}
		pdel = ppre->_next;			// �ҵ�ɾ���ڵ�
		ppre->_next = pdel->_next;	// ǰһ�ڵ�ָ��ɾ���ڵ����һ�ڵ�
	}
	--psl->_size;
	free(pdel);
}

void PushFrontSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
	InsertSLNode(psl, 0, data);		// ��λ��0������
}

void PopFrontSLNode(SingleListPtr psl) {
	assert(psl);
	RemoveAtSLNode(psl, 0);		// ɾ��λ��0�Ľڵ�
}

void PushBackSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
	InsertSLNode(psl, psl->_size, data);	// ��size������
}

void PopBackSLNode(SingleListPtr psl) {
	assert(psl);
	RemoveAtSLNode(psl, psl->_size - 1);	// ɾ��size - 1���ڵ�
}

NodePtr SearchSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
	NodePtr pret = psl->_head;
	while (pret) {
		if (pret->_data == data) {	// ֵ��ȷ���
			return pret;
		}
		else {	// �������
			pret = pret->_next;
		}
	}
	return NULL;	// δ�ҵ�
}

void RemoveSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
	NodePtr pdel = psl->_head;
	if (pdel->_data == data) {		// ��0��λ�����
		psl->_head = pdel->_next;	// ͷָ��ָ��ɾ��λ��֮��
	}
	else {	// ֮���λ�����
		NodePtr ppre = pdel;	// ��ɾ���ڵ��ǰһ���ڵ�
		pdel = pdel->_next;
		while (pdel) {
			if (pdel->_data == data) {		// �������
				ppre->_next = pdel->_next;	// ǰһλ��ָɾ��λ��֮��
				break;
			}
			else {	// �����,ָ�����
				ppre = pdel;
				pdel = pdel->_next;
			}
		}
	}	
	--psl->_size;
	free(pdel);
}

void RemoveAllSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
}

size_t SizeofSingleList(SingleListPtr psl) {
	assert(psl);
	//NodePtr pcur = psl->_head;
	//size_t len = 0;		// �����ȼ���
	//while (pcur) {
	//	++len;
	//	pcur = pcur->_next;
	//}
	//return len;

	return psl->_size;
}

int EmptySingleList(SingleListPtr psl) {
	assert(psl);
	return psl->_size == 0;
}

void ClearSingleList(SingleListPtr psl) {
	assert(psl);

	NodePtr pdel = psl->_head;
	while (pdel) {	// ��Ϊ��
		psl->_head = pdel->_next;	// ͷָ�����
		free(pdel);
		pdel = psl->_head;
	}
	psl->_size = 0;
}

void PrintSingleList(SingleListPtr psl) {
	assert(psl);
	NodePtr pcur = psl->_head;
	while (pcur) {	// ��Ϊ��
		printf("%d ", pcur->_data);	// ��ӡ����
		pcur = pcur->_next;			// �����
	}
	printf("\n");
}

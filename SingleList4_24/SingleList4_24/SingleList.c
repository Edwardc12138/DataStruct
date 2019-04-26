#define _CRT_SECURE_NO_WARNINGS
#include "SingleList.h"
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>

void InitSingleList(SingleListPtr psl) {
	assert(psl);
	psl->_head = NULL;	// 头指针置空
	psl->_size = 0;		// 元素为空
}

NodePtr NewSLNode(SingleListDataType data) {
	NodePtr pnew = (NodePtr)malloc(sizeof(Node));	// 申请内存
	if (pnew == NULL) {
		perror(strerror(errno));
		return NULL;	// 节点未创建成功,返回空
	}
	pnew->_data = data;		// 给_data赋值
	pnew->_next = NULL;		// 指针置空
	return pnew;	// 返回新建的节点
}

void InsertSLNode(SingleListPtr psl, size_t pos, SingleListDataType data) {
	assert(psl);
	if (pos > psl->_size) {	// 访问位置越界
		return;
	}
	NodePtr pnew = NewSLNode(data);	// 新建节点
	if (pnew == NULL) {		// 创建节点失败
		return;
	}

	if (pos == 0) {		// 第0个位置
		pnew->_next = psl->_head;	// 新节点指向头指针指向的位置
		psl->_head = pnew;			// 头指针指向新节点
	}
	else {	// 其他位置
		NodePtr pcur = psl->_head;
		for (size_t i = 1; i < pos; ++i) {	// 定位到pos的前一个位置
			pcur = pcur->_next;
		}
		pnew->_next = pcur->_next;	// 新节点指向pos位置的节点
		pcur->_next = pnew;			// 当前定位节点指向新节点
	}
	++psl->_size;
}

void RemoveAtSLNode(SingleListPtr psl, size_t pos) {
	assert(psl);
	if (pos >= psl->_size) {	// 位置越界
		return;
	}

	NodePtr pdel;		// 待删除节点
	if (pos == 0) {		// 第0个位置
		pdel = psl->_head;			// 待删除节点指向第0个节点
		psl->_head = pdel->_next;	// 头指针指向下一个节点
	}
	else {	// 其他位置
		NodePtr ppre = psl->_head;			// 用来存储待删除节点的前一个节点
		for (size_t i = 1; i < pos; ++i) {	// 定位前一个位置
			ppre = ppre->_next;
		}
		pdel = ppre->_next;			// 找到删除节点
		ppre->_next = pdel->_next;	// 前一节点指向删除节点的下一节点
	}
	--psl->_size;
	free(pdel);
}

void PushFrontSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
	InsertSLNode(psl, 0, data);		// 在位置0处插入
}

void PopFrontSLNode(SingleListPtr psl) {
	assert(psl);
	RemoveAtSLNode(psl, 0);		// 删除位置0的节点
}

void PushBackSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
	InsertSLNode(psl, psl->_size, data);	// 在size处插入
}

void PopBackSLNode(SingleListPtr psl) {
	assert(psl);
	RemoveAtSLNode(psl, psl->_size - 1);	// 删除size - 1处节点
}

NodePtr SearchSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
	NodePtr pret = psl->_head;
	while (pret) {
		if (pret->_data == data) {	// 值相等返回
			return pret;
		}
		else {	// 否则后移
			pret = pret->_next;
		}
	}
	return NULL;	// 未找到
}

void RemoveSLNode(SingleListPtr psl, SingleListDataType data) {
	assert(psl);
	NodePtr pdel = psl->_head;
	if (pdel->_data == data) {		// 第0个位置相等
		psl->_head = pdel->_next;	// 头指针指向删除位置之后
	}
	else {	// 之后的位置相等
		NodePtr ppre = pdel;	// 待删除节点的前一个节点
		pdel = pdel->_next;
		while (pdel) {
			if (pdel->_data == data) {		// 相等跳出
				ppre->_next = pdel->_next;	// 前一位置指删除位置之后
				break;
			}
			else {	// 不相等,指针后移
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
	//size_t len = 0;		// 链表长度计数
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
	while (pdel) {	// 不为空
		psl->_head = pdel->_next;	// 头指针后移
		free(pdel);
		pdel = psl->_head;
	}
	psl->_size = 0;
}

void PrintSingleList(SingleListPtr psl) {
	assert(psl);
	NodePtr pcur = psl->_head;
	while (pcur) {	// 不为空
		printf("%d ", pcur->_data);	// 打印数据
		pcur = pcur->_next;			// 向后移
	}
	printf("\n");
}

#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>

typedef int SLDataType;

// ˳���
typedef struct SeqList
{
	//SLDataType data[1024];	// ��̬˳���
	SLDataType *_data;		// ��̬˳���
	size_t _size;			// ��ЧԪ�ظ���
	size_t _cap;			// ����
} SeqList, *SeqListPtr;

// ��slp��ʼ��Ϊ������СΪcap��˳���
void InitSeqList(SeqListPtr slp, size_t cap);

// ����˳���
void DestroySeqList(SeqListPtr slp);

// �ı�˳��������
void ReCapSeqList(SeqListPtr slp, size_t cap);

// ��posλ�ò���data
void InsertSeqList(SeqListPtr slp, size_t pos, SLDataType data);

// ɾ��posλ�õ�Ԫ��
void EraseSeqList(SeqListPtr slp, size_t pos);

// ��ӡ˳����Ԫ��
void PrintSeqList(SeqListPtr slp);

// ��˳����β����������
void PushBackSeqList(SeqListPtr slp, SLDataType data);

// ɾ��˳���β������
void PopBackSeqList(SeqListPtr slp);

// ��˳�����ײ���������
void PushFrontSeqList(SeqListPtr slp, SLDataType data);

// ɾ��˳����ײ�������
void PopFrontSeqList(SeqListPtr slp);

// ��˳����в���data,�ҵ�����data���±�,���򷵻�-1
int SearchSeqList(SeqListPtr slp, SLDataType data);

// ˳����Ƿ�Ϊ��
int EmptySeqList(SeqListPtr slp);

// ��ЧԪ�صĸ���
int SizeSeqList(SeqListPtr slp);

// ������С
int CapSeqList(SeqListPtr slp);

// ���˳������������
void ClearSeqList(SeqListPtr slp);

// ɾ��˳����е�һ��ֵΪdata��Ԫ��
void RemoveSeqList(SeqListPtr slp, SLDataType data);

// ��˳������ð������
void BubbleSortSeqList(SeqListPtr slp);

// ��˳�����ж��ֲ���
int BinarySearchSeqList(SeqListPtr slp, SLDataType data);

// �Ƴ�˳�����������data��ȵ�����
void RemoveAllSeqList(SeqListPtr slp, SLDataType data);
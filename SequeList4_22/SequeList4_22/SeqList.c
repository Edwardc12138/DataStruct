#include "SeqList.h"
#include <assert.h>
#include <malloc.h>
#include <errno.h>
#include <string.h>

void InitSeqList(SeqListPtr slp, size_t cap)
{
	assert(slp);	// slp�Ƿ����
	slp->_data = (SLDataType *)malloc(cap * sizeof(SLDataType));	// ��ʼ���洢�ռ�
	if (slp->_data == NULL)		// ����Ƿ�����ɹ�
	{
		perror(strerror(errno));
		return;
	}
	slp->_size = 0;
	slp->_cap = cap;
}

void DestroySeqList(SeqListPtr slp)
{
	assert(slp);
	if (slp->_data != NULL)
	{
		free(slp->_data);	// �ͷ��ڴ�
		slp->_data = NULL;	// ָ���ÿ�
		slp->_size = 0;		// ��ЧԪ������
		slp->_cap = 0;		// ��������
	}
}

void ReCapSeqList(SeqListPtr slp, size_t cap)
{
	assert(slp);
	if (cap <= slp->_size)	// �޸�����С����Ч����
	{
		return;
	}
	SLDataType *newdata = (SLDataType *)malloc(cap * sizeof(SLDataType));	// ���¿����ڴ�
	if (newdata == NULL)
	{
		perror(strerror(errno));
		return;
	}
	for (size_t i = 0; i < slp->_size; ++i)	// ����Ԫ��
	{
		newdata[i] = slp->_data[i];
	}
	free(slp->_data);	// �ͷžɴ洢�ռ�
	slp->_data = newdata;	// ָ���µĴ洢�ռ�
	slp->_cap = cap;	// �µ�����
}

void InsertSeqList(SeqListPtr slp, size_t pos, SLDataType data)
{
	assert(slp);
	if (pos > slp->_size)	// posλ�úϷ��Լ��
	{
		return;
	}
	if (slp->_size == slp->_cap)	// �洢�ռ�����
	{
		ReCapSeqList(slp, 2 * slp->_cap);
	}
	for (size_t i = slp->_size; i > pos; --i)	// ��pos֮���Ԫ������ƶ�
	{
		slp->_data[i] = slp->_data[i - 1];
	}
	slp->_data[pos] = data;	// ��data����posλ��
	++slp->_size;
}

void EraseSeqList(SeqListPtr slp, size_t pos)
{
	assert(slp);
	if (pos >= slp->_size)	// posλ�úϷ��Լ��
	{
		return;
	}
	for (size_t i = pos; i < slp->_size - 1; ++i)	// ��pos֮���Ԫ����ǰ��
	{
		slp->_data[i] = slp->_data[i + 1];
	}
	--slp->_size;
}

void PrintSeqList(SeqListPtr slp)
{
	assert(slp);
	for (size_t i = 0; i < slp->_size; ++i)
	{
		printf("%d ", slp->_data[i]);
	}
	printf("\n");
}

void PushBackSeqList(SeqListPtr slp, SLDataType data)
{
	assert(slp);
	InsertSeqList(slp, slp->_size, data);
}

void PopBackSeqList(SeqListPtr slp)
{
	assert(slp);
	EraseSeqList(slp, slp->_size - 1);
}

void PushFrontSeqList(SeqListPtr slp, SLDataType data)
{
	assert(slp);
	InsertSeqList(slp, 0, data);
}

void PopFrontSeqList(SeqListPtr slp)
{
	assert(slp);
	EraseSeqList(slp, 0);
}

int SearchSeqList(SeqListPtr slp, SLDataType data)
{
	assert(slp);
	for (size_t i = 0; i < slp->_size; ++i)	// ������������
	{
		if (slp->_data[i] == data)	// ������ҵ�������ͬ
		{
			return i;
		}
	}
	return -1;
}

int EmptySeqList(SeqListPtr slp)
{
	assert(slp);
	if (slp->_size == 0)	// û����ЧԪ��
	{
		return 1;
	}
	return 0;
}

int SizeSeqList(SeqListPtr slp)
{
	assert(slp);
	return slp->_size;
}

int CapSeqList(SeqListPtr slp)
{
	assert(slp);
	return slp->_cap;
}

void ClearSeqList(SeqListPtr slp)
{
	assert(slp);
	slp->_size = 0;
}

void RemoveSeqList(SeqListPtr slp, SLDataType data)
{
	assert(slp);
	// ���ҵ��±�,��ɾ��
	EraseSeqList(slp, SearchSeqList(slp, data));
}

void BubbleSortSeqList(SeqListPtr slp)
{
	assert(slp);
	for (int end = slp->_size; end > 1; --end)	// ð������
	{
		int flag = 0;	// �Ƿ��Ѿ�����
		for (int i = 1; i < end; ++i)
		{
			// ǰһ�����ݱȺ�һ�����ݴ��򽻻�
			if (slp->_data[i - 1] > slp->_data[i])
			{
				SLDataType tmp = slp->_data[i];
				slp->_data[i] = slp->_data[i - 1];
				slp->_data[i - 1] = tmp;
				flag = 1;
			}
		}
		if (!flag)	// ����Ѿ�����
		{
			return;
		}
	}
}

int BinarySearchSeqList(SeqListPtr slp, SLDataType data)
{
	assert(slp);
	int left = 0;
	int right = slp->_size;
	while (left < right)
	{
		int mid = left + (right - left) / 2;	// ������λ�õ��м�
		if (data == slp->_data[mid])	// ��ȱ㷵���±�
		{
			return mid;
		}
		else if (data < slp->_data[mid])	// dataС���м��Ԫ��
		{
			right = mid;	// �����Ҳ������м�
		}
		else		// data�����м��Ԫ��
		{
			left = mid + 1;	// ������������м�
		}
	}
	return -1;
}

void RemoveAllSeqList(SeqListPtr slp, SLDataType data)
{
	assert(slp);
	for (int i = 0; i < slp->_size; ++i)	// ����˳���
	{
		if (slp->_data[i] == data)	// �ҵ���data���Ԫ�ص�λ��
		{
			EraseSeqList(slp, i);	//ɾ����λ��
			--i;	// ɾ����Ԫ����ǰ�ƶ�
		}
	}
}

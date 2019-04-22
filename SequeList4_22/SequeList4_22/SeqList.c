#include "SeqList.h"
#include <assert.h>
#include <malloc.h>
#include <errno.h>
#include <string.h>

void InitSeqList(SeqListPtr slp, size_t cap)
{
	assert(slp);	// slp是否存在
	slp->_data = (SLDataType *)malloc(cap * sizeof(SLDataType));	// 初始化存储空间
	if (slp->_data == NULL)		// 检查是否申请成功
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
		free(slp->_data);	// 释放内存
		slp->_data = NULL;	// 指针置空
		slp->_size = 0;		// 有效元素清零
		slp->_cap = 0;		// 容量清零
	}
}

void ReCapSeqList(SeqListPtr slp, size_t cap)
{
	assert(slp);
	if (cap <= slp->_size)	// 修改容量小于有效数据
	{
		return;
	}
	SLDataType *newdata = (SLDataType *)malloc(cap * sizeof(SLDataType));	// 重新开辟内存
	if (newdata == NULL)
	{
		perror(strerror(errno));
		return;
	}
	for (size_t i = 0; i < slp->_size; ++i)	// 拷贝元素
	{
		newdata[i] = slp->_data[i];
	}
	free(slp->_data);	// 释放旧存储空间
	slp->_data = newdata;	// 指向新的存储空间
	slp->_cap = cap;	// 新的容量
}

void InsertSeqList(SeqListPtr slp, size_t pos, SLDataType data)
{
	assert(slp);
	if (pos > slp->_size)	// pos位置合法性检测
	{
		return;
	}
	if (slp->_size == slp->_cap)	// 存储空间已满
	{
		ReCapSeqList(slp, 2 * slp->_cap);
	}
	for (size_t i = slp->_size; i > pos; --i)	// 将pos之后的元素向后移动
	{
		slp->_data[i] = slp->_data[i - 1];
	}
	slp->_data[pos] = data;	// 将data赋给pos位置
	++slp->_size;
}

void EraseSeqList(SeqListPtr slp, size_t pos)
{
	assert(slp);
	if (pos >= slp->_size)	// pos位置合法性检测
	{
		return;
	}
	for (size_t i = pos; i < slp->_size - 1; ++i)	// 将pos之后的元素向前移
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
	for (size_t i = 0; i < slp->_size; ++i)	// 遍历所有数据
	{
		if (slp->_data[i] == data)	// 与待查找的数据相同
		{
			return i;
		}
	}
	return -1;
}

int EmptySeqList(SeqListPtr slp)
{
	assert(slp);
	if (slp->_size == 0)	// 没有有效元素
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
	// 先找到下标,再删除
	EraseSeqList(slp, SearchSeqList(slp, data));
}

void BubbleSortSeqList(SeqListPtr slp)
{
	assert(slp);
	for (int end = slp->_size; end > 1; --end)	// 冒泡排序
	{
		int flag = 0;	// 是否已经有序
		for (int i = 1; i < end; ++i)
		{
			// 前一个数据比后一个数据大则交换
			if (slp->_data[i - 1] > slp->_data[i])
			{
				SLDataType tmp = slp->_data[i];
				slp->_data[i] = slp->_data[i - 1];
				slp->_data[i - 1] = tmp;
				flag = 1;
			}
		}
		if (!flag)	// 如果已经有序
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
		int mid = left + (right - left) / 2;	// 带查找位置的中间
		if (data == slp->_data[mid])	// 相等便返回下标
		{
			return mid;
		}
		else if (data < slp->_data[mid])	// data小于中间的元素
		{
			right = mid;	// 区间右侧移向中间
		}
		else		// data大于中间的元素
		{
			left = mid + 1;	// 区间左侧移向中间
		}
	}
	return -1;
}

void RemoveAllSeqList(SeqListPtr slp, SLDataType data)
{
	assert(slp);
	for (int i = 0; i < slp->_size; ++i)	// 遍历顺序表
	{
		if (slp->_data[i] == data)	// 找到与data相等元素的位置
		{
			EraseSeqList(slp, i);	//删除该位置
			--i;	// 删除后元素向前移动
		}
	}
}

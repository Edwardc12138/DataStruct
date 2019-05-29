#include "Sort.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>

int More(SortDataType left, SortDataType right) {
    if(left > right) {
        return 1;
    }

    return 0;
}

int Less(SortDataType left, SortDataType right) {
    if(left < right) {
        return 1;
    }

    return 0;
}

void InsertSort(SortDataType* arr, int size, Type tp) {
    if(!arr) {
        return;
    }
    // 待排序值
    int i;
    for(i = 1; i < size; ++i) {
        SortDataType tmp = arr[i];
        // 前一个比当前值大/小,向后移
        int j;
        for(j = i; j > 0 && tp(arr[j - 1], tmp); --j) {
            arr[j] = arr[j - 1];
        }
        if(i != j) {
            arr[j] = tmp;
        }
    }
}

void ShellSort(SortDataType* arr, int size, Type tp) {
    if(!arr) {
        return;
    }

    int flag = 1;
    int d = size;
    while(flag) {
        d = d / 3 + 1;
        if(d == 1) {
            flag = 0;
        }
        // 分组排序
        int i;
        for(i = d; i < size; ++i) {
            SortDataType tmp = arr[i];
            int j;
            for(j = i; (j - d) >= 0 && tp(arr[j - d], tmp); j -= d) {
                arr[j] = arr[j - d];
            }
            if(i != j) {
                arr[j] = tmp;
            }
        }
    }
}

// 交换
void _Swap(SortDataType* left, SortDataType* right) {
    SortDataType tmp = *left;
    *left = *right;
    *right = tmp;
}

void SlectSort(SortDataType* arr, int size, Type tp) {
    if(!arr) {
        return;
    }

    // 外层循环控制次数
    int i;
    for(i = size -1; i > 0; --i) {
        int tmp = 0;
        // 内层循环找寻最大/小的值
        int j;
        for(j = 1; j <= i; ++j) {
            if(tp(arr[j], arr[tmp])) {
                tmp = j;
            }
        }
        // 最大值不是i下标的数本身,则交换
        if(i != tmp) {
            _Swap(arr + i, arr + tmp);
        }
    }
}

// 向下调整
void _AdjustDown(SortDataType* arr, int size, int father, Type tp) {
    if(!arr) {
        return;
    }
    // 左子节点
    int child = father * 2 + 1;
    while(child < size) {
        // 找大的/小的子节点
        if((child + 1) < size && tp(arr[child + 1], arr[child])) {
            ++child;    // 切换到右子节点
        }
        // 调整父节点
        if(tp(arr[child], arr[father])) {
            _Swap(arr + child, arr + father);
            // 向下继续
            father = child;
            child = father * 2 + 1;
        }
        else {
            break;
        }
    }
}

void HeapSort(SortDataType* arr, int size, Type tp) {
    if(!arr) {
        return;
    }

    // 利用堆的思想,不建立堆
    int root = (size - 2) / 2;  // 最后一个不是叶节点的节点
    // 从后向前调整每个节点
    for(; root >= 0; --root) {
        _AdjustDown(arr, size, root, tp);
    }
    // 交换堆顶元素和未排序的最后一个元素
    int i;
    for(i = size - 1; i > 0; --i) {
        _Swap(arr + 0, arr + i);
        // 之后只用调整堆顶元素
        _AdjustDown(arr, i, 0, tp);
    }
}

void BubbleSort(SortDataType* arr, int size, Type tp) {
    if(!arr) {
        return;
    }
    // 外层控制循环次数
    int i;
    for(i = size; i > 0; --i) {
        int j;
        int flag = 1;   // 如果序列已经有序,便不再排序
        for(j = 1; j < i; ++j) {
            if(tp(arr[j - 1], arr[j])) {
                _Swap(&arr[j - 1], &arr[j]);
                if(flag) {
                    flag = 0;   // 只要有交换,序列便还未有序
                }
            }
        }
        if(flag) {
            break;
        }
    }
}

// 获取分割值
int Getmidvlaue(SortDataType* arr, int val1, int val2, int val3) {
    if(arr[val1] <= arr[val2]) {
        if(arr[val2] <= arr[val3]) {
            return val2;
        }
        else if(arr[val1] <= arr[val3]) {
            return val3;
        }
        return val1;
    }
    else {
        if(arr[val1] <= arr[val3]) {
            return val1;
        }
        else if(arr[val2] <= arr[val3]) {
            return val3;
        }
        return val2;
    }
}

// 分割同一位置开始
int _Partion(SortDataType* arr, int left, int right, Type tp) {
    if(!arr) {
        return -1;
    }
    // mid用来记录小于基准值的最后一个位置
    int mid = left + (left - right) / 2;
    mid = Getmidvlaue(arr, left, mid, right - 1);
    // mid位置不再头,将其换到头处
    if(mid != left) {
        _Swap(&arr[left], &arr[mid]);
        mid = left;
    }
    // 分割数据
    int cur;
    for(cur = left + 1; cur < right; ++cur) {
        // 当前值小于等于/大于等于基准值,并且当前位置不是大于/小于基准值的起一个位置
        if(tp(arr[left], arr[cur]) && ++mid < cur) {
            _Swap(&arr[mid], &arr[cur]);
        }
    }
    // 交换基准位置和小于/大于基准值的第一个位置
    if(mid != left) {
        _Swap(&arr[left], &arr[mid]);
    }
    return mid;
}

// 分割2两头同时
int _Partion2(SortDataType* arr, int left, int right, Type tp) {
    if(!arr) {
        return -1;
    }

    int mid = left + (right - left) / 2;
    mid = Getmidvlaue(arr, left, mid, right - 1);
    if(mid != (right - 1)) {
        _Swap(&arr[right - 1], &arr[mid]);
        mid = right - 1;
    }
    int begin = left;
    int end = right - 1;
    while (begin < end) {
        // begin找大于/小于基准值的下标
        while(begin < end && tp(arr[mid], arr[begin])) {
            ++begin;
        }
        // end找小于/大于基准值的小标
        while(begin < end && tp(arr[end], arr[mid])) {
            --end;
        }
        if(begin != end) {
            _Swap(&arr[begin], &arr[end]);
        }
    }
    if(mid != begin) {
        _Swap(&arr[begin - 1], &arr[mid]);
    }
    return begin;
}

// 分割3挖坑
int _Partion3(SortDataType* arr, int left, int right, Type tp) {
    if(!arr) {
        return -1;
    }

    int mid = left + (right - left) / 2;
    mid = Getmidvlaue(arr, left, mid, right);
    if(mid != (right - 1)) {
        _Swap(&arr[mid], &arr[right - 1]);
        mid = right - 1;
    }
    SortDataType tmp = arr[mid];
    int begin = left;
    int end = right - 1;
    while(begin < end) {
        // begin找大于/小于基准值的下标
        while(begin < end && tp(tmp , arr[begin])){
            ++begin;
        }
        if(begin < end) {
            arr[end--] = arr[begin];
        }
        // end找小于/大于基准值的下标
        while(begin < end && tp(arr[end], tmp)) {
            --end;
        }
        if(begin < end) {
            arr[begin++] = arr[end];
        }
    }
    if(begin != mid) {
        arr[begin] = tmp;
    }
    return begin;
}

// 快排
void _QuickSort(SortDataType* arr, int left, int right, Type tp) {
    if(!arr || (right - left) <= 1) {
        return;
    }

    // 分割
    //int mid = _Partion(arr, left, right, tp);
    //int mid = _Partion2(arr, left, right, tp);
    int mid = _Partion3(arr, left, right, tp);
    // 对左半部分排序
    _QuickSort(arr,left, mid, tp);
    // 对右半部分排序
    _QuickSort(arr, mid + 1, right, tp);
}

void QuickSort(SortDataType* arr, int size, Type tp) {
    if(!arr) {
        return;
    }
    _QuickSort(arr, 0, size, tp);
}

// 合并数组
void _Merge(SortDataType* arr, int left, int mid, int right, Type tp) {
    if(!arr) {
        return;
    }
    int size = (right - left) * sizeof(SortDataType);
    SortDataType* tmp = (SortDataType*)malloc(size);
    if(!tmp) {
        assert(0);
    }
    int cur1 = left;    // 左半部分
    int cur2 = mid;     // 右半部分
    int i;  // 临时空间的下标
    for(i = 0; cur1 < mid && cur2 < right; ++i) {
        if(tp(arr[cur1], arr[cur2])) {
            tmp[i] = arr[cur2++];
        }
        else {
            tmp[i] = arr[cur1++];
        }
    }
    // 左半部分为结束,拷贝左半部分
    if(cur1 != mid) {
        memcpy(&tmp[i], &arr[cur1], (mid - cur1) * sizeof(SortDataType));;
    }
    // 右半部分未结束,拷贝右半部分
    if(cur2 != right) {
        memcpy(&tmp[i], &arr[cur2], (right - cur2) * sizeof(SortDataType));;
    }
    // 将数据拷回原数组
    memcpy(&arr[left], tmp, size);
    free(tmp);
}

// 归并递归
void _MergeSort(SortDataType* arr, int left, int right, Type tp) {
    if(!arr || (right - left) <= 1) {
        return;
    }
    // 分割
    int mid = left + (right - left) / 2;
    // 归并左半部分
    _MergeSort(arr, left, mid, tp);
    // 归并右半部分
    _MergeSort(arr, mid, right, tp);
    // 合并
    _Merge(arr, left, mid, right, tp);
}

// 归并
void MergeSort(SortDataType* arr, int size, Type tp) {
    if(!arr) {
        return;
    }
    // 递归方法
    //_MergeSort(arr, 0, size, tp);
    // 迭代方法
    int i;
    for(i = 1; i < size; i *= 2) {
        int left;
        int mid;
        int right;
        for(left = 0, mid = i, right = 2 * i; mid < size; left += 2 * i, mid += 2 * i, right += 2 * i) {
            if(right > size) {
                right = size;
            }
            _Merge(arr, left, mid, right, tp);
        }
    }
}

void SortTest(SortType st) {
    srand((unsigned)time(NULL));
    SortDataType arr[20];
    int i;
    for(i = 0; i < 20; ++i) {
        arr[i] = rand() % 100;
    }
    printf("原序列: ");
    for(i = 0; i < 20; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    st(arr, 20, More);
    printf("排序后: ");
    for(i = 0; i < 20; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


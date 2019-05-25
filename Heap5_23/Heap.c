#include "Heap.h"
#include <assert.h>
#include <malloc.h>

int More(HeapDataType x, HeapDataType y) {
    if(x > y) {
        return 1;
    }
    return 0;
}

int Less(HeapDataType x, HeapDataType y) {
    if(x < y) {
        return 1;
    }
    return 0;
}

// 交换
void _Swap(HeapDataType* left, HeapDataType* right) {
    assert(left);
    assert(right);

    HeapDataType tmp = *left;
    *left = *right;
    *right = tmp;
}

// 堆向下调整为大/小堆
void _AdjustDown(Heap* ph, int father) {
    assert(ph);

    HeapDataType* arr = ph->_data;
    int child = father * 2 + 1; // 左子节点
    //if(child < ph->_size) {
    //    // 父节点的右子节点存在,且大于/小于左子节点
    //    if((child + 1) < ph->_size && ph->_ht(arr[child + 1], arr[child])) {
    //        ++child;    // 换到右子节点
    //    }
    //    // 子节点比父节点大/小
    //    if(ph->_ht(arr[child], arr[father])) {
    //        _Swap(arr + child, arr + father);   // 父节点向下调整
    //        // 调整交换后的子树
    //       _AdjustDown(ph, child);
    //    }
    //    // 父节点比子节点大/小,调正完成
    //}
    
    while(child < ph->_size) { 
        // 父节点的右子节点存在,且大于/小于左子节点
        if((child + 1) < ph->_size && ph->_ht(arr[child + 1], arr[child])) {
            ++child;    // 换到右子节点
        }
        // 子节点比父节点大/小
        if(ph->_ht(arr[child], arr[father])) {
            _Swap(arr + child, arr + father);   // 父节点向下调整
            father = child;
            child = father * 2 + 1;
        }
        // 父节点比子节点大/小,调正完成
        else {
            break;
        }
    }
}

void InitHeap(Heap* ph, HeapDataType* data, int n, HeapType ht) {
    assert(ph);

    if(!ht) {   // 防止ht为null,默认为大堆
        ht = More;
    }
    ph->_ht = ht;
    if(data) {
        ph->_data = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
        if(!ph->_data) {
            printf("初始化失败\n");
            return;
        }
        // 拷贝数据
        int i;
        for(i = 0; i < n; ++i) {
            ph->_data[i] = data[i];
        }
        ph->_cap = n;
        ph->_size = n;
        // 从最后一个不为叶节点的节点开始向下调整为大/小堆
        // 找到最后一个不为叶节点的节点
        int begin = (n - 2)/2;
        // 循环从后向前向下调整节点
        for(i = begin; i >= 0; --i) {
            _AdjustDown(ph, i);
        }
    }
    else {
        if(!n) {    // 防止n = 0;
            n = 1;
        }
        ph->_data = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
        if(!ph->_data) {
            printf("初始化失败\n");
            return;
        }
        ph->_cap = n;
        ph->_size = 0;
    }
}

void InitEmptyHeap(Heap* ph, HeapType ht) {
    assert(ph);

    InitHeap(ph, NULL, 0, ht);
}

void DetroyHeap(Heap* ph) {
    assert(ph);

    if(ph->_data) {
        free(ph->_data);
    }
    ph->_cap = 0;
    ph->_size = 0;
    ph->_ht = NULL;
}

void PrintHeap(Heap* ph) {
    assert(ph);

    int i;
    for(i = 0; i < ph->_size; ++i) {
        printf("%d ", ph->_data[i]);
    }
    printf("\n");
}

// 堆扩容,成功返回扩容后的容量,失败返回-1
int  _Resize(Heap* ph) {
    assert(ph);

    int newcap = ph->_cap * 2;
    HeapDataType* newdata = (HeapDataType*)malloc(sizeof(HeapDataType) * newcap);
    if(!newdata) {
        return -1;
    }
    // 搬移数据
    int i;
    for(i = 0; i < ph->_size; ++i) {
        newdata[i] = ph->_data[i];
    }
    free(ph->_data);
    ph->_data = newdata;
    ph->_cap = newcap;
    return newcap;
}

// 向上调整
void _AdjustUp(Heap* ph, int child) {
    assert(ph);

    HeapDataType* arr = ph->_data;
    int father = (child - 1) / 2;
    // 父节点存在,子节点大于/小于父节点
    //if(father >= 0 && ph->_ht(arr[child], arr[father])) {
    //    _Swap(arr + child, arr + father);   // 交换
    //    _AdjustUp(ph, father);  // 调整交换后的父节点
    //}
    
    while(father >= 0 && ph->_ht(arr[child], arr[father])) {
        _Swap(arr + child, arr + father);
        child = father;
        father = (child - 1) / 2;
    }
}

void InsertHeap(Heap* ph, HeapDataType data) {
    assert(ph);

    if(ph->_size == ph->_cap) {
        if( _Resize(ph) < 0) {
            printf("扩容失败");
            return;
        }
    }

    ph->_data[ph->_size++] = data;
    // 向上调整为大/小堆
    _AdjustUp(ph, ph->_size -1);
}

void RemoveHeap(Heap* ph) {
    assert(ph);

    --ph->_size;
    //交换堆顶数据与最后一个数据 
    _Swap(ph->_data + 0, ph->_data + ph->_size);
    // 向下调整堆顶数据
    _AdjustDown(ph, 0);
}

int SizeHeap(Heap* ph) {
    assert(ph);

    return ph->_size;
}

int EmptyHeap(Heap* ph) {
    assert(ph);

    return ph->_size == 0;
}

HeapDataType TopHeap(Heap* ph) {
    assert(ph);

    return ph->_data[0];
}

void HeapSort(HeapDataType* arr, int n, HeapType ht) {
    if(!arr) {
        return;
    }

    // 新建堆;
    Heap heap;
    heap._data = arr;
    heap._size = n;
    heap._cap = n;
    heap._ht = ht;
    
    // 从最后一个不为叶节点的节点开始向下调整为大/小堆
    // 找到最后一个不为叶节点的节点
    int begin = (n - 2)/2;
    // 循环从后向前向下调整节点
    for(; begin >= 0; --begin) {
        _AdjustDown(&heap, begin);
    }

    while(--heap._size) {
        // 交换堆顶和最后一个数据
        _Swap(arr + 0, arr + heap._size);
        // 向下调整堆
        _AdjustDown(&heap, 0);
    }
    heap._data = NULL;
    DetroyHeap(&heap);
}

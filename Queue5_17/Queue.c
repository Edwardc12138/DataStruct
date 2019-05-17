#include "Queue.h"
#include <assert.h>
#include <malloc.h>

void InitQueue(Queue *queue) {
    assert(queue);

    queue->_Head = NULL;    // 队头置空
    queue->_tail = NULL;    // 队尾置空
    queue->_size = 0;   // 对列元素为0
}

// 新建节点
QNode* _NewNode(QDataType data) {
    QNode *node = (QNode*)malloc(sizeof(QNode));
    if(!node) {
        assert(node);
    }
    node->_data = data; // 保存数据
    node->_next = NULL; // 指针置空
    return node;
}

void PushQueue(Queue *queue, QDataType data) {
    assert(queue);

    QNode *node = _NewNode(data);   // 新建节点
    if(queue->_Head) { // 非空链表
        queue->_tail->_next = node; // 插到队尾
        queue->_tail = node;    // 队尾指针后移
    }
    else {  // 空链表
        queue->_Head = queue->_tail = node;
    }
    ++queue->_size; // 队列元素个数增加
}

void PopQueue(Queue *queue) {
    assert(queue);

    QNode *pcur = queue->_Head;
    if(pcur) { // 非空
        queue->_Head = pcur->_next; // 队头指针后移
        free(pcur); // 销毁节点
        --queue->_size; // 队列元素减少
    }
}

void PrintQueue(Queue *queue) {
    assert(queue);

    QNode *pcur = queue->_Head;
    while(pcur) {  // 节点不为空
        printf("%d->", pcur->_data);
        pcur = pcur->_next; // 节点后移
    }
    printf("NULL\n");
}

void ClearQueue(Queue *queue) {
    assert(queue);

    if(!queue->_Head) { // 空链表
        return;
    }

    QNode *pcur = queue->_Head;
    while(pcur) {   // 节点不为空
        queue->_Head = pcur->_next; // 队头指针后移
        free(pcur);
        pcur = queue->_Head;
    }
    queue->_tail = NULL;    // 队尾指针置空
    queue->_size = 0;   // 元素个数清零
}

QDataType HeadOfQueue(Queue *queue) {
    assert(queue);

    if(queue->_Head) {  // 非空
        return queue->_Head->_data;
    }
    return -1;  // 空
}

QDataType TailOfQueue(Queue *queue) {
    assert(queue);

    if(queue->_tail) {   // 非空
        return queue->_tail->_data;
    }
    return -1;  // 空
}

int SizeOfQueue(Queue *queue) {
    assert(queue);

    return queue->_size;
}

int EmptyQueue(Queue *queue) {
    assert(queue);

    return queue->_size == 0;
}

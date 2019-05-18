#pragma once

typedef int QDataType;

typedef struct QNode {
    QDataType _data;    // 存储数据
    struct QNode *_next;// 下一节点
} QNode;

typedef struct Queue {
    QNode *_Head;    // 队头
    QNode *_tail;    // 队尾
    int _size;      // 队列元素个数
} Queue;

// 初始化
void InitQueue(Queue *queue);

// 入队
void PushQueue(Queue *queue, QDataType data);

// 出队
void PopQueue(Queue *queue);

// 打印对列元素
void PrintQueue(Queue *queue);

// 清空队列
void ClearQueue(Queue *queue);

// 队头元素
QDataType HeadOfQueue(Queue *queue);

// 队尾元素
QDataType TailOfQueue(Queue *queue);

// 队列长度
int SizeOfQueue(Queue *queue);

// 判空
int EmptyQueue(Queue *queue);

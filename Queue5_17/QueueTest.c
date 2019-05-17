#include <stdio.h>
#include "Queue.h"

int main() {
    Queue q;
    InitQueue(&q);

    PushQueue(&q, 2);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PushQueue(&q, 5);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PushQueue(&q, 6);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PushQueue(&q, 1);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PushQueue(&q, 3);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PrintQueue(&q);

    PopQueue(&q);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PrintQueue(&q);
    PopQueue(&q);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PrintQueue(&q);
    PopQueue(&q);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PrintQueue(&q);
    PopQueue(&q);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PrintQueue(&q);
    PopQueue(&q);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PrintQueue(&q);
    PopQueue(&q);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PrintQueue(&q);
    PopQueue(&q);
    if(q._Head) {
        printf("队头:%d\n", q._Head->_data);
        printf("队尾:%d\n", q._tail->_data);
    }
    printf("队列长度:%d\n", q._size);

    PrintQueue(&q);
    return 0;
}

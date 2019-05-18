#include "Stack.h"
#include <assert.h>
#include <malloc.h>

void InitStack(Stack *stack) {
    assert(stack);
    // 初始只能容纳一个元素
    stack->_data = 
        (StackDataType*)malloc(sizeof(StackDataType));
    if(!stack->_data) {    // malloc失败
        assert(stack->_data);
    }
    stack->_top = -1;    // 栈顶元素下标
    stack->_capacity = 1;
    stack->_size = 0;
}


void DestoryStack(Stack *stack) {
    assert(stack);

    free(stack->_data);     // 释放空间
    stack->_data = NULL;    // 指针置空
    stack->_top = -1;
    stack->_capacity = 0;
    stack->_size = 0;
}

// 重新分配空间
void _Resize(Stack *stack) {
    assert(stack);
    // 将空间变为原来的两倍
    StackDataType *data =
        (StackDataType*)malloc(sizeof(StackDataType) * stack->_capacity * 2);
    if(!data) {
        assert(data);
    }

    // 移动元素
    int i;
    for(i = 0; i < stack->_size; ++i) {
        data[i] = stack->_data[i];
    }

    // 释放原有空间
    free(stack->_data);
    
    stack->_data = data;
    stack->_capacity *= 2;
}

void PushStack(Stack *stack, StackDataType data) {
    assert(stack);

    // 栈满,重新申请空间
    if(stack->_capacity == stack->_size) {
        _Resize(stack);
    }
    stack->_data[stack->_size++] = data;
    stack->_top++;
}


StackDataType PopStack(Stack *stack) {
    assert(stack);

    StackDataType ret = -1;
    if(stack->_top >= 0) {  // 栈中有元素
        ret = stack->_data[stack->_top--];
        --stack->_size; 
    }
    return ret;
}


int EmptyStack(Stack *stack) {
    assert(stack);

    return stack->_size == 0;
}


int SizeStack(Stack *stack) {
    assert(stack);

    return stack->_size;
}


StackDataType TopStack(Stack *stack) {
    assert(stack);

    if(stack->_top >= 0) {  // 栈不为空
        return stack->_data[stack->_top];
    }
    return -1;
}


void ClearStack(Stack *stack) {
    assert(stack);

    if(stack->_size) {  // 栈不为空
        stack->_top = -1;
        stack->_size = 0;
    }
}

